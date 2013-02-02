#include <iostream>
#include <iomanip>
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

class edge
{
	public:
		int u;
		int v;
		double length;
	edge(){u = 0; v = 0; length = 0;}
	edge(int i, int j, double len){u = i; v = j; length = len;}

	// Overloading operator '<' for use in sort
	bool operator < (const edge& rhs) const
	{
		if (length < rhs.length)
			return true;
		else
			return false;
	}
};

int find_set(int v, vector <int>& parent)
{
	if(parent[v] == v)
		return v;
	else
		return find_set(parent[v], parent);
}

double sq_distance(int i, int j, vector < pair <double, double> >& points)
{
	double d = (points[i].f - points[j].f)*(points[i].f - points[j].f) + (points[i].s - points[j].s)*(points[i].s - points[j].s);
	return sqrt(d);
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int testcases = 0;
	cin >> testcases;
	REP(z, testcases)
	{
		int n = 0;
		cin >> n;
			
		vector < pair<double, double> > points(n);
		
		REP(i, n)
		{
			cin >> points[i].f >> points[i].s;
		}

		if (n == 1)
		{
			cout << 0.00 << "\n";
			if (z != testcases - 1)
			{
				cout << "\n";
				continue;
			}
			else
			{
				continue;
			}
		}

		// Calculate distances between all points
		vector < edge > edges;
		
		REP(i, n)
		{
			REP(j, n)
			{
				if (i != j)
				{
					double dist = sq_distance(i, j, points);
					edge e(i, j, dist);
					edges.push_back(e);
				}
			}
		}	
		
		sort(edges.begin(), edges.end());
		
		vector < double > kruskal_edges;
		set < set<int> > vertex_sets;
		vector <int> parent(n);
		REP(i, n)
		{
			parent[i] = i;
		}

		int e_count = 0;
		int e_id = 0;
		
		while(e_count != n - 1)
		{
			edge e = edges[e_id];
			int set1_rep = find_set(e.u, parent);
			int set2_rep = find_set(e.v, parent);

			if (set1_rep != set2_rep)
			{
				// Found an edge that adds a new vertex
				parent[set2_rep] = set1_rep;
				kruskal_edges.push_back(e.length);
				e_count = e_count + 1;
			}
			e_id++;
		}

		
		double sum = 0;
		REP(i, kruskal_edges.size())
		{
			sum = sum + kruskal_edges[i];
		}	
		cout << setiosflags(ios::fixed) << setprecision(2) << sum << "\n";
		
		if (z != testcases - 1)
		{
			cout << "\n";
		}
		
	}	

	return 0;
}
