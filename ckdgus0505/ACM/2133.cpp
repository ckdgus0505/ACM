#include<iostream>
using namespace std;
int f(int);
int g(int);

int main(void)
{
	int N;

	cin >> N;

	cout << f(N);

}
int f(int n)
{
	if (n == 1) return 0;
	else if (n == 2) return 3;
	else return g(n) + f(n - 2) * 2 + g(n - 2);

}
int g(int n)
{
	if (n == 1) return 0;
	if (n == 2) return 1;
	else return f(n - 2) + g(n - 2);
}