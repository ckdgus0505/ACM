#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
void visiting();
int count_island; // �湮�� ���� ���� ����
int w, h; // h�� w���� ���� ũ�⸦ �޴� ����

int adj[8][2] = { {-1, 0}, {-1, 1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0, -1}, {-1, -1} };// ������ �� Ž���Ҷ� ����ϴ� vector // 8X2, 0: y, 1: x
int visited[50][50]; // �湮�� ���� ǥ�����ִ� ����
int map[50][50]; // ����!
queue<pair<int, int>> visit_queue; // �湮�ؾ��� ������ ��� ť, pair�� first�� y��, second�� x��

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true)
	{

		cin >> w >> h;
		if (w == 0 && h == 0) break; // w,h ��� 0�̸� break
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(map));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int tmp;
				cin >> tmp;
				map[i][j] = tmp; // 0, 1�� map�� ä��(1�� ����)
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
		for (int k = 0; k < 8; k++) // �����¿�밢�� 8������ Ž���Ѵ�.
		{
			int newY = now.first + adj[k][0]; // ���ο� y 
			int newX = now.second + adj[k][1]; // ���ο� x
			if (0 <= newX && newX < w && 0 <= newY &&  newY < h) // ���� ���� ����� �ʴ� ����
			{
				if (map[newY][newX] == 1 && visited[newY][newX] == 0) // �����ִ°��� ���̰�, �Ȱ����̸�
				{
					visited[newY][newX] = 1; // �湮�� �� �ٽ� ť�� �� �ֵ���
					visit_queue.push(pair<int, int>(newY, newX)); // ���ο� y,x�� �湮�� ������ ť�� ����
				}
			}
		}
	}
	count_island++; // while ���� ������ �̾����ִ� ���� �� �����̹Ƿ�.. ���� ���� 1 ����
}