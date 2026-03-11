#include<iostream>
#include <string>

using namespace std;

template <typename T>
class Array
{
    T* arr;
    int size;
    int n;

public:
    Array(int ssize)
    {
        size = ssize;
        n = 0;
        arr = new T[size];
    }

    void insert(T v)
    {
        if (n == size)
        {
            cout << "Array is full. Cannot insert " << v << endl;
            return;
        }

        arr[n] = v;
        n++;
    }

    int search(T v)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == v)
                return i;
        }
        return -1;
    }

    void remove(T v)
    {
        int index = search(v);

        if (index == -1)
        {
            cout << v << " not found in array." << endl;
            return;
        }

        for (int i = index; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        n--;
        cout << v << " removed successfully." << endl;
    }
};



int main()
{
    cout << "Integer Array Test" << endl;
    Array<int> intArr(5);

    intArr.insert(10);
    intArr.insert(20);
    intArr.insert(30);
    intArr.insert(40);
    intArr.insert(50);

    int index = intArr.search(30);

    if (index != -1)
        cout << "30 found at index: " << index << endl;
    else
        cout << "30 not found" << endl;

    cout << "\nFloat Array Test" << endl;
    Array<float> f1(3);

    f1.insert(1.4);
    f1.insert(2.5);
    f1.insert(3.6);
    f1.insert(4.8);


    cout << "\nString Array Test" << endl;
    Array<string> str(10);

    str.insert("Ali");
    str.insert("Ahmed");
    str.insert("Sara");
    str.insert("Zain");
    str.insert("Fatima");

    string name;
    cout << "Enter name to search: ";
    cin >> name;

    int i = str.search(name);

    if (i != -1)
        cout << name << " found at index " << i << endl;
    else
        cout << name << " not found in the array." << endl;

    return 0;
}