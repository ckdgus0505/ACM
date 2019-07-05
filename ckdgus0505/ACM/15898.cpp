#include<iostream>
#include<vector>

using namespace std;

vector<vector<vector<int>>> pot; // po[a][b][c]��� �ϸ� a,b�� ��ǥ, c�� ����, ���Ҵ� 0���� ���ʴ�� RBGY
vector<vector<vector<vector<int>>>> elements;
int n; //  ����� ��
int Max = -1; // �ִ� ǰ��

int quality(vector<vector<vector<int>>>& pot);
vector<vector<vector<int>>> turn90(int angle, vector<vector<vector<int>>> &meterial);
void intoPot();
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	pot.assign(5, vector<vector<int>> (5, vector<int>(4, 0)));// [a][b][c]�� �ϸ�, a,b�� ��ǥ, c�� ������ ����
	elements.assign(n, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4, 0))));// [a][b][c][d]�� �ϸ�, a�� ���, b, c�� ��ǥ, d�� ������ ����


	for (int i = 0; i < n; i++)
	{

		vector<vector<int>> tmp1(4, vector<int>(4, 0));
		vector<vector<char>> tmp2(4, vector<char>(4, ' '));
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cin >> tmp1[j][k];
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cin >> tmp2[j][k];
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (tmp2[j][k] == 'R') elements[i][j][k][0] = tmp1[j][k];
				else if (tmp2[j][k] == 'B') elements[i][j][k][1] = tmp1[j][k];
				else if (tmp2[j][k] == 'G') elements[i][j][k][2] = tmp1[j][k];
				else if (tmp2[j][k] == 'Y') elements[i][j][k][3] = tmp1[j][k];
			}
		}
	}
	intoPot();
	cout << Max << '\n';
}
int quality(vector<vector<vector<int>>>& pot)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (k == 0 && pot[i][j][k]>0) sum += 7 * pot[i][j][k];
				else if (k == 1 && pot[i][j][k] > 0) sum += 5 * pot[i][j][k];
				else if (k == 2 && pot[i][j][k] > 0) sum += 3 * pot[i][j][k];
				else if (k == 3 && pot[i][j][k] > 0) sum += 2 * pot[i][j][k];
			}
		}
	}

	return sum;
}
vector<vector<vector<int>>> turn90(int angle, vector<vector<vector<int>>> &meterial)
{
	vector<vector<vector<int>>> ret(4, vector<vector<int>>(4, vector<int>(4, 0)));
	if (angle % 2 == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (angle == 0)
					ret[i][j] = meterial[i][j];
				else if (angle == 1)
					ret[i][3 - j] = meterial[i][j];
				else if (angle == 2)
					ret[3 - i][3 - j] = meterial[i][j];
				else if (angle == 3)
					ret[3 - i][j] = meterial[i][j];
			}
		}
	}
	return ret;
}
void intoPot()
{

	for (int i = 0; i < n - 2; i++) // i,j,k�� meterial
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				for (int l = 0; l < 4; l++) // l,m,n�� pot�� ��ġ...
				{
					for (int m = 0; m < 4; m++)
					{
						for (int n = 0; n < 4; n++)
						{
							for (int p = 0; p < 4; p++) // p,q,r�� ȸ��...
							{
								for (int q = 0; q < 4; q++)
								{
									for (int r = 0; r < 4; r++)
									{
										for (int a = 0; a < 4; a++)
										{
											for (int b = 0; b < 4; b++)
											{
												vector<vector<vector<int>>> newPot(5, vector<vector<int>>(5, vector<int>(4, 0)));
												int tmp;
												for (int c = 0; c < 4; c++)
												{

													newPot[a + l / 2][b + l % 2][c] += turn90(p, elements[i])[a][b][c];
													newPot[a + m / 2][b + m % 2][c] += turn90(q, elements[i])[a][b][c];
													newPot[a + n / 2][b + n % 2][c] += turn90(r, elements[i])[a][b][c];

												}
												tmp = quality(newPot);
												if (Max < tmp) Max = tmp;
												cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << ' ' << n << ' ' << p << ' ' << q << ' ' << r << ' ' << Max << '\n';
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}