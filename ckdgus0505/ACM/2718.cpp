#include<iostream>
#include<cstring>
using namespace std;
int cacheF[1001]; // F의 결과값을 담는 캐쉬
int cacheG[1001]; // G의 결과값을 담는 캐쉬
int cacheH[1001]; // H의 결과값을 담는 캐쉬

int F(int);
int G(int);
int H(int);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(cacheF, -1, sizeof(cacheF));
	memset(cacheG, -1, sizeof(cacheG));
	memset(cacheH, -1, sizeof(cacheH));

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		cout << F(tmp)<<'\n';
	}
	return 0;
}


int F(int n)
{
	if (n < 1) return 0;
	if (n == 1) return 1;
	if (n == 2) return 5;
	
	int& ret = cacheF[n];
	if (ret != -1) return ret;
		
	ret = F(n - 1) + (2 * F(n - 2)) + G(n - 1) + G(n - 2) + H(n - 1);

	return ret;

}
int G(int n)
{
	if (n < 1) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;

	int& ret = cacheG[n];
	if (ret != -1) return ret;
		
	ret = F(n - 1) + G(n - 1);

	return ret;
}
int H(int n)
{
	if (n < 1) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;

	int& ret = cacheH[n];
	if (ret != -1) return ret;
	
	ret = F(n - 1) + H(n - 2);

	return ret;
}