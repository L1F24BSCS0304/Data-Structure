#include<iostream>
using namespace std;

template <typename T>
class Comparator {

	T v1;
	T v2;
public:

	Comparator(T v1, T v2);
	bool isGreater();
	bool isLess();
	bool isEqual();
	T get(int index);

};

template <typename T>
Comparator<T>::Comparator(T V1, T V2)
{
	v1 = V1;
	v2 = V2;
}

template <typename T>
bool Comparator<T>::isGreater()
{
	return v1 > v2;
}

template <typename T>
bool Comparator<T>::isLess()
{
	return v1 < v2;
}

template <typename T>
bool Comparator<T>::isEqual()
{
	return v1 == v2;
}

template <typename T>
T Comparator<T>::get(int index)
{

}

int main()
{
	Comparator<int> c1(5, 8);
	cout << "Int Comparison" << endl;
	cout << "Greater: " << c1.isGreater() << endl;
	cout << "Less: " << c1.isLess() << endl;
	cout << "Equal: " << c1.isEqual() << endl;


	Comparator<double> c2(5.5, -1.3);
	cout << "\nDouble Comparison" << endl;
	cout << "Greater: " << c2.isGreater() << endl;
	cout << "Less: " << c2.isLess() << endl;
	cout << "Equal: " << c2.isEqual() << endl;


	Comparator<char> c3('d', 'D');
	cout << "\nChar Comparison" << endl;
	cout << "Greater: " << c3.isGreater() << endl;
	cout << "Less: " << c3.isLess() << endl;
	cout << "Equal: " << c3.isEqual() << endl;

	return 0;
}