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

int lcs (string& s1, string& s2, size_t i, size_t j, vector < vector <int> >& results)
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
	while (true)
	{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	
	if (s1.size() == 0 && s2.size() == 0)
		return 0;
	else
	{
		//cout << "Processing\n";
		if (s1.size() == 0 || s2.size() == 0)
		{
			cout << 0 << "\n";
			continue;
		}
		vector < vector <int> > c(s1.size(), vector <int> (s2.size(), -1));
		cout << lcs(s1, s2, 0, 0, c) << "\n";
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
	}
	
}

