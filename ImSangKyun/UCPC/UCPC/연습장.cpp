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

	if (flag) {	//����Ϸ�ð�
		vector<string> time = split(str, ':');
		hour = stoi(time[0]) * 3600;	//second �� ��ȯ
		min = stoi(time[1]) * 60;
		sec = stoi(split(time[2], '.')[0]);
		msec = stoi(split(time[2], '.')[1]);
		res = (hour + min + sec) * 1000 + msec;	//float�� int�� ��ȯ�Ͽ� ����ϱ� ���� ��ü �ʿ� X1000�� �Ͽ� �Ҽ����� ���� (ms ��ȯ)
	}
	else {	//ó���ð�
		vector<string> tmp = split(str, '.');
		if (tmp.size() == 1) {		//�Ҽ����� �������
			tmp[0].pop_back();		// s���ڿ� ����
			res = stoi(tmp[0]) * 1000;
		}
		else {	//�Ҽ����� �����Ұ��
			tmp[1].pop_back();
			res = stoi(tmp[0]) * 1000 + stoi(tmp[1]);	//�Ҽ����� int�� (ms ��ȯ)
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

	for (int i = 0; i < idx.size(); ++i) {	//�� ���۰� ���� ������ �Ǿ� 1�� Ž�� �ؾ��� (1000ms)
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