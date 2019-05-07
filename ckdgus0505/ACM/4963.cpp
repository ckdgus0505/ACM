#include<iostream>
#include<vector>
using namespace std;
void visiting(int, int);	// 같은 섬을 한 색으로 색칠한다.
int max_color;	// 색칠한 색의 수
int w, h; // h행 w열의 지도 크기를 받는 변수
vector<vector<int>> map;
int adj[8][2] = { {-1, 0}, {-1, 1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0, -1}, {-1, -1} };// 인접한 곳 탐색할때 사용하는 vector // 4X2, 0: y, 1: x
vector<vector<int>> visited; // 방문한 섬을 표시해주는 벡터

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	while (true)
	{

		cin >> w >> h;
		if (w == 0 && h == 0) break; // w,h 모두 0이면 break
		map.assign(h, vector<int>(w, 0));
		visited.assign(h, vector<int>(w, 0));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int tmp;
				cin >> tmp;
				map[i][j] = -tmp; // 0, -1로 map을 채움(-1이 땅임)
			}
		}
		max_color = 0;
		visiting();
		cout << max_color << '\n';

	}
	return 0;
}
void visiting(int nowY, int nowX)
{
	for (int i = 0 ; i < h; i++)
	{
		for (int j = 0; j < w; j++) // 열 먼저 탐색
		{
			if (map[i][j] == -1) // 땅일 경우
			{
				int ny, nx; // nextX, nextY
				visited[i][j] = 1;
				for (int k = 0; k < 8; k++)
				{
					ny = adj[k][0];
					nx = adj[k][1];
					if (0 <= j + nx && j + nx < w && 0 <= i +  ny && i + ny < h)
					{
						if (map[i + ny][j + nx] == -1 && visited[i + ny][j + nx] != 1)
						{
							coloring(i + ny, j + nx);
						}
					}

				}
			}
		}
	}
}