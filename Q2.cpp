#include<iostream>
using namespace std;

template <typename T>
class Array {

	T arr[5];

public:
	void set(int index, T value);
	T get(int index);
	void print();
};

template <typename T>
void Array<T>::set(int index, T value)
{
	if (index < 0 || index>5)
	{
		cout << "Index not found." << endl;
	}
	else
		arr[index] = value;
}

template <typename T>
T Array<T>::get(int index)
{
	if (index < 0 || index > 5)
	{
		cout << "Index out of range" << endl;
		return T();
	}
	else
		return arr[index];
		
}

template <typename T>
void Array<T>::print()
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{

	Array<int> intArr;

	intArr.set(0, 5);
	intArr.set(1, 7);
	intArr.set(2, 10);
	intArr.set(3, 12);
	intArr.set(4, 15);

	cout << "Integer Array: ";
	intArr.print();

	Array<double> doubleArr;

	doubleArr.set(0, 1.3);
	doubleArr.set(1, 2.2);
	doubleArr.set(2, 3.5);
	doubleArr.set(3, 4.7);
	doubleArr.set(4, 5.9);

	cout << "Double Array: ";
	doubleArr.print();

	return 0;
}
