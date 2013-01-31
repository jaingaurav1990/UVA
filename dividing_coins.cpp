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

#define MAX_W 500000

using namespace std;

int leftover(int W, int i, vector <int>& coins, int m, vector < vector <int> >& results)
{
	if (W >= 0 && i < m && results[W][i] != -1)
		return results[W][i];

	if (i >= m)
	{
		return W;
	}
	if (coins[i] == W)
	{
		return 0;
	}
	else if (coins[i] > W)
	{
		return results[W][i] = leftover(W, i+1, coins, m, results);
	}
	else
	{
		return results[W][i] = min(leftover(W-coins[i], i+1, coins, m, results), leftover(W, i+1, coins, m, results));
	}
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int testcases = 0;
	cin >> testcases;

	for (int c = 0; c < testcases; c++)
	{
		int m = 0;
		cin >> m;

		if (m == 0)
		{
			cout << 0 << "\n";
			continue;
		}

		vector <int> coins(m);	
		int max_w = 500*m/2;

		vector < vector <int> > results (max_w + 1, vector <int> (m, -1));
		int sum = 0;

		for (int i = 0; i < m; i++)
		{
			cin >> coins[i];
			sum = sum + coins[i];
		}

		if (m == 1)
		{
			cout << coins[0] << "\n";
			continue;
		}

		int left_cap = leftover(sum/2, 0, coins, m, results);	
		int side1 = sum/2 - left_cap;
		int side2 = sum - side1;
		if (side1 - side2 >= 0)
			cout << side1 - side2 << "\n";
		else
			cout << side2 - side1 << "\n";
	}

	return 0;
}
