#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

typedef struct node
{
	int number;
	node* next = nullptr;
}node;

vector<int> colors;
node* adj;



int N, M, C;
int answer;
int *cache;

int fvc(int v, int c);
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> C;
	colors.assign(N + 1, 0);

	cache = new int[N + 1];
	memset(cache, -1, sizeof(int) * (N + 1));
	adj = new node[N+1];

	for (int i = 1; i <= N; i++)
	{
		cin >> colors[i];
	}

	for (int i = 1; i <= N-1; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		node* tmp = &adj[tmp1];
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = new node;
		tmp->next->number = tmp2;
		tmp->number = i;

	}

	for (int i = 0; i < M; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		answer += fvc(tmp1, tmp2);
		memset(cache, -1, sizeof(int) * (N + 1));
	}
	cout << answer % 1000000007 << '\n';
}
int fvc(int v, int c)
{
	if (adj[v].next == nullptr && colors[v] <= c) return 1;
	else if (adj[v].next == nullptr && colors[v] > c) return 0;

	int& ret = cache[v];
	if (ret != -1) return ret;


	int tmp = 0;
	node* current;
	current = &adj[v];

	if (colors[current->number] <= c) tmp += 1;
	while(true)
	{
		if (current->next != nullptr)
		{
			current = current->next;
			tmp += fvc(current->number,c);
		}
		else
		{
			ret = tmp;
			break;
		}
	}

	return ret;
}