#include<iostream>
#include<vector>
#define R 0
#define B 1
#define G 2
#define Y 3
#define W 4
using namespace std;

int ****meterials;
//vector<vector<vector<vector<int>>>> meterials;
int*** newPot;
//vector<vector<vector<int>>> newPot;
int*** tmp;
int n;
int Max;



void turn90s(int*** meterial);
//void turn90s(vector<vector<vector<int>>>& meterial);
//vector<vector<vector<int>>> turn90s(int angle, const vector<vector<vector<int>>>& meterial);

void intoPot(int***& meterial1, int***& meterial2, int ***& meterial3);

//void intoPot(vector<vector<vector<int>>>& meterial1, vector<vector<vector<int>>>& meterial2, vector<vector<vector<int>>>& meterial3);
int getQuality(int*** & Pot);
//int getQuality(vector<vector<vector<int>>>& Pot);
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//newPot.assign(5, vector<vector<int>>(5, vector<int>(2, 0)));
	cin >> n;

	meterials = new int*** [n];
	for (int i = 0; i < n; i++)
	{
		meterials[i] = new int** [4];
		for (int j = 0; j < 4; j++)
		{
			meterials[i][j] = new int* [4];
			for (int k = 0; k < 4; k++)
			{
				meterials[i][j][k] = new int [2];
			}
		}
	}

	newPot = new int** [5];
	for (int i = 0; i < 5; i++)
	{
		newPot[i] = new int* [5];
		for (int j = 0; j < 5; j++)
		{
				newPot[i][j] = new int[2];
		}
	}

	tmp = new int** [4];
	for (int i = 0; i < 4; i++)
	{
		newPot[i] = new int* [4];
		for (int j = 0; j < 4; j++)
		{
			newPot[i][j] = new int[2];
		}
	}

	//meterials.assign(n, (vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(2, 0))))); // meterials[n][4][4][2], n은 재료 순서, [4][4]는 좌표, [2]는 재료의 효능과 원소


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int tmp;
				cin >> tmp;
				 meterials[i][j][k][0] = tmp;
			}
		}
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				char tmp;
				cin >> tmp;
				if (tmp == 'R')
					meterials[i][j][k][1] = R;
				else if (tmp == 'B')
					meterials[i][j][k][1] = B;
				else if (tmp == 'G')
					meterials[i][j][k][1] = G;
				else if (tmp == 'Y')
					meterials[i][j][k][1] = Y;
				else if (tmp == 'W')
					meterials[i][j][k][1] = W;
			}
		}
	}

	for (int a = 0; a < n-2; a++)
	{
		for (int b = a+1; b < n-1; b++)
		{
			for (int c = b+1; c < n; c++)
			{
				intoPot(meterials[a], meterials[b], meterials[c]);
				cout << a << ' ' << b << ' ' << c << ' ' << Max << '\n';
				intoPot(meterials[a], meterials[c], meterials[b]);
				intoPot(meterials[b], meterials[a], meterials[c]);
				intoPot(meterials[b], meterials[c], meterials[a]);
				intoPot(meterials[c], meterials[a], meterials[b]);
				intoPot(meterials[c], meterials[b], meterials[a]);
			}
		}
	}


	cout << Max << '\n';

}

void turn90s(int *** meterial)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tmp[j][3-i][0] = meterial[i][j][0];
			tmp[j][3-i][1] = meterial[i][j][1];
		}
	}

	meterial = tmp;
}

//void turn90s( vector<vector<vector<int>>>& meterial)
//{
//	vector<vector<vector<int>>> ret (4, vector<vector<int>>(4, vector<int>(2,0)));
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			ret[j][3 - i] = meterial[i][j];
//		}
//	}
//	meterial = ret;
//}


