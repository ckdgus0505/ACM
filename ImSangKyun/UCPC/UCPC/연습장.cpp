#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> ret;
	stringstream stream(str);
	string tmp;
	
	while (getline(stream, tmp, delimiter))
		ret.push_back(tmp);
	return ret;
}

int stringToTime(string str, bool flag) {
	int hour, min, sec, msec, res;

	if (flag) {	//응답완료시간
		vector<string> time = split(str, ':');
		hour = stoi(time[0]) * 3600;	//second 로 변환
		min = stoi(time[1]) * 60;
		sec = stoi(split(time[2], '.')[0]);
		msec = stoi(split(time[2], '.')[1]);
		res = (hour + min + sec) * 1000 + msec;	//float을 int로 변환하여 사용하기 위해 전체 초에 X1000을 하여 소숫점을 없앰 (ms 변환)
	}
	else {	//처리시간
		vector<string> tmp = split(str, '.');
		if (tmp.size() == 1) {		//소숫점이 없을경우
			tmp[0].pop_back();		// s문자열 제거
			res = stoi(tmp[0]) * 1000;
		}
		else {	//소숫점이 존재할경우
			tmp[1].pop_back();
			res = stoi(tmp[0]) * 1000 + stoi(tmp[1]);	//소숫점을 int로 (ms 변환)
		}
	}
	return res;
}

int solution(vector<string> lines) {
	int answer = 0;
	vector<string> splLog;
	vector<vector<string>> splTime;
	vector<pair<int, int>> idx;

	for (int i = 0; i < lines.size(); ++i) {
		splLog = split(lines[i], ' ');
		if (splLog[0] != "2016-09-15") 
			lines[i].erase();
		else {
			int endTime = stringToTime(splLog[1], true);
			int procTime = stringToTime(splLog[2], false);
			int startTime = endTime - procTime + 1;
			idx.push_back(make_pair(startTime, endTime));
		}
	}

	for (int i = 0; i < idx.size(); ++i) {	//각 시작과 끝이 기준이 되어 1초 탐색 해야함 (1000ms)
		for (int j = idx[i].first; j < idx[i].second; ++j) {
			int cnt = 0;
			for (int k = 0; k < idx.size(); ++k) {
				if (i == k)	continue;
				if ((idx[k].first <= j && idx[k].second >= j) || (idx[k].first <= j+1000 && idx[k].second >= j+1000))	++cnt;
			}
			answer = std::max(answer, cnt + 1);
		}
	}
	return answer;
}

int main(void) {
	vector<string> s = { "2016-09-15 23:59:59.999 0.001s" };
	cout << solution(s) << '\n';
}