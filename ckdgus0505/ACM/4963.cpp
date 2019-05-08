#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
void visiting();
int count_island; // 방문한 섬을 세는 변수
int w, h; // h행 w열의 지도 크기를 받는 변수

int adj[8][2] = { {-1, 0}, {-1, 1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0, -1}, {-1, -1} };// 인접한 곳 탐색할때 사용하는 vector // 8X2, 0: y, 1: x
int visited[50][50]; // 방문한 섬을 표시해주는 벡터
int map[50][50]; // 지도!
queue<pair<int, int>> visit_queue; // 방문해야할 지점을 담는 큐, pair의 first가 y축, second가 x축

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true)
	{

		cin >> w >> h;
		if (w == 0 && h == 0) break; // w,h 모두 0이면 break
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(map));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int tmp;
				cin >> tmp;
				map[i][j] = tmp; // 0, 1로 map을 채움(1이 땅임)
			}
		}
		count_island = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == 0)
				{
					visit_queue.push(pair<int, int>(i, j));
					visiting();
				}
			}
		}
		cout << count_island << '\n';
	}
	return 0;
}
void visiting()
{
	while (!visit_queue.empty())
	{
		pair<int, int> now = visit_queue.front();
		visit_queue.pop();
		for (int k = 0; k < 8; k++) // 상하좌우대각선 8방향을 탐색한다.
		{
			int newY = now.first + adj[k][0]; // 새로운 y 
			int newX = now.second + adj[k][1]; // 새로운 x
			if (0 <= newX && newX < w && 0 <= newY &&  newY < h) // 지도 밖을 벗어나지 않는 범위
			{
				if (map[newY][newX] == 1 && visited[newY][newX] == 0) // 옆에있는곳이 섬이고, 안간곳이면
				{
					visited[newY][newX] = 1; // 방문할 곳 다시 큐에 안 넣도록
					visit_queue.push(pair<int, int>(newY, newX)); // 새로운 y,x를 방문할 예정인 큐에 넣음
				}
			}
		}
	}
	count_island++; // while 문이 끝나면 이어져있는 섬은 다 돈것이므로.. 섬의 갯수 1 증가
}