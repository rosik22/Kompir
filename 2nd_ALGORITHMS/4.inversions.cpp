#include <iostream>
using namespace std;

int main() {
	char A[] = "912989";
	int n = 6;
	int min;
	int flag;

	for (int i = 0; i < n-1; i++)
	{
		min = A[i];
		flag = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j]<min)
			{
				min = A[j];
				flag = j;
			}
		}
		A[flag] = A[i];
		A[i] = min;
	}
	cout << A << endl;
	return 0;
}

//������ 5 - ����������� �� �������� � �����
#include <iostream>
using namespace std;

int main() {
	int arr[6] = { 9,1,2,9,8,2 };
	int c = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i+1; j < 6; j++)
		{
			if (arr[i]>arr[j])
			{
				++c;
			}
		}
	}
	cout << "Count of inversions = " << c << endl;
	return 0;
}

