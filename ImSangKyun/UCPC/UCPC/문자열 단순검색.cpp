#include <iostream>
#include <vector>
#include <string>
using namespace std;

//문자열 검색 알고리즘 : 특정 문자열을 포함하는지 확인 후 포함하는 시작위치를 찾는 알고리즘

vector<int> nativeSearch(const string& H, const string& N) {
	vector<int> ret;
	for (int begin = 0; begin + N.size() <= H.size(); ++begin) {
		bool matched = true;
		for (int i = 0; i < N.size(); ++i) {
			if (H[begin + i] != N[i]) {
				matched = false;
				break;
			}
		}
		if (matched)	ret.push_back(begin);
	}
	return ret;
}

//여기서 KMP(Knuth-Morris-Pratt) 알고리즘을 적용하면 더 빠르게 검색한다. (커누스-모리스-프랫 알고리즘 이라고 부름)


int main(void) {

}