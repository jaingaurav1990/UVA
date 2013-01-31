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

using namespace std;
void debug_print( vector < vector <int> >& array, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int N = 0;
	cin >> N;

	vector < vector <int> > array(N, vector <int> (N));
	vector < vector <int> > prefix_sum(N, vector <int> (N));

	for (int i = 0; i < N; i++)
	{
		int row_sum = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> array[i][j];			
			row_sum += array[i][j];

			if (i-1 >= 0)
			{
				prefix_sum[i][j] = prefix_sum[i-1][j] + row_sum;
			}
			else	
			{
				prefix_sum[i][j] = row_sum;
			}
		}
	}

	// debug_print(array, N);
	// cout << " *** \n";
	// debug_print(prefix_sum, N);
	// cout << " *** \n";
	int max_sum = array[0][0];
	int max_i = 0; 
	int max_j = 0;
	int max_p = 0;
	int max_q = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int p = i; p < N; p++)
			{
				for (int q = j; q < N; q++)
				{
					int sub_1 = 0;
					if (i-1 >= 0)
					{
						sub_1 = prefix_sum[i-1][q];
					}
					else
					{
						sub_1 = 0;
					}

					int sub_2 = 0;
					if ( j-1 >= 0 )
					{
						sub_2 = prefix_sum[p][j-1];
					}	
					else
					{
						sub_2 = 0;
					}
					int add_1 = 0;
					if (i-1 >= 0 && j-1 >= 0)
					{
						add_1 = prefix_sum[i-1][j-1];
					}
					int sum = prefix_sum[p][q] - sub_1 - sub_2 + add_1;			
					//cout << "Sum for i: " << i << " j:" << j << " p:" << p << " q:" << q << " is " << sum  << "with sub_1 = " << sub_1 << " sub_2 = " << sub_2 << " and add_1 = " << add_1 << "\n";
					if (sum > max_sum)
					{
						max_i = i;
						max_j = j;
						max_p = p;
						max_q = q;
						max_sum = sum;
					}
				}
			}
		}
	}	

	cout << max_sum << "\n"; // " " << max_i << " " << max_j << " " << max_p << " " << max_q <<  "\n";

}
