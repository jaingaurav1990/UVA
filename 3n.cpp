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
#define f first
#define s second
#define mp make_pair

typedef signed long long sll;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	sll a = 0; sll b = 0;
	vector <sll> cycle_len(1000000, -1);
	vector < pair <sll, sll> > visited;
	cycle_len[1] = 1;

	cin >> a >> b;
	while(!cin.eof())
	{
		sll max = 0;
		sll len = 0;
		sll lower = a;
		sll upper = b + 1;
		if (a > b)
		{
			upper = a + 1;
			lower = b;
		}

		FOR(start, lower, upper)
		{
			sll i = start;
			sll step = 0;
			while (true)
			{
				if (i < 1000000 && cycle_len[i] != -1)
				{
					len = cycle_len[i];
					break;
				}
				else if ((0x01 & i) == 0)
				{
					visited.push_back(mp(i, step));
					i = i/2;
					step = step + 1;
				}
				else
				{
					visited.push_back(mp(i, step));
					i = 3*i + 1;
					step = step + 1;
				}
				
			}

			//cout << "visited.size : " << visited.size() << "\n";
			// Fill cycle lengths of all visited numbers
			sll size = visited.size();
			REP(j, size)
			{
				
				if (visited[j].f < 1000000)
				{
					cycle_len[visited[j].f] = len + (step - visited[j].s); 
				}
				//cout << "start ======= " << start << "\n";
				//cout << "Setting for : " << visited[j].f << " :" << len + (step - visited[j].s) << "\n";
			}


			//cout << "len for start = " << start << " stopped at i = " << i << " with cycle_len[i] = " << len << "\n";
			len = len + step;
			visited.clear();

			if (len > max)
				max = len;
		}
				
		cout << a << " " << b << " " << max << "\n";
		cin >> a >> b;
	}

	return 0;
}
