#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define F(p,q,r) for(int p = q;p<r; p++)

int main(){
	int N;
	cin >> N;
	vector<int> oranges(N, 0);
	F(idx, 0, N) {
		cin >> oranges[idx];
	}



	return 0;
}

//7
//- 7 7 1 - 6 4 9 8
//23

//3
//- 2 6 - 1
//6

//7
//- 9 - 3 8 - 6 - 9 - 9 10
//10