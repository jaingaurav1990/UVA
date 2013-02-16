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
#include <sstream>

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
	string input;
	int testcases;
	getline(cin, input);
	stringstream convert(input);
	convert >> testcases;
	cout << "Testcases :" << testcases << "\n";
	int z = 0;
	while(getline(cin, input))
	{
		cout << z << ":" << input << "\n";
		z++;
	}

	cout << "Finished reading all input\n";
	return 0;
}
