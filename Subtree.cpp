/*
 * Subtree.cpp
 * To check if a tree S is a subtree of T
 * Given two binary trees, check if the first tree is subtree of the second one.
 * A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T.
 *  Created on: Apr 29, 2015
 *      Author: Athakur
 *
 *      				25
 *      				/\
 *      			   10 3
 *      			   /\  \
 *      			   4 6  3
 *      			  /
 *      			 30
 */


#include <iostream>

using namespace std;

#define MAX 100

struct node
{
	int data;
	struct node* left;
	struct node* right;
};


// A function to return a new node
node* newNode(int val)
{
	node* temp = new node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
// A function to check whether the two trees are the same
bool isIdentical(node* root1, node* root2)
{
	// base case: nothing left in the subtree
	if (root1 == NULL && root2 == NULL)
		return true;

	// big tree empty and subtree still not found
	if (root1 == NULL || root2 == NULL)
		return false;

	return (root1->data == root2->data &&
			isIdentical(root1->left, root2->left) &&
			isIdentical(root1->right, root2->right));
}

// Fucntion to check if a given tree is a subtree
bool isSubtree(node* T, node* S)
{
	if (T == NULL)
		return false;

	if (S == NULL)
		return true;

	// Check if the tree with node S is rooted at T
	if (isIdentical(T,S))
		return true;

	// if the tree with root as the current node doesn't exist
	// then try the left and the right subtree

	return isSubtree(T->left,S) ||
		isSubtree(T->right,S);
}



int main()
{
	struct node* T = newNode(26);
	T->left = newNode(10);
	T->right = newNode(3);
	T->right->right = newNode(3);
	T->left->left = newNode(4);
	T->left->right = newNode(6);
	T->left->left->right = newNode(30);

	// Subtree S
	struct node* S = newNode(10);
	S->left = newNode(4);
	S->right = newNode(6);
	S->left->right = newNode(30);

	if (isSubtree(T,S))
		cout << "S is a subtree of T.";
	else
		cout << "S is not a subtree of T.";

	cout << endl;

	return 0;
}
