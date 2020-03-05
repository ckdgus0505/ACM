#include <iostream>
#include <vector>
#include <algorithm>
#define F(p,q,r) for(int p=q;p<r;p++)
using namespace std;

int main(void) {
	vector<vector<int>> v1 ={{5, 3}, { 11,5 }, { 13,3 }, { 3,5 }, { 6,1 }, { 1,3 }, { 8,6 }, { 7,2 }, { 2,2 }
};
	sort(v1.begin(), v1.end());

	F(x, 0, v1.size()) {
		F(y, 0, v1[0].size()) {
			cout << v1[x][y] << " ";
		}
		cout << "\n";
	}

	vector<vector<int>> depth(1001, vector<int>());

	F(x, 0, v1.size()) {
		depth[v1[x][1]].push_back(x);
	}
	// 해당 인덱스를 저장하자. x값이 아니다!!!

	cout << "hi\n";

	F(dep, 1, 14) {
		for(auto item : depth[dep]) {
			cout << item << " ";
		}
		cout << "\n";
	}

}