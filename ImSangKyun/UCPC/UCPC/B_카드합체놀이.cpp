#include <iostream>
#include <queue>
using namespace std;

int n, m;
priority_queue<long long> pq;

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		pq.push(x*-1);
	}
	for (int i = 0; i < m; ++i) {
		long long num1, num2;
		num1 = pq.top();	pq.pop();
		num2 = pq.top();	pq.pop();
		pq.push(num1 + num2);
		pq.push(num1 + num2);
	}
	unsigned long long res = 0;
	while (!pq.empty()) {
		res += (pq.top() * -1);	pq.pop();
	}
	cout << res << '\n';
}