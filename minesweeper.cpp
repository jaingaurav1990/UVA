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

typedef signed long long sll;

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, FROM, n) for (int i = FROM; i < n; i++)
#define f first
#define s second
#define mp make_pair

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int n = 0; int m = 0;
	cin >> n >> m;
	int num = 1;
	while (n && m)
	{
		vector < vector <char> > mine_field(n, vector <char> (m, 0));
		vector < vector <char> > sol_field(n, vector <char> (m, 0));
		vector < pair<int, int> > mines;
		REP(i, n)
		{
			REP(j, m)
			{
				cin >> mine_field[i][j];
				if (mine_field[i][j] == '*')
				{
					mines.push_back(mp(i,j));
				}				
			}
		}

		int size = mines.size();
		REP(i, size)
		{
			pair <int, int> p = mines[i];
			sol_field[p.f][p.s] = '*';	

			for (int row = p.f - 1; row <= p.f + 1; row++)
			{
				if (row < n && row >= 0)
				{
					for (int col = p.s - 1; col <= p.s + 1; col++)
					{
						if (col < m && col >= 0 && !(row == p.f && col == p.s) && sol_field[row][col] != '*')
						{
							sol_field[row][col] += 1;	
						}
					}
				}
			}
		}

		cout << "Field #" << num << ":\n";
		num = num + 1;
		
		REP(i, n)
		{
			REP(j, m)
			{
				if (sol_field[i][j] == '*')
				{
					cout << sol_field[i][j];
				}
				else
				{
					cout << (int)sol_field[i][j];
				}	
			}
			cout << "\n";
		}
		
		cin >> n >> m;
		if (n != 0 && m != 0)
		{
			cout << "\n";
		}
	}

	return 0;
}
