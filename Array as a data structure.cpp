#include<iostream>
#include<string>
using namespace std;

class arrays {
	int arraySize;
	int arrayLength;
	int* ptr;
public:
	arrays() :arrayLength(0), arraySize(0)
	{}
	arrays(int arsz) {
		arraySize = arsz;
		ptr = new int[arraySize];
	}
	void Fill() {
		int elmntsNum;
		cout << "How many elements would you like to enter" << endl;
		cin >> elmntsNum;
		for (int i = 0; i < elmntsNum; i++) {
			cout << "Enter the " << i + 1 << " element" << endl;
			cin >> ptr[i];
			arrayLength++;
		}

	}
	void Display() {
		for (int i = 0; i < arrayLength; i++) {
			cout << ptr[i] << " ";

		}
	}
	int getSize() {
		return arraySize;
	}
	int getLength() {
		return arrayLength;
	}
	int search(int key) {
		int index = -1;
		for (int i = 0; i < arrayLength; i++) {
			if (ptr[i] == key)
			{
				index = i;
			}
		}
		return index;
	}
	void append(int item) {
		if (arrayLength < arraySize) {
			ptr[arrayLength] = item;
			arrayLength++;
		}
		else {
			cout << "Array is full" << endl;
		}
	}
	void insert(int item, int index) {
		for (int i = arrayLength; i > index; i--) {
			ptr[i] = ptr[i - 1];
		}
		ptr[index] = item;
		arrayLength++;
	}
	void Delete(int index) {
		for (int i = index; i < arrayLength-1; i++) {
			ptr[i] = ptr[i + 1];
		}
		arrayLength--;
	}
	void enlarge(int newSize) {
		if (newSize <= arraySize) {
			cout << "New size must be larger than the old one" << endl;
			return;
		}
		else {
			arraySize = newSize;
			int* past=ptr;
			ptr = new int[newSize];
			for (int i = 0; i < arrayLength; i++)
			{
				ptr[i] = past[i];
			}
			delete[]past;
		}
	}
	void merge(arrays other) {
		int* old = ptr;
		int x = arraySize + other.getSize();
		arraySize = x;
		ptr = new int[x];
		int i;
		for (i=0; i < arrayLength; i++) {
			ptr[i] = old[i];
		}
		delete[]old;
		int j = i;
		
		for (int i = 0; i < other.getLength(); i++) {
			ptr[j++] = other.ptr[i];
			arrayLength++;
		}
	}
};





void main() {
	cout << "Enter the array size" << endl;
	int arsize;
	cin >> arsize;
	arrays arr1(arsize);
	arr1.Fill();
	arr1.Display();
	cout << endl;
	cout << "The array size is: " << arr1.getSize() << endl;
	cout << "The array length is: " << arr1.getLength() << endl;
	cout << "Enter the number you would like to search about" << endl;
	int key, index;
	cin >> key;
	index = arr1.search(key);
	if (index == -1)
		cout << "Number not found" << endl;
	else
		cout<<"Number is found at: "<< index<<" index" << endl;
	cout << "Enter the item you would like to add" << endl;
	int item;
	cin >> item;
	arr1.append(item);
	cout << endl;
	arr1.Display();
	cout << "Enter the item you would like to add" << endl;
	int item;
	cin >> item;
	cout << "Enter the index you would like to add the item "<<item<<" at." << endl;
	int index;
	cin >> index;
	arr1.insert(item, index);
	arr1.Display();
	cout << endl;
	cout << "The array size is: " << arr1.getSize() << endl;
	cout << "The array length is: " << arr1.getLength() << endl;
	cout << "Enter the index you would like to delete" << endl;
	int index;
	cin >> index;
	arr1.Delete(index);
	arr1.Display();
	cout << endl;
	cout << "The array size is: " << arr1.getSize() << endl;
	cout << "The array length is: " << arr1.getLength() << endl;
	cout << endl;
	cout << "Enter the new size" << endl;
	int newSize;
	cin >> newSize;
	arr1.enlarge(newSize);
	cout << endl;
	cout << "The array size is: " << arr1.getSize() << endl;
	cout << "The array length is: " << arr1.getLength() << endl;
	arr1.Display();
	arrays other(4);
	other.Fill();
	arr1.merge(other);
	cout << "The array size is: " << arr1.getSize() << endl;
	cout << "The array length is: " << arr1.getLength() << endl;
	cout << endl;
	arr1.Display();

}