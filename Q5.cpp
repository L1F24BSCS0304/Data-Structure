#include<iostream>
using namespace std;

template <typename T>
class Range
{
    T min;
    T max;

public:
    Range(T minimum, T maximum);
    bool contains(T value);
};

template <typename T>
Range<T>::Range(T minimum, T maximum)
{
    min = minimum;
    max = maximum;
}

template <typename T>
bool Range<T>::contains(T value)
{
    return (value >= min && value <= max);
}



int main()
{

    Range<int> intRange(10, 40);
    cout << "Integer Range (10-40)" << endl;
    cout << "17: " << intRange.contains(17) << endl;
    cout << "55: " << intRange.contains(55) << endl;

    Range<double> doubleRange(4.5, 10.5);
    cout << "\nDouble Range (4.5-10.5)" << endl;
    cout << "7.2: " << doubleRange.contains(7.2) << endl;
    cout << "12.7: " << doubleRange.contains(12.7) << endl;

    Range<char> charRange('A', 'H');
    cout << "\nChar Range (A-H)" << endl;
    cout << "D: " << charRange.contains('D') << endl;
    cout << "Z: " << charRange.contains('Z') << endl;

    return 0;
}