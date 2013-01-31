#include <iostream>
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

bool color_graph(vector < vector <int> >& adj_list, vector < vector <int> >& matrix, int n, int source)
{
	vector <int> visited(n);
	vector <int> color(n, -1);
	int s = source;
	visited[s] = 1;
	color[s] = 0;
	queue <int> stk;
	stk.push(s);
		
	while (!stk.empty())
	{
		int v = stk.front();
		//cout << "Popped :" << v << "from stack\n";
		stk.pop();
		
		for (size_t i = 0; i < adj_list[v].size(); i++)
		{

			int neighbor = adj_list[v][i];
			//cout << "Inspecting neighbor " << neighbor << " of " << v << "\n";
			if (!visited[adj_list[v][i]])
			{
				
				/*			
				for (size_t j = 0; j < i; j++)
				{
					if (matrix[neighbor][adj_list[v][j]] == 1)
					{
			//			cout << neighbor << "," << adj_list[v][j] << "\n";
						return false;	
					}
				}
				*/
				
				
				
			
				stk.push(adj_list[v][i]);
			//	cout << "Pushing :" << adj_list[v][i] << " on stack\n";
				visited[adj_list[v][i]] = 1;		
				color[neighbor] = (color[v] + 1)%2;
			}
				
			else
			{
				if (color[neighbor] == color[v])
					return false;
			}
			
			
		}			
	}
	return true;
}

int main()
{

	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int n = 0;
	cin >> n;
	while (n != 0)
	{
		int l = 0;
		cin >> l;
		vector < vector <int> > adj_list(n);
		vector < vector <int> > matrix(n, vector <int> (n, 0));
		int source;
		REP(i, l)
		{
			int u; int v;
			cin >> u >> v;
			source = u;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
			matrix[u][v] = 1;
			matrix[v][u] = 1;
		}

		bool ret = color_graph(adj_list, matrix, n, source);
		if (ret)
			cout << "BICOLORABLE.\n";
		else
			cout << "NOT BICOLORABLE.\n";

		cin >> n;
	}
	return 0;
}
