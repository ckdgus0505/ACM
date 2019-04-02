#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> A; // N*M 크기 행렬
vector<vector<int>> B; // M*K 크기 행렬
vector<vector<int>> C; // 결과를 저장하는 행렬
int N, M, K;
void arrMul(int n, int k ,int as, int ae, int bs, int be) // as, ae는 a행렬의 행의 시작과 끝, 마지막 미포함
{																		// b는 열의 시작과 끝, 마지막 미포함


	if (n == 1 && k == 1)
	{
		int tmp = 0;
		for (int i = 0; i < M; i++)
		{
			tmp += A[as][i] * B[i][bs];
		}
		C[as][bs] = tmp;
	}
	else
	{
		if (n > 1 && n % 2 == 0)
		{
			arrMul(n / 2, k, as, as + (n / 2), bs, be);
			arrMul(n / 2, k, as + (n / 2), ae, bs, be);
		}
		else if (n > 1 && n % 2 == 1)
		{
			arrMul(1, k, as, as + 1, bs, be);
			arrMul((n - 1) / 2, k, as + 1, as + 1 + (n - 1) / 2, bs, be);
			arrMul((n - 1) / 2, k, as + 1 + (n - 1) / 2, ae, bs, be);
		}

		if (k > 1 &&k % 2 == 0)
		{
			arrMul(n, k / 2, as, ae, bs, bs + (k / 2));
			arrMul(n, k / 2, as, ae, bs + (k / 2), be);
		}
		else if (k > 1 && k % 2 == 1)
		{
			arrMul(n, 1, as, ae, bs, bs + 1);
			arrMul(n, (k - 1) / 2, as, ae, bs + 1, bs + 1 + (k - 1) / 2);
			arrMul(n, (k - 1) / 2, as, ae, bs + 1 + (k - 1) / 2, be);
		}
	}
}

int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	A.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}
	cin >> M >> K;
	B.assign(M, vector<int>(K, 0));
	C.assign(N, vector<int>(K, 0));

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> B[i][j];
		}
	}

	arrMul(N, K, 0, N, 0, K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << C[i][j] << ' ';
		}
		cout << '\n';
	}

}