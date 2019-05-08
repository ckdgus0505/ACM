#include <iostream>
#include<cstdio>
#include<vector>

using namespace std;
int N, M; // 미로의 크기
int minwalk = 987654321; // 끝까지 갔을때의 최솟값
vector<vector<int>> maze; // 미로
vector<vector<int>> visited; // 방문한 곳을 표시하는 벡터
int adj[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} }; // (y,x)

int counting(pair<int, int> now , int count ); // 미로를 다니면서 세는 함수
//now는 말 그대로 현재 위치, count는 지금까지 오면서 지나온 거리(카운트)
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

	cout << counting(pair<int, int>(0,0),0) +1 << '\n'; // 도착지점까지 카운트

}
int counting(pair<int, int> now, int count)
{
	visited[now.first][now.second] = 1;
	if (now.first == N - 1 && now.second == M - 1)
	{
		if (minwalk > count) minwalk = count;
	}
	for (int i = 0; i < 4; i++) // 상하좌우 4번 이동
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