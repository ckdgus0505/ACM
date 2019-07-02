#include <iostream>
#include <vector>
using namespace std;

vector<int> st;
void outputnum(int a, int b); // ���� ������ش�. a�� ���� ��, b�� ���� ����ؾ� �� ��
int N, M; // N������ �� �� M���� �ߺ� ���� ��� ���������� ����
int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		if (N - i + 1 < M) break;
		st.push_back(i);
		outputnum(i+1, M-1);
		st.pop_back();
	}
}

void outputnum(int a, int b)
{
	if (b <= 0)
	{
		for (vector<int>::iterator iter = st.begin(); iter < st.end(); iter++)
		{
			cout << *iter << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = a; i <= N; i++)
	{
		if (N - a + 1 < b) break;
		st.push_back(i);
		outputnum(i + 1, b - 1);
		st.pop_back();
	}
}