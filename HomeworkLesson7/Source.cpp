#include <iostream>
#include <assert.h>

using namespace std;

// ===========================================================
// Task:
// Class DynamicArray (template<class t, int len>)
// Example: DynamicArray<double, 20> da;
// Copy Constructor, Copy Assignment operator, Default Constructor
// InitRandom()
// [] operator overloading
// AddElementToEnd
// AddElementToHead
// AddElementByIndex
// DeleteElementByIndex
// Print()
// ===========================================================

template<class t, int len>
class DynamicArray {
	t* arr;
	int size;
	int count;

public:
	DynamicArray() {
		size = len;
		arr = new t[size]{};
	}

	DynamicArray(const DynamicArray& obj) {
		size = obj.size;
		arr = new t[size];

		for (int i = 0; i < size; i++) {
			arr[i] = obj.arr[i];
		}
	}

	DynamicArray& operator=(const DynamicArray& obj) {
		delete[] arr;
		size = obj.size;
		arr = new t[size];

		for (int i = 0; i < size; i++) {
			arr[i] = obj.arr[i];
		}

		return *this;
	}

	void AddElementToEnd(t element) {
		if ((count + 1) <= size) {
			arr[count] = element;
			count++;
		}

		else {
			size = size + len;
			t* temp = new t[size];

			for (int i = 0; i < count; i++) {
				temp[i] = arr[i];
			}

			temp[count] = element;

			delete[] arr;
			arr = temp;
			temp = nullptr;
			count = count + 1;
		}
	}

	void AddElementToHead(t element) {
		if ((count + 1) <= size) {
			t* temp = new t[size];
			temp[0] = element;

			for (int i = 0; i < count; i++) {
				temp[i + 1] = arr[i];
			}

			delete[] arr;
			arr = temp;
			temp = nullptr;
			count = count + 1;
		}

		else {
			size = size + len;
			t* temp = new t[size];

			for (int i = 0; i < count; i++) {
				temp[i + 1] = arr[i];
			}

			temp[0] = element;

			delete[] arr;
			arr = temp;
			temp = nullptr;
			count = count + 1;
		}
	}

	void DeleteElementByIndex(int index) {
		t* temp = new t[size]{};
		int j = 0;

		for (int i = 0; i < count; i++) {
			if (i == index)
				i += 1;
			temp[j++] = arr[i];
		}

		delete[] arr;
		arr = temp;
		temp = nullptr;
		count = count - 1;
	}

	void RandomInit() {
		count = size - 1;
		srand(time(0));

		int select = 0;
		cout << ">> Choose Array Type\n1. int\n2. char\n3. float\nSELECT: ";
		cin >> select;
		system("cls");

		if (select == 1) {
			for (int i = 0; i < count; i++) {
				arr[i] = rand() % 100;
			}
		}

		else if (select == 2) {
			for (int i = 0; i < count; i++) {
				arr[i] = char(rand() % 126 + 32);
			}
		}

		else if (select == 3) {
			for (int i = 0; i < count; i++) {
				arr[i] = (rand() % 100) - 0.4;
			}
		}
	}

	void Print() {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	int GetSize() {
		return size;
	}

	int GetCount() {
		return count;
	}

	~DynamicArray() {
		delete[] arr;
	}
};

void main() {
	DynamicArray<float, 10> data;
	/*data.AddElementToEnd(5);
	data.AddElementToHead(3);
	data.DeleteElementByIndex(1);*/
	data.RandomInit();
	data.Print();

	DynamicArray<float, 10> data2;
	data2 = data;
	data2.Print();
}