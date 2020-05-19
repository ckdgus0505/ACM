#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> jewel; // V,M

int N, K;
int M, V;
int C;
priority_queue<jewel> jewels;
multiset<int> bags;

int Z_O_KnapSack();
void input();
void solution();
int search_min(int val);

int main(void) {
	solution();
}

void input() {
	cin >> N >> K;
	// C.assign(K, 0);
	for (int i = 0; i < N; i++) {
		cin >> M >> V;
		jewels.push(pair<int, int>(V, M));
	}

	for (int i = 0; i < K; i++) {
		cin >> C;
		bags.insert(C);
	}
}

void solution() {
	input();
	
	cout << Z_O_KnapSack();
}

int Z_O_KnapSack() {
	long long sum_V = 0;

	jewel now;
	while (!jewels.empty()) {
		now = jewels.top();
		jewels.pop();
		// ���� ����� ���� ã�� ( num �̶� ����) num < min_weight �϶�, find(num)�� ���� iterator �� ��ȯ, num >= min_weight �� ��� find(num) �� iterator �� ��ȯ�Ѵ�.
		int min_weight = search_min(now.second);

		if (min_weight == -1) return sum_V;
		else if (bags.find(min_weight) == bags.end()) continue; // ������ �� ������ ���� ���
		else { // ������ �Һ��ϰ�, ���� ������ ��ġ�� ������
			bags.erase(bags.find(min_weight));
			sum_V += now.first;
		}

	}

	return sum_V;
}
/*
int search_min(int val) {
	if (bags.empty()) return -1;
	set<int>::iterator iter = bags.begin();
	while ((*iter < val) || iter == bags.end()) {
		iter++;
	}
	return *iter;
}
*/

int search_min(int val) {
	if (bags.empty()) return -1;
	if (bags.find(val) != bags.end()) return *bags.find(val);
	set<int>::iterator iter = bags.upper_bound(val);
	return *iter;
}