#include<iostream>
#include<string>
using namespace std;

void inputArray(int arr[], int size)
{
	cout << "Enter 10 integers: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

int LinearSearch(int key, int arr[],int size)
{
	
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
			return i;
	}
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

	cout<<"Integer is at index: " << LinearSearch(key, Array, size) << endl;
	return 0;
}
