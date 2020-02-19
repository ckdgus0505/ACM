#include <iostream>
#include <vector>
using namespace std;

class Sorting {
	vector<int> arr;
	Sorting() {
		int n;
		cout << "Input Array Size : ";
		cin >> n;
		arr = vector<int>(n);

		cout << "Input Array : ";
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
	}
	Sorting(int n) : arr(n) {
		cout << "Input Array : ";
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
	}
	Sorting(int n, int a[]) : arr(n){
		for (int i = 0; i < n; ++i)
			arr[i] = a[i];
	}
public:
	void insertionSort(bool ascending) {
		for (int i = 1; i < arr.size(); ++i) {
			for (int j = i; j > 0; --j) {
				if (!((arr[j] < arr[j - 1]) ^ ascending)) 
					std::swap(arr[j], arr[j - 1]);
			}
		}
	}
	void mergeSort() {

	}
	void heapSort() {

	}
	void QuickSort() {

	}
};

int main(void) {

}