#include<iostream>
#include<vector>
using namespace std;
void visiting(int, int);	// ���� ���� �� ������ ��ĥ�Ѵ�.
int max_color;	// ��ĥ�� ���� ��
int w, h; // h�� w���� ���� ũ�⸦ �޴� ����
vector<vector<int>> map;
int adj[8][2] = { {-1, 0}, {-1, 1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0, -1}, {-1, -1} };// ������ �� Ž���Ҷ� ����ϴ� vector // 4X2, 0: y, 1: x
vector<vector<int>> visited; // �湮�� ���� ǥ�����ִ� ����

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	while (true)
	{

		cin >> w >> h;
		if (w == 0 && h == 0) break; // w,h ��� 0�̸� break
		map.assign(h, vector<int>(w, 0));
		visited.assign(h, vector<int>(w, 0));
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
		visiting();
		cout << max_color << '\n';

	}
	return 0;
}
void visiting(int nowY, int nowX)
{
	for (int i = 0 ; i < h; i++)
	{
		for (int j = 0; j < w; j++) // �� ���� Ž��
		{
			if (map[i][j] == -1) // ���� ���
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