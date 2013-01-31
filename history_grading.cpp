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

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i, FROM, n) for (int i = FROM; i < n; i++)

int lcs (vector <int>& s1, vector <int>& s2, size_t i, size_t j, vector < vector <int> >& results)
{
	if ( i == s1.size() || j == s2.size() )
		return 0;

	if (results[i][j] != -1)
		return results[i][j];
	else if (s1[i] == s2[j])
		return results[i][j] = 1 + lcs(s1, s2, i+1, j+1, results);
	else
		return results[i][j] = max(lcs(s1, s2, i+1, j, results), lcs(s1, s2, i, j+1, results));
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int N = 0;
	cin >> N;

	vector <int> correct(N);
	REP(i, N)
	{
		int ranking = 0;
		cin >> ranking;
		correct[ranking-1] = i;
	}

	while (true)
	{
	int t = 0;
	cin >> t;
	
	if (!cin.eof())
	{
		vector <int> seq(N);
		seq[t-1] = 0;
		FOR(i, 1, N)
		{
			int ranking;
			cin >> ranking;
			seq[ranking-1] = i;
		}

		vector < vector <int> > c(N, vector <int> (N, -1));
		cout << lcs(correct, seq, 0, 0, c) << "\n";
		// Alternative
		/*
		REP(i, s1.size())
		{
			REP(j, s2.size())
			{
				if (s1[i] == s2[j])
				{		
					if (i-1 >= 0 && j-1 >= 0)
						c[i][j] = 1 + c[i-1][j-1];
					else
						c[i][j] = 1;
				}
				else
				{
					if (i-1 >= 0 && j-1 >= 0)
					{
						c[i][j] = max(c[i-1][j], c[i][j-1]);
					}
					else if (i-1 >= 0)
					{
						c[i][j] = c[i-1][j];
					}
					else if (j-1 >= 0)
					{
						c[i][j] = c[i][j-1];
					}
					else
						c[i][j] = 0;
				}
			}
		}

		cout << c[s1.size() - 1][s2.size() - 1] << "\n";
		*/
		
	}
	else
	{
		return 0;
	}
	}
	
}

