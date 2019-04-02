#include<iostream>
#include<vector>
using namespace std;
pair<int, int>  point; //한 점을 의미함 (x, y)
vector<pair<int, int>> arr; // vector 안에 pair 로 점을 넣을 예정임

int n;

int find_nearest_point(int n) // n은 기준(n,0) 인 직선
{


	find_nearest_point(n/2)
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		arr.push_back(make_pair(x,y));
	}


}