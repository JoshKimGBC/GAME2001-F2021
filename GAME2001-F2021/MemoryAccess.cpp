/* 
	What is the difference from accessing 

	Array[0][0][0] to Array[0][0][1]
				vs
	Array[0][0][0] to Array[1][0][0]
*/
#include <iostream>
#include <time.h>

const int n = 750;
float TestData[n][n][n];

// Helper function that converst clock ticks to milliseconds

double diffClock(clock_t clock1, clock_t clock2) 
{
	double diffTicks = clock1 - clock2; // Difference between 2 seperate clock ticks.
	double diffMS = (diffTicks * 10) / CLOCKS_PER_SEC;
	return diffMS;
}

// Add values row by row
void row_ordered() 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				TestData[i][j][k] = 1;
			}
		}
	}
}

// Add values column by column
void column_ordered()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				TestData[k][j][i] = 2;
			}
		}
	}
}

int main() 
{

	clock_t begin = clock(); // Current number of clock ticks elapsed up to this point
	row_ordered();
	clock_t end = clock(); // Current number of clock ticks elapsed up to this point
	std::cout << "Time elapsed (row): " << diffClock(end, begin) << " ms" << std::endl;

	begin = clock(); // Current number of clock ticks elapsed up to this point
	column_ordered();
	end = clock(); // Current number of clock ticks elapsed up to this point
	std::cout << "Time elapsed (column): " << diffClock(end, begin) << " ms" << std::endl;

	return 0;
}