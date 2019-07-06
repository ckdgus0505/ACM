#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int k =0;


void test(void) {
	int n;
	cin >> n;
	int* sieve = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j += i) {
			sieve[j] += 1;
			cout << i << " " << j << "\n";
			k++;
		}
	}

	cout << "count:" << k << "\n";
}

int result(int n) {
	int sum;

	sum = n;
	int num = n - 1;
	for (int i = 1; i <= n; i++) {
		sum += num/i;
		cout << sum << "\n";
	}
	return sum;
}

int result2(int n) { // 3보다 큰 경우에만 이 함수를
	int sum;
	int lim = int(sqrt(n));
	sum = n;
	int num = n - 1;

	int a1 = 1;
	int b1 = (n - 1) / a1;
	int a2;
	int b2;
	for (int i = 2; i <= lim+1; i++) {
		//1.

		a2 = i;
		b2 = (n - 1) / i;
		//cout << "a1/b1  a2/b2" << "\n";
		//cout << a1 << " " << b1 << " " << a2 << " " << b2 << "\n";
		//절대값 출력함수.
		sum += abs(b2 - b1) * a1;
		cout << abs(b2 - b1) * a1 << "\n";
		sum += abs(a2 - a1) * b1;
		cout << abs(a2 - a1) * b1 << "\n";
		a1 = a2;
		b1 = b2;
	}
	return sum;
}

int main(void) {
	int n;
	cin >> n;
	//for(int i=3;i<20;i++)
		cout << result(12)<<" "<<result2(12)<<"\n";
	test();


			
}