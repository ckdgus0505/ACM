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
		// 가장 가까운 수를 찾아 ( num 이라 하자) num < min_weight 일때, find(num)의 다음 iterator 를 반환, num >= min_weight 인 경우 find(num) 의 iterator 을 반환한다.
		int min_weight = search_min(now.second);

		if (min_weight == -1) return sum_V;
		else if (bags.find(min_weight) == bags.end()) continue; // 보석이 들어갈 가방이 없는 경우
		else { // 가방을 소비하고, 현재 보석의 가치를 더해줌
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