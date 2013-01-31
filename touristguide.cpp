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

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int N = 0, R = 0;
		
	cin >> N >> R;
	int scenario = 1;
	while (N != 0 && R != 0)
	{
		vector < vector <int> > cost(N, vector <int> (N, -1));
		vector < vector <int> > d(N, vector <int> (N));
	
		for (int i = 0; i < R; i++)
		{
			int c1, c2, c;
			cin >> c1 >> c2 >> c;
			cost[c1-1][c2-1] = cost[c2-1][c1-1] = c;
		}

		int source, destination, num;
		cin >> source >> destination >> num;

		// Use technique deceptively similar to Floyd-Warshall
		
		// Initialize

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				d[i][j] = cost[i][j];	
			}
		}

		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					d[i][j] = max(d[i][j], min(d[i][k], d[k][j]));					
				} 

			}
		}

		int t_at_a_time = d[source-1][destination-1] - 1;
		//cout << d[source-1][destination-1] << "\n";
		int trips = num/t_at_a_time;
		if (trips * t_at_a_time < num)
			trips = trips + 1;	

		cout << "Scenario #" << scenario << "\n";
		cout << "Minimum Number of Trips = " << trips << "\n\n";;

		scenario++;
		cin >> N >> R;
	}
	

	
}
