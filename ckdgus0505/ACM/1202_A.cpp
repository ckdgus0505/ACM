#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> jewel; // M, V

int N, K;
int M, V;
int C;
priority_queue<jewel, vector<jewel>, greater<jewel> > jewels;
priority_queue<int> jewels_value;
vector<int> bags;

long long Z_O_KnapSack();
void input();
void solution();
int search_min(int val);

int main(void) {
	solution();
}

void input() {
	cin >> N >> K;
	bags.assign(K, 0);

	for (int i = 0; i < N; i++) {
		cin >> M >> V;
		jewels.push(pair<int, int>(M, V));
	}

	for (int i = 0; i < K; i++) {
		cin >> C;
		bags[i] = C;
	}
	sort(bags.begin(), bags.end()); // 오름차순 정렬
}

void solution() {
	input();

	cout << Z_O_KnapSack();
}

long long Z_O_KnapSack() {
	long long Val = 0;

	for (int i = 0; i < bags.size(); i++) { // 모든 가방에 대하여
		while (!jewels.empty() && jewels.top().first <= bags[i]) { // 가방에 들어가는 모든 보석에 대하여
			jewels_value.push(jewels.top().second); // 보석을 담는다 (가치의 내림차순이 된다)
			// 가치만 담는 이유는, 무게는 이제 더이상 필요 없기 때문이다.
			jewels.pop();
		}
		// 현재, jewels_value 에 담긴 보석들은 모두 i번째 가방에 들어가는 보석들이다.
		if (jewels_value.empty()) continue; // 이거 안해서 런타임 에러 걸렸었음
		Val += jewels_value.top();
		jewels_value.pop();
	}
	return Val;
}