void intoPot(int ***& meterial1,int ***& meterial2, int ***& meterial3)
{

	for (int a = 0; a < 4; a++) // a는 meterial1의 회전하는 각도
	{
		for (int b = 0; b < 4; b++) // b는 meterial2의 회전하는 각도
		{
			for (int c = 0; c < 4; c++) // c는 meterial3의 회전하는 각도
			{
				for (int d = 0; d < 4; d++) // d는 meterial1을 넣을 위치
				{
					for (int e = 0; e < 4; e++) // e는 meterial2의 넣을 위치
					{
						for (int f = 0; f < 4; f++) // f는 meterial3의 넣을 위치
						{
							memset(newPot, 0, sizeof(newPot));
							turn90s(meterial1);
							turn90s(meterial2);
							turn90s(meterial3);

							for (int i = 0; i < 4; i++)
							{
								for (int j = 0; j < 4; j++)
								{
									newPot[d / 2 + i][d % 2 + j][0] += meterial1[i][j][0];
									newPot[d / 2 + i][d % 2 + j][1] = meterial1[i][j][1];

									newPot[e / 2 + i][e % 2 + j][0] += meterial2[i][j][0];
									if (newPot[e / 2 + i][e % 2 + j][0] < 0) newPot[e / 2 + i][e % 2 + j][0] = 0;
									else if (newPot[e / 2 + i][e % 2 + j][0] > 9) newPot[e / 2 + i][e % 2 + j][0] = 9;
									if (newPot[e / 2 + i][e % 2 + j][1] = !W)
										newPot[e / 2 + i][e % 2 + j][1] = meterial2[i][j][1];

									newPot[f / 2 + i][f % 2 + j][0] += meterial3[i][j][0];
									if (newPot[f / 2 + i][f % 2 + j][0] < 0) newPot[f / 2 + i][f % 2 + j][0] = 0;
									else if (newPot[f / 2 + i][f % 2 + j][0] > 9) newPot[f / 2 + i][f % 2 + j][0] = 9;
									if (newPot[f / 2 + i][f % 2 + j][1] = !W)
										newPot[f / 2 + i][f % 2 + j][1] = meterial3[i][j][1];

								}
							}
							int tmp = getQuality(newPot);
							if (Max < tmp)
								Max = tmp;
						}
					}
				}
			}
		}
	}
}
//void intoPot(vector<vector<vector<int>>>& meterial1, vector<vector<vector<int>>>& meterial2, vector<vector<vector<int>>>& meterial3)
//{
//
//	for (int a = 0; a < 4; a++) // a는 meterial1의 회전하는 각도
//	{
//		for (int b = 0; b < 4; b++) // b는 meterial2의 회전하는 각도
//		{
//			for (int c = 0; c < 4; c++) // c는 meterial3의 회전하는 각도
//			{
//				for (int d = 0; d < 4; d++) // d는 meterial1을 넣을 위치
//				{
//					for (int e = 0; e < 4; e++) // e는 meterial2의 넣을 위치
//					{
//						for (int f = 0; f < 4; f++) // f는 meterial3의 넣을 위치
//						{
//							newPot.assign(5, vector<vector<int>>(5, vector<int>(2, 0)));
//							turn90s(meterial1);
//							turn90s(meterial2);
//							turn90s(meterial3);
//
//							for (int i = 0; i < 4; i++)
//							{
//								for (int j = 0; j < 4; j++)
//								{
//									newPot[d / 2 + i][d % 2 + j][0] += meterial1[i][j][0];
//									newPot[d / 2 + i][d % 2 + j][1] = meterial1[i][j][1];
//
//									newPot[e / 2 + i][e % 2 + j][0] += meterial2[i][j][0];
//									if (newPot[e / 2 + i][e % 2 + j][0] < 0) newPot[e / 2 + i][e % 2 + j][0] = 0;
//									else if (newPot[e / 2 + i][e % 2 + j][0] > 9) newPot[e / 2 + i][e % 2 + j][0] = 9;
//									if (newPot[e / 2 + i][e % 2 + j][1] = !W)
//										newPot[e / 2 + i][e % 2 + j][1] = meterial2[i][j][1];
//
//									newPot[f / 2 + i][f % 2 + j][0] += meterial3[i][j][0];
//									if (newPot[f / 2 + i][f % 2 + j][0] < 0) newPot[f / 2 + i][f % 2 + j][0] = 0;
//									else if (newPot[f / 2 + i][f % 2 + j][0] > 9) newPot[f / 2 + i][f % 2 + j][0] = 9;
//									if (newPot[f / 2 + i][f % 2 + j][1] = !W)
//										newPot[f / 2 + i][f % 2 + j][1] = meterial3[i][j][1];
//
//								}
//							}
//							int tmp = getQuality(newPot);
//							if (Max < tmp)
//								Max = tmp;
//						}
//					}
//				}
//			}
//		}
//	}
//}

int getQuality(int***& Pot)
{
	int r = 0;;
	int b = 0;
	int g = 0;
	int y = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Pot[i][j][1] == R)
				r += Pot[i][j][0];
			else if (Pot[i][j][1] == B)
				b += Pot[i][j][0];
			else if (Pot[i][j][1] == G)
				g += Pot[i][j][0];
			else if (Pot[i][j][1] == Y)
				y += Pot[i][j][0];
		}
	}

	return (7 * r) + (5 * b) + (3 * g) + (2 * y);
}
//int getQuality(vector<vector<vector<int>>>& Pot)
//{
//	int r = 0;;
//	int b = 0;
//	int g = 0;
//	int y = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			if (Pot[i][j][1] == R)
//				r += Pot[i][j][0];
//			else if (Pot[i][j][1] == B)
//				b += Pot[i][j][0];
//			else if (Pot[i][j][1] == G)
//				g += Pot[i][j][0];
//			else if (Pot[i][j][1] == Y)
//				y += Pot[i][j][0];
//		}
//	}
//
//	return (7 * r) + (5 * b) + (3 * g) + (2 * y);
//}
//int getQuality_slow(vector<vector<vector<int>>>& Pot)
//{
//	int ret = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			if (Pot[i][j][1] == R)
//				ret += 7 * Pot[i][j][0];
//			else if (Pot[i][j][1] == B)
//				ret += 5 * Pot[i][j][0];
//			else if (Pot[i][j][1] == G)
//				ret += 3 * Pot[i][j][0];
//			else if (Pot[i][j][1] == Y)
//				ret += 2 * Pot[i][j][0];
//		}
//	}
//	return ret;
//}

