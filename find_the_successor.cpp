#include <iostream>
#include <stdio.h> 
using namespace std;

typedef struct node
{
	int data;
	node* left;
	node* right;
	node* parent;
}node;

node* minValue(node* x)
{
	node* current = x;
	while(current->left != NULL)
		current = current->left;
	return current;
}

node* inOrderTraversal(node* n)
{
	node *p = new node;
	if (n->right != NULL)
		return minValue(n);
	else
		p = n->parent;
		while(p != NULL && n == p->right)
		{
			n=p;
			p=p->parent;
		}
	return p;
}


node* addNode(int data)
{
	node* root = new node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
	return root;
}


node* insert(node* add, int data)
{
	node* temp = new node;
	if (add == NULL)
		addNode(data);
	else if (data <= add->data)
	{
		temp = insert(add->left, data);
		add->left = temp;
		temp->parent = add;
	}
	else
	{
		temp = insert(add->right, data);
		add->right = temp;
		temp->parent = add;
	}

	return add;
}

int main()
{
	node* root = NULL, *temp, *succ, *min;
	root = insert(root, 20);
  	root = insert(root, 8);
	root = insert(root, 22);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);  
  	root = insert(root, 14);    
	temp = root->left->right->right;
	
	succ = inOrderTraversal(temp);
	if (succ != NULL)
		cout << "The successor of " << temp->data << " is " << succ->data;
	else
		cout << "The successor of " << temp->data << " does not exist.";
	cout << endl;

	return 0;
}
