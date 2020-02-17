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
	vector<int> batting; // Ÿ���� �����ϴ� �迭,
						// 1���� 8���� ����Ǿ� �ְ�, �� ���� ���� ��ȣ�� �ǹ� & 4�� Ÿ�ڸ� ������ Ÿ��

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
		// Ÿ�� ����
		if ((play_count % 9) < 3) {
			now_batter = batting[play_count % 9];
		}
		else if (play_count % 9 == 3) {
			now_batter = 0;
		}
		else {
			now_batter = batting[(play_count % 9) - 1];
		}

		// Ÿ�� Ÿ��
		switch (player[inning][now_batter]) {
		case 1: // 1��Ÿ
			base = base << 1;
			if (base>>3 & 1) { // 3�� ���ڰ� Ȩ���� ����, 1�� ����
				base &= ~8;
				score++;
			}
			base |= 1; // Ÿ�ڰ� 1�翡 ����
			break;
		case 2: // 2��Ÿ
			base = base << 2;
			if (base >> 3 & 1) {
				base &= ~8;
				score++;
			}
			if (base >> 4 & 1) {
				base &= ~16;
				score++;
			}
			base |= 2; // Ÿ�ڰ� 2�翡 ����
			break;
		case 3: // Ȩ��
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
			base |= 4; // Ÿ�ڰ� 3�翡 ����
			break;
		case 4: // Ȩ��
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
		case 0: // �ƿ�
			out++; // �ƿ� ī��Ʈ�� �ö󰣴�.
			if (out == 3) { // �ƿ� ī��Ʈ�� 3�� �Ǹ� ���� �̴����� �Ѿ �غ� �� �ش�.
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