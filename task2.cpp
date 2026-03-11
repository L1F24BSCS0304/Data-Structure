#include <iostream>
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
            cout << "Array is full. Cannot insert more items." << endl;
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
            cout << "Product not found." << endl;
            return;
        }

        for (int i = index; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        n--;
        cout << "Product removed successfully." << endl;
    }
};

class Product
{
public:
    int productID;
    string productName;
    float price;
    int quantity;

    Product()
    {
        productID = 0;
        productName = "";
        price = 0;
        quantity = 0;
    }

    Product(int id, string name, float p, int q)
    {
        productID = id;
        productName = name;
        price = p;
        quantity = q;
    }

    void display()
    {
        cout << "ID: " << productID << " Name: " << productName << " Price: " << price << " Quantity: " << quantity << endl;
    }

    bool operator==(Product p)
    {
        return productID == p.productID;
    }

    friend ostream& operator<<(ostream& out, Product p)
    {
        out << "ID: " << p.productID << ", Name: " << p.productName << ", Price: " << p.price << ", Quantity: " << p.quantity;
        return out;
    }
};

int main()
{
    Array<Product> store(10);

    store.insert(Product(101, "Laptop", 1200, 5));
    store.insert(Product(102, "Phone", 800, 10));
    store.insert(Product(103, "Tablet", 400, 7));
    store.insert(Product(104, "Headphones", 150, 20));
    store.insert(Product(105, "SmartWatch", 250, 8));
    store.insert(Product(106, "Camera", 900, 4));

    int id;
    cout << "Enter product ID to search: ";
    cin >> id;

    Product searchProduct(id, "", 0, 0);
    int index = store.search(searchProduct);

    if (index != -1)
        cout << "Product found at index: " << index << endl;
    else
        cout << "Product not found." << endl;

    cout << "Enter product ID to remove: ";
    cin >> id;

    Product removeProduct(id, "", 0, 0);
    store.remove(removeProduct);

    int check = store.search(removeProduct);

    if (check == -1)
        cout << "Product no longer exists in the store." << endl;
    else
        cout << "Product still found at index: " << check << endl;

    store.insert(Product(107, "Mouse", 25, 30));
    store.insert(Product(108, "Keyboard", 50, 15));
    store.insert(Product(109, "Monitor", 300, 6));
    store.insert(Product(110, "Printer", 200, 3));
    store.insert(Product(111, "Speaker", 100, 12));
    store.insert(Product(112, "Mike", 160, 11));
    return 0;
}