#include <iostream>
#include<cstdio>
#include<vector>

using namespace std;
int N, M; // �̷��� ũ��
int minwalk = 987654321; // ������ �������� �ּڰ�
vector<vector<int>> maze; // �̷�
vector<vector<int>> visited; // �湮�� ���� ǥ���ϴ� ����
int adj[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} }; // (y,x)

int counting(pair<int, int> now , int count ); // �̷θ� �ٴϸ鼭 ���� �Լ�
//now�� �� �״�� ���� ��ġ, count�� ���ݱ��� ���鼭 ������ �Ÿ�(ī��Ʈ)
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	maze.assign(N, vector<int>(M, 0));
	visited.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	cout << counting(pair<int, int>(0,0),0) +1 << '\n'; // ������������ ī��Ʈ

}
int counting(pair<int, int> now, int count)
{
	visited[now.first][now.second] = 1;
	if (now.first == N - 1 && now.second == M - 1)
	{
		if (minwalk > count) minwalk = count;
	}
	for (int i = 0; i < 4; i++) // �����¿� 4�� �̵�
	{
		int nextY = now.first + adj[i][0];
		int nextX = now.second + adj[i][1];
		if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M)
		{
			if (maze[nextY][nextX] == 1 && visited[nextY][nextX] == 0)
			{
				counting(pair<int, int>(nextY, nextX), count + 1);
				visited[nextY][nextX] = 0;
			}
		}
	}
	return minwalk;
}