#include<iostream>
#include<vector>
using namespace std;

int n, m; // n : �� �� m : ���� ��
int cnt;

vector<vector<int>> adj; // �������
vector<int> stack; // ��� �����ϴ� stack
void goNext(int a); // a���� n-1�� ���� �Լ�
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	adj.assign(n+1, vector<int>(n+1, 0));

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a < b) adj[a][b] = c;
		else adj[b][a] = c;
	}

	stack.push_back(1);
	goNext(1);
	cout << cnt << '\n';
}

void goNext(int a)
{
	int minWeight;
	if (a == n)
	{
		for (int i = 0; i < stack.size(); i++)
		{
			if (i < stack.size() - 1 && minWeight > adj[stack[i]][stack[i+1]]) minWeight = adj[stack[i]][stack[i + 1]];
		}
		for (int i = 0; i < stack.size(); i++)
		{
			if (i < stack.size() - 1 && minWeight > adj[stack[i]][stack[i + 1]]) adj[stack[i]][stack[i + 1]] -= minWeight;
		}
		cnt += minWeight;
		return;
	}
	else
	{
		for (int i = a+1; i <= n; i++)
		{
			if (adj[a][i] > 0) {

				stack.push_back(i);
				goNext(i);
				stack.pop_back();
			}
		}
	}
}