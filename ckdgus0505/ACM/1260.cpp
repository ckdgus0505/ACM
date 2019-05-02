#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>> linkedList; // �� ������ ������踦 ��Ÿ���� ����
vector<bool> DFS_check; // DFS���� ��带 �湮�ߴ��� ���θ� ��� ����
vector<bool> BFS_check; // BFS���� ��带 �湮�ߴ��� ���θ� ��� ����
queue<int> BFS_Q; // BFS���� Ž���� ��带 �ִ� ť

void DFS(int); // ù��° ���ڴ� Ž���� �����ϴ� �����̴�. 
void BFS();
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, V; // ������ ���� N, ������ ���� M, Ž���� ������ ������ ��ȣ V
	cin >> N >> M >> V; 
	linkedList.assign(N + 1, vector<int>(0,0)); // index�� 0�� ���ʹ� ����

	for (int i = 0; i < M; i++) // ������ ������ŭ �ݺ���
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		linkedList[tmp1].push_back(tmp2); // 1������ 2������ ������ �̾��� ������ linkedlist ������ [1]�� �ڿ� 2�� Ǫ��
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
				BFS_Q.push(linkedList[start][i]); // push�� �ش� ��� �� ����
			}
			cout << start << ' ';
		}
		BFS_Q.pop(); // pop�� �ش� ��� �湮�� �ǹ�
		BFS_check[start] = true;
	}
}