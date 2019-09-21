#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int N, K;
queue<int> passenger;
vector<deque<int>> q;
stack<int> sorted;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	q.assign(K, deque<int>());
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		passenger.push(tmp);
	}
	
	while (!passenger.empty()) {

		int flag = 0; // push ¿©ºÎ

		for (int i = 0; i < q.size(); i++) {
			if (!q[i].empty() && q[i].back() < passenger.front()) {
				q[i].push_back(passenger.front());
				passenger.pop();
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			for (int i = 0; i < q.size(); i++) {
				if (sorted.empty()) {
					if (q[i].front() == 1) {
						sorted.push(q[i].front());
						q[i].pop_front();
						break;
					}
				}
				else if (sorted.top() + 1 == q[i].front()) {
					sorted.push(q[i].front());
					q[i].pop_front();
					break;
				}
			}
		}
		if (flag == 0) {
			for (int i = 0; i < q.size(); i++) {
				if (q[i].empty()) {
					q[i].push_back(passenger.front());
					passenger.pop();
					flag = 2;
					break;
				}
			}
		}
		if (flag == 0) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	return 0;
}