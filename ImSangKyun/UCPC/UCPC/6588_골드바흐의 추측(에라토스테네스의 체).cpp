#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_V = 1000001;
vector<int> primeNum(MAX_V, 0);

void eratosthenes() {
	primeNum[1] = 1;
	for (int i = 2; i*i < MAX_V; ++i)
		if (!primeNum[i])
			for (int j = i * i; j < MAX_V; j += i)
				primeNum[j] = 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	eratosthenes();
	int N;
	while (true) {
		cin >> N;
		if (!N)	break;
		bool isPrime = false;
		for(int i=3; i<=N; i+=2)
			if (!primeNum[i] && !primeNum[N - i]) {
				cout << N << " = " << i << " + " << N - i << '\n';
				isPrime = true;
				break;
			}
		if (!isPrime)
			cout << "Goldbach's conjecture is wrong." << '\n';
	}
}