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

	sll b1, g1, c1, b2, g2, c2, b3, g3, c3;
	cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3;
	
	while (!cin.eof())
	{
		int s1 = b1 + g1 + c1;
		int s2 = b2 + g2 + c2;
		int s3 = b3 + g3 + c3;

		int min = (s1 - b1) + (s2 - c2) + (s3 - g3);
		string min_s = "BCG";
		
		int cand = (s1 - b1) + (s2 - g2) + (s3 - c3);
		if (cand < min)
		{
			min_s = "BGC";
			min = cand;
		}

		cand = (s1 - c1) + (s2 - b2) + (s3 - g3);
		if (cand < min)
		{
			min_s = "CBG";
			min = cand;
		}

		cand = (s1 - c1) + (s2 - g2) + (s3 - b3);
		if (cand < min)
		{
			min_s = "CGB";
			min = cand;
		}

		cand = (s1 - g1) + (s2 - b2) + (s3 - c3);
		if (cand < min)
		{
			min_s = "GBC";
			min = cand;
		}

		cand = (s1 - g1) + (s2 - c2) + (s3 - b3);
		if (cand < min)
		{
			min_s = "GCB";
			min = cand;
		}

		cout << min_s << " " << min << "\n";
		cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3;
			
	}

	return 0;
}
