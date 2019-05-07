#include<iostream>
#include<vector>
using namespace std;
void coloring();	// ���� ���� �� ������ ��ĥ�Ѵ�.
int max_color;	// ��ĥ�� ���� ��
int mix_color;	// ���� ���� ��
int w, h; // h�� w���� ���� ũ�⸦ �޴� ����
vector<vector<int>> map;
int adj[4][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};// ������ �� Ž���Ҷ� ����ϴ� vector // 4X2, 0: y, 1: x
vector<vector<int>> mixx_color;

int count_mixx_color();
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	while (true)
	{

		cin >> w >> h;
		if (w == 0 && h == 0) break; // w,h ��� 0�̸� break
		map.assign(h, vector<int>(w, 0));
		mixx_color.assign(625, vector<int>(625, 0));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int tmp;
				cin >> tmp;
				map[i][j] = -tmp; // 0, -1�� map�� ä��(-1�� ����)
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
		for (int j = 0; j < w; j++) // �� ���� Ž��
		{
			if (map[i][j] == -1) // ���� ���
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
				if (map[i][j] == -1) map[i][j] = ++max_color; ///�ֺ��� ���� ������ ���ο� ������ ä�� 
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