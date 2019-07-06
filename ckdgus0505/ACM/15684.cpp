#include<iostream>
#include<vector>
using namespace std;
int N, M, H; // ���� ���μ� ����, ���μ� ����, ���μ����� ���μ��� ���� �� �ִ� ��ġ�� ����
vector < vector<int>> ledder; // arr[a][b], a�� ���μ�, b�� ���μ�
int trace(int a, vector<vector<int>> ledder2); // ��ٸ� Ÿ�� ���������� ������ �� ��ȯ�ϴ� �Լ�
bool ordered(vector<vector<int>> ledder2); // ��ٸ�Ÿ�� ���������� �״�θ� true ��ȯ���ִ� �Լ�
void add_trial(int a, vector<vector<int>> tmpled); // ���� ��ٸ� ����ִ� �Լ� , a�� ��ٸ� ���� �߰� Ƚ��, �߰��� �� ��ŭ ��ȯ
int ans = -1;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> H;
	ledder.assign(H, vector<int>(N-1, 0));

	for (int i = 0; i < M; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;  // tmp2�� ���μ�, tmp1�� ���μ�
		ledder[tmp1-1][tmp2-1] = 1; // 0������...
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			cout << ledder[i][j] << ' ';
		}
		cout << '\n';
	}

	add_trial(3, ledder);

	cout << ans << '\n';
}
int trace(int a, vector<vector<int>> ledder2)
{
	int ret = a;
	if (ret < 0 || ret >= N) return -1;

	for (int i = 0; i < H; i++)
	{
		if (ret < N-1 && ledder2[i][ret] == 1)
			ret += 1;
		else if (ret - 1 >= 0 && ledder2[i][ret - 1] == 1)
			ret -= 1;
	}
	return ret;
}
bool ordered(vector<vector<int>> ledder2)
{
	for (int i = 0; i < N; i++)
	{
		if (trace(i, ledder2) != i)
			return false;
	}
	return true;
}
void add_trial(int a, vector<vector<int>> tmpled)
{
	vector<vector<int>> tmp = tmpled;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (tmp[i][j] == 0)
			{
				tmp[i][j] = 1;
				add_trial(a - 1, tmp);
				tmp[i][j] = 0;
			}
		}
	}
}