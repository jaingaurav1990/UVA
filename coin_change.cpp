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

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, FROM, n) for (int i = FROM; i < n; i++)

int main()
{
	int N = 0; 
	cin >> N;
	
	vector <int> ways(7490, 1);
	vector <int> coins(4);
	coins[0]= 5;
	coins[1] = 10;
	coins[2] = 25;
	coins[3] = 50;

	for (vector <int>::iterator it = coins.begin(); it != coins.end(); it++)
	{
		REP(i, 7490)
		{
			if (i - *it >= 0)
				ways[i] = ways[i] + ways[i-*it];
			
		}
	}		
	
	while (!cin.eof())
	{
		cout << ways[N] << "\n";
		cin >> N;
	}
}
