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
	sort(bags.begin(), bags.end()); // �������� ����
}

void solution() {
	input();

	cout << Z_O_KnapSack();
}

long long Z_O_KnapSack() {
	long long Val = 0;

	for (int i = 0; i < bags.size(); i++) { // ��� ���濡 ���Ͽ�
		while (!jewels.empty() && jewels.top().first <= bags[i]) { // ���濡 ���� ��� ������ ���Ͽ�
			jewels_value.push(jewels.top().second); // ������ ��´� (��ġ�� ���������� �ȴ�)
			// ��ġ�� ��� ������, ���Դ� ���� ���̻� �ʿ� ���� �����̴�.
			jewels.pop();
		}
		// ����, jewels_value �� ��� �������� ��� i��° ���濡 ���� �������̴�.
		if (jewels_value.empty()) continue; // �̰� ���ؼ� ��Ÿ�� ���� �ɷȾ���
		Val += jewels_value.top();
		jewels_value.pop();
	}
	return Val;
}