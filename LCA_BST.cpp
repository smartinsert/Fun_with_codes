/*
 * LCA_BST.cpp
 * Find the least common ancestor in a BST
 *  Created on: Apr 28, 2015
 *      Author: Athakur
 */

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int key;
	struct Node *left, *right;
};

// Function to create a new binary tree node with a given key
Node* newNode(int k)
{
	Node* temp = new Node;
	temp->key = k;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// Function to find the path from the root node to given root of the tree. Stores the
// path in a vector, returns true if the path exists else false
bool TracePath(Node* root, vector<int> &path, int k)
{
	// base case
	if (root == NULL)
		return false;
	// Store this node in path vector. The node will be removed if it does not exist
	path.push_back(root->key);

	// Check if k is the same as root's key
	if (root->key == k)
		return true;

	// Check if k is in the left or the right subtree
	if ((root->left && TracePath(root->left, path, k)) ||
		(root->right && TracePath(root->right, path, k)))
	return true;
	// If not found, remove root from path[] and return false
	path.pop_back();
	return false;
}

int findLCA(Node* root, int n1, int n2)
{
	// store paths to n1 and n2 from the root
	vector<int> path1, path2;
	if (!TracePath(root,path1,n1) || !TracePath(root, path2,n2))
		return -1;
	unsigned int i;
	for (i=0; i<(unsigned)path1.size() && i<(unsigned)path2.size(); ++i)
		if (path1[i] != path2[i])
			break;
	return path1[i-1];
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "FCA(2,4) is: " <<  findLCA(root,2,4) << endl;
	cout << "FCA(5,6) is: " <<  findLCA(root,5,6) << endl;
	cout << "FCA(4,7) is: " <<  findLCA(root,4,7) << endl;
	cout << "FCA(4,5) is: " <<  findLCA(root,4,5) << endl;
	return 0;
}
