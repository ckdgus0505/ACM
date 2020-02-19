#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int MAX_N = 300, MAX_M = 300;
bool adj[MAX_N][MAX_M];
vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a) {
	if (visited[a])	return false;
	visited[a] = true;
	for(int i=0; i<m; ++i)
		if(adj[a][i])
			if (bMatch[i] == -1 || dfs(bMatch[i])) {
				aMatch[a] = i;
				bMatch[i] = a;
				return true;
			}
	return false;
}

int bipartiteMatch() {
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);
	int size = 0;
	for (int start = 0; start < n; ++start) {
		visited = vector<bool>(n, false);
		if (dfs(start))
			++size;
	}
	return size;
}

int main(void) {
	
}