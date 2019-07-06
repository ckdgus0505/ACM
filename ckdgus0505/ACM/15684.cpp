#include<iostream>
#include<vector>
using namespace std;
int N, M, H; // 각각 세로선 개수, 가로선 개수, 세로선마다 가로선을 놓을 수 있는 위치의 개수
vector < vector<int>> ledder; // arr[a][b], a는 가로선, b는 세로선
int trace(int a, vector<vector<int>> ledder2); // 사다리 타고 내려갔을때 나오는 값 반환하는 함수
bool ordered(vector<vector<int>> ledder2); // 사다리타고 내려왔을때 그대로면 true 반환해주는 함수
void add_trial(int a, vector<vector<int>> tmpled); // 가로 사다리 집어넣는 함수 , a는 사다리 남은 추가 횟수, 추가한 양 만큼 반환
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
		cin >> tmp1 >> tmp2;  // tmp2는 세로선, tmp1은 가로선
		ledder[tmp1-1][tmp2-1] = 1; // 0번부터...
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