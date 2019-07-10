
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//vector<vector<int> > arr(6, vector<int>(5, 0));
vector<vector<int> > trvec(500000);            // index 0 사용.
vector<bool > visited(500000, false);


int N;
int result;

void dfs(int state, int sum) {
	//visited[state] = true;

	if (trvec[state].size() == 1 && visited[trvec[state][0]] ==true) {
		result += sum;
		return;
	}
	for (int i=0; i < trvec[state].size();i++) {
		if (visited[trvec[state][i]] == false) {
			visited[trvec[state][i]] = true;
			visited[state] = true;
			dfs(trvec[state][i], sum + 1);
			visited[state] = false;
			visited[trvec[state][i]] = false;
			//visited[i] = false; 필요없다.
		}
		
	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int a;
	int b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a;
		cin >> b;
		trvec[a - 1].push_back(b - 1);
		trvec[b - 1].push_back(a - 1);
	}

	dfs(0, 0);
	if (result % 2 == 0)
		cout << "No";
	else
		cout << "Yes";

	return 0;
}