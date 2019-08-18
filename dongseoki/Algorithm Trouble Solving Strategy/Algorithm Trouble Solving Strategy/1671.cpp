#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int n, m;
int visited[1010];
int b[1010];
//int linknum[51];
vector<vector<int>> node;
int dfs(int here, int flag) {
	//cout << "dfs ���� here����" << here << "\n";
	if (visited[here]) {
		//cout << "\n������ �־�\n";
		return 0;
	}
	visited[here] = 1;

	int linknum = 0;
	for (int i = 0; i < node[here].size(); i++) {
		
		/*if (linknum >= 2 && flag==0)
			return 0;*/ 
		// ��ũ�� 2�� �̻��� �ȵȴ�.
		int there = node[here][i];
		if (!b[there] || dfs(b[there], 1)) {
			b[there] = here;
		//	linknum++;
			return 1;
		}
	}
	//cout << "\n�� �������� ����\n";
	return 0;
}
int bmatch() {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		//cout << i << "��° bmatch\n";
		memset(visited, 0, sizeof(visited));
		dfs(i, 0);
		memset(visited, 0, sizeof(visited));
		dfs(i, 0);
		//cout << "\n ���� b�迭��Ȳ\n";
		//for (int i = 1; i <= n; i++)
		//	cout << b[i] << " ";
		//cout << "\n";
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	node.resize(n + 1);
	vector<vector<int>> sharks;
	sharks.push_back({ 0,0,0 });// index 0�� �Ⱦ�.
	for (int i = 1; i <= n; i++) {
		int si, sp, in;
		scanf("%d %d %d", &si, &sp, &in);
		sharks.push_back({ si, sp, in });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			int si, sp, in;
			int count = 0;
			int eq = 0;
			for (int k = 0; k < 3; k++) {
				if (sharks[i][k] > sharks[j][k])
					count++;
				else if (sharks[i][k] == sharks[j][k])
					eq++;
			}

			if (count == 3 ||(eq == 3 && i < j)) {
				//���� �̾�����
				node[i].push_back(j);
			}
		}
	}
	bmatch();
	//printf("%d\n", bmatch());

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i]==0)
			sum++;
	}
	printf("%d\n", n- sum);
	return 0;

	//scanf("%d%d", &n, &m);
	//node.resize(n + 1);
	//for (int i = 1; i <= n; i++) {
	//	int v, x;
	//	scanf("%d", &v);
	//	while (v--) {
	//		scanf("%d", &x);
	//		node[i].push_back(x);
	//	}
	//}
	//printf("%d", bmatch());
	//return 0;
}


//��ó: https://jason9319.tistory.com/149 [ACM-ICPC �� Ż ���]