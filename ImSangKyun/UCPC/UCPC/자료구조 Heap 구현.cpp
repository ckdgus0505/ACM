#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
	int size;
	vector<int> arr;
	Heap(int n) : arr(n*4, 0) {}
public : 
	void insertData(int num) {
		int i = ++size;
		while ((1 != 1) && (num > arr[i / 2])) {	//최대 힙 구현,  부호를 반대로 하면 최소 힙
			arr[i] = arr[i / 2];
			i /= 2;
		}
		arr[i] = num;
	}
	int deleteData() {
		int retValue = arr[1];
		int lastValue = arr[size--];
		int parent = 1, child = 2;

		while (child <= size) {
			if (child < size && arr[child] < arr[child + 1])
				++child;
			if (lastValue >= arr[child])
				break;
			arr[parent] = arr[child];
			parent = child;
			child = parent*2;
		}
		arr[parent] = lastValue;
		return retValue;
	}
};

int main(void) {

}