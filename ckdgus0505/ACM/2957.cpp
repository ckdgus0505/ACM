#include<iostream>
using namespace std;
int N, C;				// N : 수열의 크기, C : 카운터 값
typedef struct node {
	int value;			//노드의 값
	node* lnode = NULL;	// 왼쪽 자식
	node* rnode = NULL;	// 오른쪽 자식
}node;

void insert(int  X, node* N)
{
	C++;						// 카운터 C값을 1 증가시킨다
	if (X < N->value)			// X가 노드 N에 있는 수보다 작다면)
	{
		if (N->lnode == NULL)	// N의 왼쪽 자식이 없다면
		{
			N->lnode = new node;
			N->lnode->value = X;	// X를 포함하는 새 노드를 만든 뒤, N의 왼쪽 자식으로 만든다
			cout << C << '\n';
		}
		else
		{
			insert(X, N->lnode);	// insert(X, N의 왼쪽 자식) 을 본다.
		}
	}
	else if (X > N->value)			// X가 노드 N에 있는 수보다 크다면
	{
		if (N->rnode == NULL)	// N의 오른쪽 자식이 없다면
		{
			N->rnode = new node;			// 를 포함하는 새 노드를 만든 뒤, N의 오른쪽 자식으로 만들기
			N->rnode->value = X;
			cout << C << '\n';
		}
		else
		{
			insert(X, N->rnode);	// insert(X, N의 오른쪽 자식)
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tmp;

	cin >> N;
	cin >> tmp;
	node *A = new node;

	A->value = tmp;
	cout << C << '\n';
	for (int i = 0; i < N-1; i++)
	{
		cin >> tmp;
		insert(tmp, A );
	}

	
}