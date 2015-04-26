#include <iostream>
#include <stdio.h>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

node* BTtoListUtil(node* root)
{
	if (root == NULL)
		return root;
	if (root->left != NULL)
	{
	node* left = BTtoListUtil(root->left);
	// Find the inorder predecessor. After this loop, left
	// will point to the inorder predecessor
	for(; left->right!=NULL; left=left->right);
	
	// Make root as next of the predecessor
	left->right = root;
	
	// Make predecessor as previous of root
	root->left = left;
	}

	if (root->right != NULL)
	{
	node* right = BTtoListUtil(root->right);
	for (; right->left!=NULL; right=right->left);

	// Make root as next of the predecessor
	right->left = root;

	// Make predecessor as previous of root
	root->right=right;
	}

	return root;
}

node* BTtoList(node* root)
{

	// Base Case
	if (root == NULL)
		return root;
	
	root = BTtoListUtil(root);

	while (root->left != NULL)
		root=root->left;
	
	return root;
}

/* Helper function that allocates a new node with the 
* given data and NULL left and right pointers
*/

node* newNode(int data)
{
	node* root = new node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void printList(node* root)
{
	while (root != NULL)
	{
		printf("%d", root->data);
		root = root->right;
		cout << " ";
	}
	cout << endl;

}

int main()
{
	node* root = newNode(10);
	root->left = newNode(12);
	root->right = newNode(15);
	root->left->left = newNode(25);
	root->right->left = newNode(36);
	root->left->right = newNode(30);
	
	node* head = BTtoList(root);

	printList(head);

	return 0;
}
