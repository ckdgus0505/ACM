#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int scoring(vector<vector<int>>& player, vector<int>& batting, int N);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	int highest = 0;
	vector<vector<int>> player;
	vector<int> batting; // 타순을 저장하는 배열,
						// 1부터 8까지 저장되어 있고, 이 수는 선수 번호를 의미 & 4번 타자를 제외한 타순

	cin >> N;
	player.assign(N, vector<int>(9, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> player[i][j];
		}
	}

	for (int i = 1; i <= 8; i++) {
		batting.push_back(i);
	}
	highest = scoring(player, batting, N);
	while (next_permutation(batting.begin(), batting.end())) {
		int score = scoring(player, batting, N);
		if (highest < score) highest = score;
	}
	cout << highest << '\n';
}

int scoring(vector<vector<int>> &player, vector<int> &batting, int N) {
	int out = 0; int inning = 0; int score = 0;
	unsigned int base = 0;
	int play_count = 0;
	int now_batter = 0;
	while (inning < N) {
		// 타자 등판
		if ((play_count % 9) < 3) {
			now_batter = batting[play_count % 9];
		}
		else if (play_count % 9 == 3) {
			now_batter = 0;
		}
		else {
			now_batter = batting[(play_count % 9) - 1];
		}

		// 타자 타격
		switch (player[inning][now_batter]) {
		case 1: // 1루타
			base = base << 1;
			if (base>>3 & 1) { // 3루 주자가 홈으로 들어옴, 1점 증가
				base &= ~8;
				score++;
			}
			base |= 1; // 타자가 1루에 들어옴
			break;
		case 2: // 2루타
			base = base << 2;
			if (base >> 3 & 1) {
				base &= ~8;
				score++;
			}
			if (base >> 4 & 1) {
				base &= ~16;
				score++;
			}
			base |= 2; // 타자가 2루에 들어옴
			break;
		case 3: // 홈런
			base = base << 3;
			if (base >> 3 & 1) {
				base &= ~8;
				score++;
			}
			if (base >> 4 & 1) {
				base &= ~16;
				score++;
			}
			if (base >> 5 & 1) {
				base &= ~32;
				score++;
			}
			base |= 4; // 타자가 3루에 들어옴
			break;
		case 4: // 홈런
			if (base >> 0 & 1) {
				score++;
			}
			if (base >> 1 & 1) {
				score++;
			}
			if (base >> 2 & 1) {
				score++;
			}
			base = 0;
			score++;
			break;
		case 0: // 아웃
			out++; // 아웃 카운트가 올라간다.
			if (out == 3) { // 아웃 카운트가 3이 되면 다음 이닝으로 넘어갈 준비를 해 준다.
				inning++;
				out = 0;
				base = 0;
			}
			break;
		}
		play_count++;
	}
		return score;
}