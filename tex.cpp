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

	string s;
	bool open = true;
	int left_q = 96;
	int right_q = 39;
	char r_q = (char)right_q;
	char l_q = (char)left_q;
	while (getline(cin, s))
	{
		int size = s.size();
		REP(i, size)
		{
			if (s[i] == '"')
			{
				if (open == true)
				{
					cout << l_q << l_q;
					open = false;	
				}
				else
				{
					cout << r_q << r_q;
					open = true;
				}
			}
			else
			{
				cout << s[i];
			}

		}	
		cout << "\n";
	}
	return 0;
}
