#include <iostream>

using namespace std;

int main()
{
	unsigned n;
	int x;
	cout << "Enter number of elements ";
	cin >> n;
	cout << "Enter the element to search\nx= ";
	cin >> x;
	cout << "Enter sorted sequence \n";
	int *A = new int[n + 1];
	for (size_t i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	A[n] = x;
	unsigned iBeg = 0;
	unsigned iEnd = n;
	unsigned iMid = (iBeg + iEnd) / 2;

	while (A[iMid] != x)
	{
		if (A[iMid] < x)
		{
			iBeg = iMid + 1;
		}
		else
		{
			iEnd = iMid - 1;
		}
		iMid = (iBeg + iEnd) / 2;
	}
	if (iMid == n)
	{
		cout << "x is not in the sequence\n";
	}
	else
	{
		cout << "x was found";
	}
	delete[] A;
	return 0;
}
