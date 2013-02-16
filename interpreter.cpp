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

class triplet
{
	public:

	int first;
	int second;
	int third;
	triplet(){first = 0; second = 0; third = 0;}
	triplet(int i, int j, int k){first = i; second = j; third = k;}
	triplet(int num)
	{
		num = num%1000;
		third = num%10;
		num = num/10;
		second = num%10;
		num = num/10;
		first = num;
	}
	int num()
	{
		return first * 100 + second * 10 + third;
	};
};

void execute(triplet& word, triplet& next_word, int idx, int& next_idx, vector < triplet >& ram, vector < triplet >& registers)
{
	int op = word.first;
	int s = word.third;
	int d = word.second;
	int n = s;
			
		if (op == 0)
		{
			if (!(registers[s].num() == 0))
			{
				int loc = registers[d].num();	
				next_word = ram[loc];
				next_idx = loc;
			}
			else
			{
				next_idx = idx + 1;
				next_word = ram[next_idx];
			}
		}
		
		else if (op == 1)
		{
			// Won't reach here
		}

		else if (op == 2)
		{
			triplet t2(0, 0, n);
//			cout << "Setting register " << d << " to " << t2.num() << "\n";
			registers[d] = t2;	
			next_idx = idx + 1;
			next_word = ram[next_idx];
		}
			
		else if (op == 3)
		{
			int sum = n + registers[d].num();	
			
			triplet t3(sum);
			registers[d] = t3;
			next_idx = idx + 1;
			next_word = ram[next_idx];
		}	

		else if (op == 4)
		{
			int prod = registers[d].num() * n;	
			triplet t4(prod);
			registers[d] = t4;
			next_idx = idx + 1;
			next_word = ram[next_idx];
		}	

		else if (op == 5)
		{
			registers[d] = registers[s];
			next_idx = idx + 1;
			next_word = ram[next_idx];
		}	

		else if (op == 6)
		{
			int sum = registers[d].num() + registers[s].num();
//			cout << "register d: " << registers[d].num() << " and register s: " << registers[s].num() << "\n";
//			cout << "sum = " << sum << "\n";
			triplet t6(sum);
//			cout << "Setting register " << d << " to " << t6.num() << "\n";
			registers[d] = t6;
			next_idx = idx + 1;
			next_word = ram[next_idx];
		}	

		else if (op == 7)
		{
			int prod = registers[d].num() * registers[s].num();	
			triplet t7(prod);
			registers[d] = t7;
			next_idx = idx + 1;
			next_word = ram[next_idx];
		}	

		else if (op == 8)
		{
			int a = s;
			int loc = registers[a].num();
			registers[d] = ram[loc];
			next_idx = idx + 1;
			next_word = ram[next_idx];
		}
	
		else if (op == 9)
		{
			int a = s;
			int loc = registers[a].num();
			ram[loc] = registers[d];
			next_idx = idx + 1;
			next_word = ram[next_idx];
		}
	
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	string input;
	int testcases = 0;
	getline(cin, input); 
	stringstream convert(input);
	convert >> testcases;
//	cout << "Testcase " << testcases << "\n";

	getline(cin, input);

	REP(z, testcases)
	{		
		
	
		vector < triplet > registers(10);		
		vector < triplet > ram(1000);

		int i = 0;

		while(getline(cin, input))
		{
			if (input.size() == 0)
			{
				break;
			}

//			cout << i << ": " << input << "\n";
			
			ram[i].first = input[0] - '0';
			ram[i].second = input[1] - '0';
			ram[i].third = input[2] - '0';	
		
			i++;
		}

//		cout << "Finished reading all input \n";
		
		int count = 0;
		int idx = 0;
		int next_idx = 0;
		triplet word = ram[0];
		triplet next_word;
		
		while(word.first != 1)
		{
//			cout << "executing word " << word.first << word.second << word.third << " at index " << idx << "\n";
			count++;	
		
			execute(word, next_word, idx, next_idx, ram, registers);
			word = next_word;
			idx = next_idx;	
		}
		
		cout << count + 1 << "\n";
		
		cout << "\n";
	}
	return 0;
}
