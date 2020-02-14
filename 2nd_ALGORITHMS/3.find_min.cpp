#include <iostream>

using namespace std;

int main() {
	unsigned n;
	cout << "enter number of elements\nn= ";
	cin >> n;
	int * arr = new int[n];
	cout << "enter the elements (whole numbers) separated with a white space\n";
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	unsigned minIndex = 0;
	int minValue = arr[0];

	for (size_t i = 1; i < n; i++)
	{
		if (minValue > arr[i])
		{
			minValue = arr[i];
			minIndex = i;
		}
	}
	cout << "minimum value in the given sequence " << minValue << endl;
	cout << "which was found at " << minIndex << endl;
	delete[] arr;

	return 0;
}
