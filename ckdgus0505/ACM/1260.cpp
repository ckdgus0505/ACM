#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>> linkedList; // 각 노드들의 연결관계를 나타내는 벡터
vector<bool> DFS_check; // DFS에서 노드를 방문했는지 여부를 담는 벡터
vector<bool> BFS_check; // BFS에서 노드를 방문했는지 여부를 담는 벡터
queue<int> BFS_Q; // BFS에서 탐색할 노드를 넣는 큐

void DFS(int); // 첫번째 인자는 탐색을 시작하는 정점이다. 
void BFS();
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, V; // 정점의 개수 N, 간선의 개수 M, 탐색을 시작할 정점의 번호 V
	cin >> N >> M >> V; 
	linkedList.assign(N + 1, vector<int>(0,0)); // index가 0인 벡터는 버림

	for (int i = 0; i < M; i++) // 간선의 개수만큼 반복문
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		linkedList[tmp1].push_back(tmp2); // 1번에서 2번으로 간선이 이어져 있으면 linkedlist 벡터의 [1]의 뒤에 2를 푸쉬
		linkedList[tmp2].push_back(tmp1);
	}
	
	for (int i = 0; i < N + 1; i++)
	{
		sort(linkedList[i].begin(), linkedList[i].end());
	}

	DFS_check.assign(N + 1, false);
	DFS(V);
	cout << '\n';

	BFS_check.assign(N + 1, false);
	BFS_Q.push(V);
	BFS();
}

void DFS(int start)
{
	if (DFS_check[start] == false)
	{
		cout << start << ' ';
		DFS_check[start] = true;
		for (int i = 0; i < linkedList[start].size() ; i++)
		{
			DFS(linkedList[start][i]);
		}
	}
}
void BFS()
{
	int start;
	while (!BFS_Q.empty())
	{
		start = BFS_Q.front();
		if (BFS_check[start] == false)
		{
			for (int i = 0; i < linkedList[start].size(); i++)
			{
				BFS_Q.push(linkedList[start][i]); // push는 해당 노드 갈 예정
			}
			cout << start << ' ';
		}
		BFS_Q.pop(); // pop은 해당 노드 방문을 의미
		BFS_check[start] = true;
	}
}