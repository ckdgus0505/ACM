#include<iostream>
#include<vector>
using namespace std;
void coloring();	// 같은 섬을 한 색으로 색칠한다.
int max_color;	// 색칠한 색의 수
int mix_color;	// 섞인 색의 수
int w, h; // h행 w열의 지도 크기를 받는 변수
vector<vector<int>> map;
int adj[4][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};// 인접한 곳 탐색할때 사용하는 vector // 4X2, 0: y, 1: x
vector<vector<int>> mixx_color;

int count_mixx_color();
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	while (true)
	{

		cin >> w >> h;
		if (w == 0 && h == 0) break; // w,h 모두 0이면 break
		map.assign(h, vector<int>(w, 0));
		mixx_color.assign(625, vector<int>(625, 0));
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
		mix_color = 0;
		coloring();
		cout << max_color - count_mixx_color() << '\n';

	}
	return 0;
}
void coloring()
{
	for (int i = 0 ; i < h; i++)
	{
		for (int j = 0; j < w; j++) // 열 먼저 탐색
		{
			if (map[i][j] == -1) // 땅일 경우
			{
				int color_count = 0;
				for (int k = 0; k < 4; k++)
				{
					if ((i + adj[k][0] >= 0 && j + adj[k][1] >= 0 && j + adj[k][1] < w) && map[i + adj[k][0]] [j + adj[k][1]] > 0)
					{
						if (map[i][j] != map[i + adj[k][0]][j + adj[k][1]])
						{
							if (map[i][j] != -1)
							{
								mixx_color[map[i][j]][map[i + adj[k][0]][j + adj[k][1]]] = 1;
								mixx_color[map[i + adj[k][0]][j + adj[k][1]]][map[i][j]] = 1;
							}
							color_count++;
							map[i][j] = map[i + adj[k][0]][j + adj[k][1]];
						}

					}
					
				}
				if (map[i][j] == -1) map[i][j] = ++max_color; ///주변에 색이 없으면 새로운 색으로 채움 
				if (color_count > 1) mix_color++;
			}
		}
	}
}
int count_mixx_color()
{
	int sum = 0;
	for (int i = 0; i < 625; i++)
	{
		for(int j = 0; j < 625; j++)
		{
			sum += mixx_color[i][j];
		}
	}
	return sum / 2;
}