#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <queue>
#include <string>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, FROM, n) for (int i = FROM; i < n; i++)

class config
{
	public:
	int a; int b; int c; int d;
	config(){a = 0; b = 0; c = 0; d = 0;}
	config(int p, int q, int r, int s){a = p; b = q; c = r; d = s;}
};

int id(config conf)
{
	return conf.d + conf.c*10 + conf.b*100 + conf.a*1000;
}

config generate_neighbor(config source, int i)
{
	
		if (i == 0)
		{
			config c((source.a + 1)%10, source.b, source.c, source.d);
			return c;
		}
		else if (i == 1)
		{
			config c(source.a == 0 ? 9 : source.a - 1, source.b, source.c, source.d);
			return c;
		}
		else if (i == 2)
		{
			config c(source.a, (source.b + 1)%10, source.c, source.d);
			return c;
		}
		else if (i == 3)
		{
			config c(source.a, source.b == 0 ? 9 : source.b - 1, source.c, source.d);
			return c;
		}
		else if (i == 4)
		{
			config c(source.a, source.b, (source.c + 1)%10, source.d);
			return c;
		}
		else if (i == 5)
		{
			config c(source.a, source.b, source.c == 0 ? 9 : source.c - 1, source.d);
			return c;
		}
		else if (i == 6)
		{
			config c(source.a, source.b, source.c, (source.d + 1)%10);
			return c;
		}
		else 
		{
			config c(source.a, source.b, source.c, source.d == 0 ? 9 : source.d - 1);
			return c;
		}
}

int bfs(config source, vector <int>& forbidden, config final)
{
	vector <int> visited(10000);
	queue <config> q;
	q.push(source);
	visited[id(source)] = 1;
	vector <int> depth(10000);

	while (!q.empty())
	{
		config c = q.front();
		q.pop();
		
		if (id(c) == id(final))
			return depth[id(c)];
		// cout << "Dequeue " << c.a << c.b << c.c << c.d << "\n";
		// Generate neighbors
		for (int i = 0; i < 8; i++)
		{
			config neighbor = generate_neighbor(c, i);
			int neighbor_id = id(neighbor);
			if (forbidden[neighbor_id] != 1 && visited[neighbor_id] != 1)
			{
				depth[neighbor_id] = depth[id(c)] + 1;
				visited[neighbor_id] = 1;

				q.push(neighbor);
			}
		}
		
	}

	return -1;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int testcases = 0;
	cin >> testcases;
	REP(z, testcases)
	{
		int a = 0; int b = 0; int c = 0; int d = 0;
		cin >> a >> b >> c >> d;
		config init(a, b, c, d);

		cin >> a >> b >> c >> d;
		config final(a, b, c, d);

		int f = 0;
		cin >> f;
		vector <int> forbidden(10000);
		REP(i, f)
		{
			config conf;
			cin >> conf.a >> conf.b >> conf.c >> conf.d;
			forbidden[id(conf)] = 1;
		}

		cout << bfs(init, forbidden, final) << "\n";
	}
}
