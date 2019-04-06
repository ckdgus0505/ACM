#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//7
//A B C
//B D .
//C E F
//E . .
//F.G
//D . .
//G . .
//

//전위
//중위
//후위
//ABDCEFG 
//DBAECFG
//DBEGFCA


class BinaryNode
{
public:
	char data;
	BinaryNode* left;
	BinaryNode* right;
	/*BinaryNode(char val = 0, BinaryNode * l = NULL, BinaryNode* r =NULL)
		:data(val), left(l), right(r)
	{ }*/

	char getData() { return data;}
	void setData(int val) { data = val; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
};

class BinaryTree
{
public:
	BinaryNode * root;
	//BinaryTree(BinaryNode * root):root(root)
	//{ }
	void inorder(BinaryNode * n) {
		if (n != NULL)
		{
			if (n->getLeft() != NULL)
				inorder(n->getLeft());
			cout << n->getData();
			if (n->getRight() != NULL)
				inorder(n->getRight());
		}
	}
	void preorder(BinaryNode * n) {
		if (n != NULL)
		{
			cout << n->getData();
			if (n->getLeft() != NULL)
				inorder(n->getLeft());
			if (n->getRight() != NULL)
				inorder(n->getRight());
		}
	}
	void postorder(BinaryNode * n) {
		if (n != NULL)
		{
			
			if (n->getLeft() != NULL)
				inorder(n->getLeft());
			if (n->getRight() != NULL)
				inorder(n->getRight());
			cout << n->getData();

		}
	}

};



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); // cout 과 cin 사이에 같이 쓰는 버퍼 연결을 끊는다. 동기화를 해제한다.?

	int N;
	cin >> N;
	vector<BinaryNode *> vec;
	
	for (int i = 0; i < N; i++)
		vec.push_back(new BinaryNode());

	for (int i = 0; i < N; i++) {
		char nodeName;
		char leftNode;
		char rightNode;
		cin >> nodeName;
		cin >> leftNode;
		cin >> rightNode;
		//vec.push_back(new BinaryNode());

		vec[i]->data = nodeName;
		if (leftNode = '.')
			vec[i]->left = NULL;
		else
			vec[i]->left =vec[leftNode - 'A'];

		if (rightNode = '.')
			vec[i]->right = NULL;
		else
			vec[i]->right = vec[rightNode - 'A'];

	}

	BinaryTree * bt = new BinaryTree();

	bt->preorder(vec[0]);
	//bt->inorder(vec[0]);
	//bt->postorder(vec[0]);




	return 0;



}