#include<iostream>
using namespace std;
int N, C;				// N : ������ ũ��, C : ī���� ��
typedef struct node {
	int value;			//����� ��
	node* lnode = NULL;	// ���� �ڽ�
	node* rnode = NULL;	// ������ �ڽ�
}node;

void insert(int  X, node* N)
{
	C++;						// ī���� C���� 1 ������Ų��
	if (X < N->value)			// X�� ��� N�� �ִ� ������ �۴ٸ�)
	{
		if (N->lnode == NULL)	// N�� ���� �ڽ��� ���ٸ�
		{
			N->lnode = new node;
			N->lnode->value = X;	// X�� �����ϴ� �� ��带 ���� ��, N�� ���� �ڽ����� �����
			cout << C << '\n';
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
			cout << C << '\n';
		}
		else
		{
			insert(X, N->rnode);	// insert(X, N�� ������ �ڽ�)
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