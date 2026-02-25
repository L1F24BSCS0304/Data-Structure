#include<iostream>
#include<string>
using namespace std;

void inputArray(int arr[], int size)
{
	cout << "Enter 10 sorted integers: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}



int BinarySearch(int key, int arr[], int size)
{
	int low = 0;
	int high = size - 1;
	
	while (low < high)
	{
		int mid = (low + high) / 2;

		if (arr[mid] == key)
			return mid;
		else if (arr[mid] > key)
			high = mid + 1;
		else
			low = mid + 1;
	}
	if (low > high)
		return -1;
	
}
int main()
{
	const int size = 10;
	int Array[size];

	inputArray(Array, size);

	int key;
	cout << "Enter integer you want to find: ";
	cin >> key;

	cout << "Integer is at index: " << BinarySearch(key, Array, size) << endl;
	return 0;
}
