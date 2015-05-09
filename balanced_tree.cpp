#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int maxn=100;

struct Node
{
	int key;
	Node *lchild, *rchild, *parent;
	Node() : lchild(NULL), rchild(NULL),parent(NULL) {}
};

Node *head, *p, node[maxn];

int cnt;

void init()
{
	head = p = NULL;
	memset(node, '\0', sizeof(node));
	cnt=0;
}

int getHeight(Node* head)
{
	if (head == NULL)
		return 0;
	else
		return max(getHeight(head->lchild),getHeight(head->rchild));
}

bool isBalanced(Node* head)
{
	if (head == NULL)
		return true;
	int diff = getHeight(head->lchild) - getHeight(head->rchild);
	if (fabs(diff)>1)
		return false;
	else
		return isBalanced(head->lchild) && isBalanced(head->rchild);
}

void insert(Node* head, int x)
{
	if (head == NULL)
	{
		node[cnt].key = x;
		node[cnt].parent = p;
		head = &node[cnt++];
		return;
	}

	p = head;
	if (x < head->key)
		insert(head->lchild, x);
	else
		insert(head->rchild, x);
	return;
}

int main()
{
	init();
	int a[] = {3,4,5,1,7,8,6,12,13};
	for (int i=0; i<10; ++i)
		insert(head, a[i]);
	
	cout << "The height of the tree is " << cnt << endl;
/*
	for (int i=0; i<cnt; ++i)
	{
		cout << "The left child of the parent " << node[i].parent << "is " << (node[i].lchild)->key << endl;
		cout << "The right child of the parent " << node[i].parent << "is " << (node[i].rchild)->key << endl;
	}	
*/
	if (isBalanced(head))
		cout << "The binary tree is balanced." << endl;
	else
		cout<< "The binary tree is not balanced." << endl;
	return 0;
} 
