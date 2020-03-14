#include <iostream>
#include <vector>
#include <algorithm>
#define F(p,q,r) for(int p=q; p<r; p++)
using namespace std;


int calculate_cost(vector<int> & shieldarr, vector<int>& numbers) {
	
	int start = 0;
	int result = 0;
	F(s_idx, 0, shieldarr.size()) {
		if (shieldarr[s_idx] == 1) {
			result += numbers[s_idx] - numbers[start];
			start = s_idx + 1;
		}
	}

	return result;
}

int solution(int N, int K, vector<int> numbers) {
	int answer = 99999999;

	vector<int> shieldarr;

	F(idx, 0, (K - 1)) {
		shieldarr.push_back(1);
	}

	F(fidx, 0, ((N - 1) - (K - 1))) {
		shieldarr.push_back(0);
	}

	sort(shieldarr.begin(), shieldarr.end());
	do {
		int result = calculate_cost(shieldarr, numbers);
		
		if (answer > result) {
			answer = result;
		}


	} while (next_permutation(shieldarr.begin(), shieldarr.end()));

	return answer;
}



int main() {

	Input(N, K, numbers);
	int N;
	int K;
	cin >> N;
	cin >> K;
	vector<int > numbers(N, 0);

	F(idx, 0, N) {
		cin >> numbers[idx];
	}
	//cout << solution(N, K, numbers);
	vector<int> sh = { 0,0,0,1 , 1 };
	vector<int> numbers2 = { 4,8,15,16,23,42 };
	cout <<calculate_cost(sh, numbers2);

	return 0;
}