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
	cin >> s;
	while (!cin.eof())
	{
		int size = s.size();
		REP(i, size)
		{
			int c = (int)s[i] - 7;	
			cout << (char)c ;
		}
		cout << "\n";

		cin >> s;
	}
	return 0;
}
