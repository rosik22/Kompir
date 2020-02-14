#include <iostream>

using namespace std;

int main() {
	const unsigned short n = 8;
	int A[] = {11,-3,4,7,8,7,3,5};
	int B[n];
	int max = A[0];
	int min;
	unsigned short flag;
	for (size_t i = 1; i < n; i++)
	{
		if (max<A[i])
		{
			max = A[i];
		}
	}
	B[n - 1] = max;
	for (size_t i = 0; i < n-1; i++)
	{
		min = A[0];
		flag = 0;
		for (size_t j = 1; j < n; j++)
		{
			if (A[j]<min)
			{
				min = A[j];
				flag = j;
			}
		}
		B[i] = min;
		A[flag] = max;
	}

	return 0;
}
