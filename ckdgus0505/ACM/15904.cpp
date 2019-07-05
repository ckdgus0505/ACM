#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<char> str; // �Է� ���ڿ��� �޴� ����
vector<char> UCPC; // UPCP�� �����ϰ� �ִ� ����

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	str.assign(1000, 0);
	UCPC.assign(4, 0);
	UCPC[0] = 'U';
	UCPC[1] = 'C';
	UCPC[2] = 'P';
	UCPC[3] = 'C';

	for (int i = 0; i < 1000; i++)
	{
		char tmp;
		scanf("%1c", &tmp);
		if (tmp == '\n')
			break;
		 else str[i] = tmp;
	}

	int k = 0; // k�� UCPC�� iter
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == UCPC[k])
			k++;
		if (k == 4) break;
	}

	if (k == 4)
		cout << "I love UCPC\n";
	else
		cout << "I hate UCPC\n";
}