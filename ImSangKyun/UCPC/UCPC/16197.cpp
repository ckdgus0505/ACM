#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> board;//0:ºóÄ­, 1:º®
pair<int, int> coin1, coin2;//Y, X
enum direct { left, right, up, down};

//¹Ý·Ê¸¦ Ã£¾Æ¾ß ÇÏ´À´Ï¶ó... ¿ÖÆ²¸®Áö

void move(direct d, bool& mCoin1, bool& mCoin2, bool rev=false) {
	//0:ºóÄ­, 1:º®
	if (!rev) {
		if (d == direct::left) {
			if (coin1.second - 1 >= 0 && board[coin1.first][coin1.second - 1] == 1) {
				mCoin1 = false;
			}
			else {
				coin1.second -= 1;
				mCoin1 = true;
			}
			if (coin2.second - 1 >= 0 && board[coin2.first][coin2.second - 1] == 1) {
				mCoin2 = false;
			}
			else {
				coin2.second -= 1;
				mCoin2 = true;
			}
		}
		if (d == direct::right) {
			if (coin1.second + 1 < M && board[coin1.first][coin1.second + 1] == 1) {
				mCoin1 = false;
			}
			else {
				coin1.second += 1;
				mCoin1 = true;
			}
			if (coin2.second + 1 < M && board[coin2.first][coin2.second + 1] == 1) {
				mCoin2 = false;
			}
			else {
				coin2.second += 1;
				mCoin2 = true;
			}
		}
		if (d == direct::down) {
			if (coin1.first - 1 >= 0 && board[coin1.first - 1][coin1.second] == 1) {
				mCoin1 = false;
			}
			else {
				coin1.first -= 1;
				mCoin1 = true;
			}
			if (coin2.first - 1 >= 0 && board[coin2.first - 1][coin2.second] == 1) {
				mCoin2 = false;
			}
			else {
				coin2.first -= 1;
				mCoin2 = true;
			}
		}
		if (d == direct::up) {
			if (coin1.first + 1 < N && board[coin1.first + 1][coin1.second] == 1) {
				mCoin1 = false;
			}
			else {
				coin1.first += 1;
				mCoin1 = true;
			}
			if (coin2.first + 1 < N && board[coin2.first + 1][coin2.second] == 1) {
				mCoin2 = false;
			}
			else {
				coin2.first += 1;
				mCoin2 = true;
			}
		}
	}
	else {
		if (d == direct::left) {
			if(mCoin1)
				coin1.second += 1;
			if (mCoin2)
				coin2.second += 1;
		}
		if (d == direct::right) {
			if(mCoin1)
				coin1.second -= 1;
			if (mCoin2)
				coin2.second -= 1;
		}
		if (d == direct::down) {
			if(mCoin1)
				coin1.first += 1;
			if (mCoin2)
				coin2.first += 1;
		}
		if (d == direct::up) {
			if(mCoin1)
				coin1.first -= 1;
			if (mCoin2)
				coin2.first -= 1;
		}
	}
}

int confirm() {
	int cnt = 0;
	if (coin1.first <0 || coin1.second < 0 || coin1.first > N - 1 || coin1.second > M - 1) 
		++cnt;
	if (coin2.first <0 || coin2.second < 0 || coin2.first > N - 1 || coin2.second > M - 1)
		++cnt;
	if (cnt == 1)	return 1;
	if (cnt == 2)	return 2;
	return 0;
	
}

int func(direct now, int cnt) {
	if (cnt > 10)	return 9999;

	bool mCoin1, mCoin2;

	move(now, mCoin1, mCoin2);
	int confval = confirm();
	if (confval == 1) {
		move(now, mCoin1, mCoin2, true);
		return cnt;
	}
	else if (confval == 2) {
		move(now, mCoin1, mCoin2, true);
		return 9999;
	}

	
	int res = 9999;

	if(coin1.second > -1 && coin2.second > -1)
		res = min(res, func(direct::left, cnt + 1));
	else {
		move(now, mCoin1, mCoin2, true);
		return 9999;
	}
		
	if(coin1.second < N && coin2.second < N)
		res = min(res, func(direct::right, cnt + 1));
	else {
		move(now, mCoin1, mCoin2, true);
		return 9999;
	}

	if(coin1.first > -1 && coin2.first > -1)
		res = min(res, func(direct::up, cnt + 1));
	else {
		move(now, mCoin1, mCoin2, true);
		return 9999;
	}

	if(coin1.first < N && coin2.first < N)
		res = min(res, func(direct::down, cnt + 1));
	else {
		move(now, mCoin1, mCoin2, true);
		return 9999;
	}
	
	move(now, mCoin1, mCoin2, true);
	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool bCoin1 = true;
	char val;
	coin1.first = coin1.second = coin2.first = coin2.second = -1;


	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>(M, 0));	//0:ºóÄ­, 1:º®, 2: µ¿Àü
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> val;
			switch (val) {
			case '.':
				board[i][j] = 0;
				break;
			case '#':
				board[i][j] = 1;
				break;
			case 'o':
				if (bCoin1) { 
					coin1.first = i;
					coin1.second = j;
					bCoin1 = false;
				}
				else {
					coin2.first = i;
					coin2.second = j;
				}
				break;
			default :
				cout << "INPUT ERROR" << '\n';
				break;
			}
		}
	}
	if (coin2.first == -1 && coin2.second == -1) {	//µ¿Àü ÀÔ·Â 1°³ (°ãÃÄ¼­ ³õÀ»°¡´É¼º)
		coin2.first = coin1.first;
		coin2.second = coin1.second;
	}
	


	int res = 9999;
	res = min(res, func(direct::left, 1));
	res = min(res, func(direct::right, 1));
	res = min(res, func(direct::up, 1));
	res = min(res, func(direct::down, 1));
	if (res == 9999) {
		cout << -1 << '\n';
	}
	else {
		cout << res << '\n';
	}

}