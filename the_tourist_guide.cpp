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

void dfs_recursive(int v, vector < vector <int> >& adj_list, vector <int>& visited, vector <int>& depth, vector <int>& low, vector <int>& pred, vector <int>& child_count)
{
	REP(i, adj_list[v].size())
	{
		int child = adj_list[v][i];
		if (visited[child] == 0) // Tree edge
		{
			depth[child] = depth[v] + 1;	
			low[child] = depth[child];
			visited[child] = 1;
			child_count[v]++;
			pred[child] = v;
			dfs_recursive(child, adj_list, visited, depth, low, pred, child_count);
			low[v] = min(low[v], low[child]);
		}
		else
		{
			// Found a back edge. 
			low[v] = min(low[v], depth[child]);
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int N = 0;
	cin >> N;
	int map_number = 0;
	while (N != 0)	
	{
		map_number++;
		map <int, string> cities;
		map <string, int> rev_map;
		REP(i, N)
		{
			string s;
			cin >> s;
			cities[i] = s;	
			rev_map[s] = i;
		}

		int edges;
		cin >> edges;

		vector < vector <int> > adj_list(N);
		REP(i, edges)
		{
			string s1, s2;
			cin >> s1 >> s2;

			int c1 = rev_map[s1];
			int c2 = rev_map[s2];

			adj_list[c1].push_back(c2);
			adj_list[c2].push_back(c1);
		}

		int source = 0;
		vector <string> articulation_point;
		vector <int> already_covered(N);
		vector < vector <int> > children(N);
		vector <int> art_point_checked(N, -1);
		bool vertices_left;

		vector <int> visited(N);
		vector <int> depth(N);
		vector <int> child_count(N);
		vector <int> low(N);
		vector <int> pred(N, -1);
	
		do
		{
			visited[source] = 1;
			pred[source] = source;
			dfs_recursive(source, adj_list, visited, depth, low, pred, child_count);

			if (child_count[source] > 1)
			{
				articulation_point.push_back(cities[source]);
			}
			art_point_checked[source] = 1;
		
		
			FOR(i, 1, N)
			{
				// Additional checks if this is not the first iteration
				// of the do..while loop
				if (i == source || pred[i] == -1 || already_covered[i] == 1)
				{
					continue;
				}
				else
				{
					int p = pred[i];
					children[p].push_back(i);
					already_covered[i] = 1;
				}
			}

			REP(i, N)
			{
				if (i == source)
				{
					continue;
				}
				bool art_point = false;
				REP(j, children[i].size())
				{
					if (low[children[i][j]] >= depth[i])
					{
						art_point = true;
						break;
					}				
				}
				if (art_point && art_point_checked[i] == -1)
				{
					articulation_point.push_back(cities[i]);
					art_point_checked[i] = 1;
				}
			}

			// Check if there are any unvisited vertices
			vertices_left = false;
			REP(i, N)
			{
				if (i != source && visited[i] == 0)
				{
					source = i;
					vertices_left = true;
					break;
				}
			}
		}while(vertices_left);

		int cam_num = articulation_point.size();
		sort(articulation_point.begin(), articulation_point.end());

		cout << "City map #" << map_number << ": " << cam_num << " camera(s) found\n";
		
		REP(i, cam_num)
		{
			cout << articulation_point[i] << "\n";
		}
		
		cin >> N;
		if (N != 0)
			cout << "\n";
	}
}
