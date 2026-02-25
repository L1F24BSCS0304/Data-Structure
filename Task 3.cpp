#include<iostream>
#include<string>
using namespace std;

class Product
{
	int ProductID;
	float Price;
public:

	void setInput(int ID, float price)
	{
		ProductID = ID;
		Price = price;
	}

	int getID()
	{
		return ProductID;
	}

	float getPrice()
	{
		return Price;
	}

	int LinearSearch(Product arr[], int size, float key)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i].getPrice() == key)
				return i;
		}
		return -1;
	}

	int BinarySearch(float key, Product arr[], int size)
	{
		int low = 0;
		int high = size - 1;

		while (low <= high)
		{
			int mid = (low + high) / 2;

			if (arr[mid].getPrice() == key)
				return mid;
			else if (arr[mid].getPrice() > key)
				high = mid - 1;
			else
				low = mid + 1;
		}

		return -1;
	}

	void BubbleSort(Product arr[], int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j].getPrice() > arr[j + 1].getPrice())
				{
					Product temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};

int main()
{
	const int SIZE = 15;
	Product products[SIZE];

	products[0].setInput(1001, 450.5);
	products[1].setInput(1002, 1200.0);
	products[2].setInput(1003, 999.9);
	products[3].setInput(1004, 2500.5);
	products[4].setInput(1005, 300.0);
	products[5].setInput(1006, 1750.75);
	products[6].setInput(1007, 4000.0);
	products[7].setInput(1008, 850.25);
	products[8].setInput(1009, 600.0);
	products[9].setInput(1010, 2200.0);
	products[10].setInput(1011, 150.0);
	products[11].setInput(1012, 4800.5);
	products[12].setInput(1013, 2750.0);
	products[13].setInput(1014, 3200.0);
	products[14].setInput(1015, 1100.0);

	cout << "Original Product List:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "ID: " << products[i].getID()
			<< "  Price: " << products[i].getPrice() << endl;
	}

	float searchPrice;
	cout << "\nEnter price to search: ";
	cin >> searchPrice;

	Product obj;

	int linearIndex = obj.LinearSearch(products, SIZE, searchPrice);

	if (linearIndex != -1)
		cout << "Linear Search: Found at index " << linearIndex << endl;
	else
		cout << "Linear Search: Not Found\n";

	obj.BubbleSort(products, SIZE);

	cout << "\nSorted Product List (Ascending by Price):\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "ID: " << products[i].getID()
			<< "  Price: " << products[i].getPrice() << endl;
	}

	int binaryIndex = obj.BinarySearch(searchPrice, products, SIZE);

	if (binaryIndex != -1)
		cout << "Binary Search: Found at index " << binaryIndex << endl;
	else
		cout << "Binary Search: Not Found\n";

	return 0;
}