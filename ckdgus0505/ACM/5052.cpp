#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int NUMBERS = 10;
int toNumber(char ch) { return ch - '0'; }

int t, n;
char** nums;

struct TrieNode {
	TrieNode* children[NUMBERS];
	bool terminal;
	TrieNode() : terminal(false) {
		memset(children, 0, sizeof(children));
	}
	~TrieNode() {
		for (int i = 0; i < NUMBERS; i++)
			if (children[i])
				delete children[i];
	}

	void insert(const char* key) {
		if (*key == 0)
			terminal = true;
		else {
			int next = toNumber(*key);
			if (children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key + 1);
		}
	}

	TrieNode* find(const char* key) {
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		nums = (char**)malloc(sizeof(char*) * n);
		for (int j = 0; j < n; j++)
			nums[j] = (char*)malloc(sizeof(char) * 11);
		TrieNode tri;
		for (int j = 0; j < n; j++) {
			cin >> nums[j];
			tri.insert(nums[j]);
		}
		int chk = 0;
		for (int j = 0; j < n; j++)
		{
			for(int k = 0; k < 10; k++)
				if (tri.find(nums[j])->children[k] != NULL)
					chk++;
		}
		if (chk == 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}