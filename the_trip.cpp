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
	int n = 0;
	cin >> n;
	while(n)
	{
		vector <double> expenses(n);
		REP(i, n)
		{
			double exp = 0;
			cin >> exp;
			expenses[i] = exp*100;
		}

		sort(expenses.begin(), expenses.end());
		sll sum = (sll)accumulate(expenses.begin(), expenses.end(), 0);
		sll avg = sum/n;	
		sll rem = sum - (avg*n);
		sll exact = n - rem;

		double transfer = 0;

		int i = 0;
		while(i < n && expenses[i] <= avg)
		{
			if (exact != 0)
			{	
				exact--;
				transfer += (double)avg - expenses[i];	
			}
			else
			{
				transfer += (avg + 1 - expenses[i]);
			}
			i++;
		}
		double tr = (transfer/100);
		cout << setiosflags(ios::fixed) << setprecision(2) << "$" << tr << "\n";
		cin >> n;
	}

	return 0;
}
