#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char a[4], b[4], A[4], B[4];
	
	scanf("%s", &a);
	scanf("%s", &b);
	for (int i = 0; i < 3; i++)
	{
		A[2-i] = a[i];
		B[2-i] = b[i];
	}
	A[3] = '\0';
	B[3] = '\0';
	
	if (atoi(A) > atoi(B)) cout << A;
	else cout << B;
	
}
