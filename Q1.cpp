#include<iostream>
using namespace std;

template <typename T>
class Counter
{
	T value;
public:

	Counter(T v) ;
	void increment();
	T getValue();

};

template <typename  T>
Counter<T>::Counter(T v)
{
	value = v;

}

template <typename  T>
void Counter<T>::increment()
{
	value = value + 1;
}


template <typename T>
T  Counter<T>::getValue()
{
	return value;

}

int main()
{
	Counter<int> int_counter(4);
	cout << "Int Counter: " << endl;
	for (int i = 0; i < 3; i++) 
	{
		int_counter.increment();
		cout << int_counter.getValue() << endl;
	}

	Counter<float> float_counter(4.5);

	cout << "\nFloat Counter: " << endl;
	for (int i = 0; i < 3; i++)
	{
		float_counter.increment();
		cout << float_counter.getValue() << endl;
	}

	Counter<double> double_counter(45.55);

	cout << "\nDouble Counter: " << endl;
	for (int i = 0; i < 3; i++)
	{
		double_counter.increment();
		cout << double_counter.getValue() << endl;
	}

}