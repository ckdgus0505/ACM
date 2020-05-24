/* 
 백준 알고리즘 1005
 풀이 아이디어 : 다이나믹 프로그래밍 (backward approach)
 - 시간 초과 - 
 메모이제이션
 - 성공 -
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T; // number of test case
int N; // number of buildings
int K; // number of construction order rule of buildings
int X, Y; // construction order rule of building (X->Y)
int W; // target building
vector<int> D; // cost time to build buildings
vector<vector<int>> graph; // reversed graph for building order
vector<int> answers; // vector for save answers
vector<int> cache;

int build_time(int target);
void solution();
void input();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solution();
}

void solution() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		input();
		answers.push_back(build_time(W));
	}

	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i] << '\n';
	}
}

void input() {
	cin >> N >> K;
	D.assign(N + 1, 0);
	graph.assign(N + 1, vector<int>());
	cache.assign(N + 1, -1);
	
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
	}

	for (int i = 0; i < K; i++) {
		
		cin >> X >> Y;
		graph[Y].push_back(X);
	}

	cin >> W;
}

int build_time(int target) {
	if (cache[target] != -1) return cache[target];

	int cost_time = D[target];

	int max_time = 0;
	for (int i = 0; i < graph[target].size(); i++) {
		max_time = max(max_time, build_time(graph[target][i]));
	}
	cache[target] = max_time + cost_time;
	return cache[target];
}