#include<iostream>
#include<vector>
using namespace std;
typedef struct node {
	char data;
	node* lnode = NULL;
	node* rnode = NULL;
} node;

vector<node*> arr; // node를 담는 vector

void search1(node* N)
{
	cout << N->data;
	if (N->lnode != NULL) search1(N->lnode);
	if (N->rnode != NULL) search1(N->rnode);
}
void search2(node *N)
{
	
	if (N->lnode != NULL) search2(N->lnode);
	cout << N->data;
	if (N->rnode != NULL) search2(N->rnode);
}
void search3(node *N)
{
	if (N->lnode != NULL) search3(N->lnode);
	if (N->rnode != NULL) search3(N->rnode);
	cout << N->data;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	arr.assign(N, NULL);
	for (int i = 0; i < N; i++)	//벡터에다가 node 할당해줌
	{
		arr[i] = new node;
		arr[i]->data = i + 'A';
	}


	for (int i = 0; i < N; i++)
	{
		char tmp1, tmp2, tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;

		if (tmp2 != '.')
		{
			arr[tmp1 - 'A']->lnode = arr[tmp2 - 'A'];
		}
		if (tmp3 != '.')
		{
			arr[tmp1 - 'A']->rnode = arr[tmp3 - 'A'];
		}
	}
	search1(arr[0]);
	cout << '\n';
	search2(arr[0]);
	cout << '\n';
	search3(arr[0]);
	cout << '\n';

}