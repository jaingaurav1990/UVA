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
#define f first
#define s second

list <int> euler_circuit;

void find_euler_circuit(int u, vector < list <int> >& adj_list)
{
	while (!adj_list[u].empty())
	{
		int v = adj_list[u].back();
		// Delete this edge
		adj_list[u].pop_back();
		list<int>:: iterator it = find(adj_list[v].begin(), adj_list[v].end(), u);
		adj_list[v].erase(it);
		
		find_euler_circuit(v, adj_list);
	}	
	euler_circuit.push_front(u);
}

bool dfs(int source, vector < vector <int> >& adj_list, int colors_num)
{
	vector <int> visited(51);
	visited[source] = 1;
	stack <int> stk;
	stk.push(source);

	while (!stk.empty())
	{
		int v = stk.top();
		stk.pop();
		
		REP(i, adj_list[v].size())
		{
			if (!visited[adj_list[v][i]])
			{
				stk.push(adj_list[v][i]);
				visited[adj_list[v][i]] = 1;
			}
		}
	}

	int sum = 0;
	REP(i, 51)
	{
		sum = sum + visited[i];
	}
	
	if (sum == colors_num)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int testcases;
	cin >> testcases;
	REP(z, testcases)
	{
		int n = 0;
		cin >> n; 

		set <int> colors;
		vector < list <int> > adj_list(51);
		vector < vector <int> > ad_list(51);
		REP(i, n)
		{
			int c1 = 0; int c2 = 0;
			cin >> c1 >> c2;	
			colors.insert(c1);
			colors.insert(c2);

			adj_list[c1].push_back(c2);
			adj_list[c2].push_back(c1);

			ad_list[c1].push_back(c2);
			ad_list[c2].push_back(c1);
		}
		
		cout << "Case #" << z+1 << "\n";
		// Check if euler circuit exists
		// 1. Graph should be connected
		bool possible = true;
		possible = dfs(*colors.begin(), ad_list, colors.size());
		if (!possible)
		{
			cout << "some beads may be lost\n";	
			if (z != testcases - 1)
			{
				cout << "\n";
			}
			continue;
		}
		//2. Every vertex should have an even degree
		set <int>:: iterator sit;
		for (sit = colors.begin(); sit != colors.end(); sit++)
		{
			int color = *sit;
			if (adj_list[color].size() % 2 != 0)
			{
				possible = false;
				break;
			}
		}
		
		if (!possible)
		{
			cout << "some beads may be lost\n";	
			if (z != testcases - 1)
			{
				cout << "\n";
			}
			continue;
		}

		if (possible)
		{
			euler_circuit.clear();
		
			find_euler_circuit(*colors.begin(), adj_list);

			list <int>:: iterator lit = euler_circuit.begin(); 
			int beads = 0;
			while (beads < n)
			{
				cout << *lit << " " ;
				lit++;
				cout << *lit << "\n"; 
				beads++;
			}

			if (z != testcases - 1)
			{
				cout << "\n";			
			}
		}
	}
}
