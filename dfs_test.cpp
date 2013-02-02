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

void dfs_recursive( vector < vector <int> >& adj_list, int v, vector <int>& pred, vector <int>& visited)
{
	REP(i, adj_list[v].size())
	{
		int neighbor = adj_list[v][i];
		if (visited[neighbor] == 0)
		{
			visited[neighbor] = 1;
			pred[neighbor] = v;
			dfs_recursive(adj_list, neighbor, pred, visited);
		}	
	}

}

void dfs_iter(int source, vector < vector <int> >&adj_list, vector <int>& pred, int n)
{
	vector <int> visited(n);
	visited[source] = 1;
		
	stack <int> stk;
	stk.push(source);
	while (!stk.empty())
	{
		int v = stk.top();
		stk.pop();

		REP(i, adj_list[v].size())
		{
			int neighbor = adj_list[v][i];
			if (visited[neighbor] == 0)
			{
				visited[neighbor] = 1;
				pred[neighbor] = v;
				stk.push(neighbor);
			}	
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int n = 0;
	cin >> n;
	int e = 0;
	cin >> e;
	vector <int> pred(n);
	vector < vector <int> > adj_list(n);

	REP(i, e)
	{
		int a, b;
		cin >> a >> b;
		
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	vector <int> visited(n);
	int source = 0;
	visited[source] = 1;
	pred[source] = source;

	dfs_recursive(adj_list, source, pred, visited);
	REP(i, n)
	{
		cout << "Predecessor of " << i << " :" << pred[i] << "\n";
	}
	
	dfs_iter(source, adj_list, pred, n);
	REP(i, n)
	{
		cout << "Predecessor of " << i << " :" << pred[i] << "\n";
	}
	
}
