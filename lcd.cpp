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

char one[] = {
	' ',' ',' ',
	' ',' ','|',
	' ',' ',' ',
	' ',' ','|',
	' ',' ',' '
};

char two[] = {
	' ','-',' ',
	' ',' ','|',
	' ','-',' ',
	'|',' ',' ',
	' ','-',' '
};

char three[] = {
	' ','-',' ',
	' ',' ','|',
	' ','-',' ',
	' ',' ','|',
	' ','-',' '
};
	
char four[] = {
	' ',' ',' ',
	'|',' ','|',
	' ','-',' ',
	' ',' ','|',
	' ',' ',' '
};

char five[] = {
	' ','-',' ',
	'|',' ',' ',
	' ','-',' ',
	' ',' ','|',
	' ','-',' '
};

char six[] = {
	' ','-',' ',
	'|',' ',' ',
	' ','-',' ',
	'|',' ','|',
	' ','-',' '
};

char seven[] = {
	' ','-',' ',
	' ',' ','|',
	' ',' ',' ',
	' ',' ','|',
	' ',' ',' '
};

char eight[] = {
	' ','-',' ',
	'|',' ','|',
	' ','-',' ',
	'|',' ','|',
	' ','-',' '
};


char nine[] = {
	' ','-',' ',
	'|',' ','|',
	' ','-',' ',
	' ',' ','|',
	' ','-',' '
};

char zero[] = {
	' ','-',' ',
	'|',' ','|',
	' ',' ',' ',
	'|',' ','|',
	' ','-',' '
};


int find_dig(vector <int>& digits, int n)
{
	while (n/10)
	{
		int rem = n - (n/10)*10;
		digits.push_back(rem);
		n = n/10 ;
	}
	digits.push_back(n);
	return digits.size();
}

void fill_output(vector < vector < char > >& output, int digit, int pos, int s)
{
	int leftcol = pos * (s + 3);
	char *array;
	if (digit == 1)
	{
		array = one;
	}
	else if (digit == 2)
	{
		array = two;
	}
	else if (digit == 3)
	{
		array = three;
	}
	else if (digit == 4)
	{
		array = four;
	}
	else if (digit == 5)
	{
		array = five;
	}
	else if (digit == 6)
	{
		array = six;
	}
	else if (digit == 7)
	{
		array = seven;
	}
	else if (digit == 8)
	{
		array = eight;
	}
	else if (digit == 9)
	{
		array = nine;
	}
	else 
	{
		array = zero;
	}
	
	int row = 0;
	for (int i = 0; i < 5; i = i + 2)
	{
		int j = 1;
	
		if (array[i*3 + j] == '-')
		{
			if (i == 0)
			{
				row = i;
			} 
			else if (i == 2)
			{
				row = s + 1;
			}
			else if (i == 4)
			{
				row = 2 * s + 2;
			}

			for (int k = leftcol + 1; k < s + leftcol + 1; k++)
			{
				output[row][k] = '-';	
			}		
		}
	}		

	int up_row = 0;
	for (int i = 1; i < 5; i = i + 2)
	{
		for (int j = 0; j < 3; j = j + 2)
		{
			if (array[i*3 + j] == '|')
			{
				//cout << "Found | at (" << i << "," << j << ")\n";
				if (i == 1)
				{
					up_row = 1;	
				}
				else
				{
					up_row = s + 2;
				}

			int column = 0;
			if (j == 0)
			{
				column = leftcol;
			}
			else
			{
				column = leftcol + s + 1;
			}
				
			for (int k = up_row; k < up_row + s; k++)
			{
				output[k][column] = '|';
			}
			}
		}
	}

	
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int s = 0; int n = 0;
	cin >> s >> n;
	while(s || n)
	{
		vector <int> digits;
		int num_dig = find_dig(digits, n);
		vector < vector <char> > output (2*s + 3, vector < char > ((s+2)*num_dig + num_dig - 1, ' '));	

		int sz = digits.size();
		for (int i = sz - 1; i >= 0; i--)
		{
			fill_output(output, digits[i], sz - i - 1, s);	
		}

		REP(i, 2*s + 3)
		{
			REP(j, output[i].size())
			{
				cout << output[i][j] ;
			}
			cout << "\n";
		}
		cin >> s >> n;
		cout << "\n";
		
	}

	return 0;
}