//vector<vector<vector<int>>> turn90s(int angle, const vector<vector<vector<int>>>& meterial)
//{
//	vector<vector<vector<int>>> ret(4, vector<vector<int>>(4, vector<int>(2, 0)));
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (angle == 0)
//				ret[i][j] = meterial[i][j];
//			else if (angle == 1)
//				ret[j][3 - i] = meterial[i][j];
//			else if (angle == 2)
//				ret[3 - i][3 - j] = meterial[i][j];
//			else if (angle == 3)
//				ret[3 - j][i] = meterial[i][j];
//		}
//	}
//	return ret;
//}

//void intoPot(vector<vector<vector<int>>>& meterial1, vector<vector<vector<int>>>& meterial2, vector<vector<vector<int>>>& meterial3)
//{
//	vector<vector<vector<int>>> newPot;
//	for (int a = 0; a < 4; a++) // a는 meterial1의 회전하는 각도
//	{
//		for (int b = 0; b < 4; b++) // b는 meterial2의 회전하는 각도
//		{
//			for (int c = 0; c < 4; c++) // c는 meterial3의 회전하는 각도
//			{
//				for (int d = 0; d < 4; d++) // d는 meterial1을 넣을 위치
//				{
//					for (int e = 0; e < 4; e++) // e는 meterial2의 넣을 위치
//					{
//						for (int f = 0; f < 4; f++) // f는 meterial3의 넣을 위치
//						{
//							newPot.assign(5, vector<vector<int>>(5, vector<int>(2, 0)));
//							vector<vector<vector<int>>> tmp1(4, vector<vector<int>>(4, vector<int>(2, 0)));
//							vector<vector<vector<int>>> tmp2(4, vector<vector<int>>(4, vector<int>(2, 0)));
//							vector<vector<vector<int>>> tmp3(4, vector<vector<int>>(4, vector<int>(2, 0)));
//							tmp1 = turn90s(a, meterial1);
//							tmp2 = turn90s(b, meterial2);
//							tmp3 = turn90s(c, meterial3);
//
//							for (int i = 0; i < 4; i++)
//							{
//								for (int j = 0; j < 4; j++)
//								{
//									newPot[d / 2 + i][d % 2 + j][0] += tmp1[i][j][0];
//									if (newPot[d / 2 + i][d % 2 + j][0] < 0) newPot[d / 2 + i][d % 2 + j][0] = 0;
//									else if (newPot[d / 2 + i][d % 2 + j][0] > 9) newPot[d / 2 + i][d % 2 + j][0] = 9;
//									if (newPot[d / 2 + i][d % 2 + j][1] = !W)
//										newPot[d / 2 + i][d % 2 + j][1] = tmp1[i][j][1];
//
//									newPot[e / 2 + i][e % 2 + j][0] += tmp2[i][j][0];
//									if (newPot[e / 2 + i][e % 2 + j][0] < 0) newPot[d / 2 + i][d % 2 + j][0] = 0;
//									else if (newPot[e / 2 + i][e % 2 + j][0] > 9) newPot[d / 2 + i][d % 2 + j][0] = 9;
//									if (newPot[e / 2 + i][e % 2 + j][1] = !W)
//										newPot[e / 2 + i][e % 2 + j][1] = tmp2[i][j][1];
//
//									newPot[f / 2 + i][f % 2 + j][0] += tmp3[i][j][0];
//									if (newPot[f / 2 + i][f % 2 + j][0] < 0) newPot[d / 2 + i][d % 2 + j][0] = 0;
//									else if (newPot[f / 2 + i][f % 2 + j][0] > 9) newPot[d / 2 + i][d % 2 + j][0] = 9;
//									if (newPot[f / 2 + i][f % 2 + j][1] = !W)
//										newPot[f / 2 + i][f % 2 + j][1] = tmp3[i][j][1];
//								}
//							}
//							int tmp = getQuality(newPot);
//							if (Max < tmp)
//								Max = tmp;
//						}
//					}
//				}
//			}
//		}
//	}
//}