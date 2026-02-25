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

	void BubbleSort(Product* arr, int size)
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

void displayProduct(Product* p)
{
	cout << "ID: " << p->getID()
		<< "  Price: " << p->getPrice() << endl;
}

void displayArray(Product* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		displayProduct(&arr[i]);
	}
}

int linearSearch(Product* arr, int n, float targetPrice)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i].getPrice() == targetPrice)
			return i;
	}
	return -1;
}

int binarySearch(Product* arr, int n, float targetPrice)
{
	int low = 0;
	int high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (arr[mid].getPrice() == targetPrice)
			return mid;
		else if (arr[mid].getPrice() > targetPrice)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main()
{
	Product p1;
	p1.setInput(1111, 500.5);

	Product* ptr = &p1;

	cout << ptr->getID() << " " << ptr->getPrice() << endl;
	cout << (*ptr).getID() << " " << (*ptr).getPrice() << endl;

	Product arr5[5];

	for (int i = 0; i < 5; i++)
	{
		arr5[i].setInput(2000 + i, 100.0f * (i + 1));
	}

	Product* ptrArr = arr5;

	for (int i = 0; i < 5; i++)
	{
		cout << (ptrArr + i)->getID() << " "
			<< (ptrArr + i)->getPrice() << endl;
	}

	int n;
	cout << "Enter number of products: ";
	cin >> n;

	Product* arr = new Product[n];

	for (int i = 0; i < n; i++)
	{
		int id;
		float price;

		cout << "Enter ID and Price for product " << i + 1 << ": ";
		cin >> id >> price;

		arr[i].setInput(id, price);
	}

	cout << "\nOriginal Array:\n";
	displayArray(arr, n);

	float searchPrice;
	cout << "\nEnter price to search: ";
	cin >> searchPrice;

	int index1 = linearSearch(arr, n, searchPrice);

	if (index1 != -1)
		cout << "Linear Search Found at index " << index1 << endl;
	else
		cout << "Linear Search Not Found\n";

	Product obj;
	obj.BubbleSort(arr, n);

	cout << "\nSorted Array:\n";
	displayArray(arr, n);

	int index2 = binarySearch(arr, n, searchPrice);

	if (index2 != -1)
		cout << "Binary Search Found at index " << index2 << endl;
	else
		cout << "Binary Search Not Found\n";

	delete[] arr;
	arr = nullptr;

	return 0;
}