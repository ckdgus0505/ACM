#include<iostream>
#include<vector>
using namespace std;

int n, m; // n : �� �� m : ���� ��
int cnt;
vector<vector<int>> adj; // �������
bool chk();
void goNext(int a, int b); // a���� b�� ���� �Լ�
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
		adj[a][b] = c;
		adj[b][a] = c;
	}

	//for (int i = 0; i <= n; i++)
	//{
	//	for (int j = 0; j <= n; j++)
	//	{
	//		cout << adj[i][j];
	//	}

	//	cout << '\n';
	//}

	goNext();
}
bool chk()
{
	int tmpsum = 0;
	for (int i = 0; i <= n; i++)
		tmpsum += adj[1][i];
	if (tmpsum == 0)
		return true;
	else return false;
}
void goNext(int a, int b)
{
	if(adj[a][b] >0)
		goNext


}