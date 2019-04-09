#include<iostream>
using namespace std;

typedef struct node {
	int value;			//����� ��
	node* lnode = NULL;	// ���� �ڽ�
	node* rnode = NULL;	// ������ �ڽ�
}node;

void insert(int  X, node* N)
{
	if (X < N->value)			// X�� ��� N�� �ִ� ������ �۴ٸ�)
	{
		if (N->lnode == NULL)	// N�� ���� �ڽ��� ���ٸ�
		{
			N->lnode = new node;
			N->lnode->value = X;	// X�� �����ϴ� �� ��带 ���� ��, N�� ���� �ڽ����� �����
		}
		else
		{
			insert(X, N->lnode);	// insert(X, N�� ���� �ڽ�) �� ����.
		}
	}
	else if (X > N->value)			// X�� ��� N�� �ִ� ������ ũ�ٸ�
	{
		if (N->rnode == NULL)	// N�� ������ �ڽ��� ���ٸ�
		{
			N->rnode = new node;			// �� �����ϴ� �� ��带 ���� ��, N�� ������ �ڽ����� �����
			N->rnode->value = X;
		}
		else
		{
			insert(X, N->rnode);	// insert(X, N�� ������ �ڽ�)
		}
	}
}

void search(node* N)
{
	if (N->lnode != NULL)
	{
		search(N->lnode);
	}
	if (N->rnode != NULL)
	{
		search(N->rnode);
	}
	cout << N->value << '\n';
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tmp;

	cin >> tmp;
	node *A = new node;

	A->value = tmp;
	while(!cin.eof())
	{
		cin >> tmp;
		insert(tmp, A);
	}

	search(A);

}