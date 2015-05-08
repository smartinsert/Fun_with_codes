/*
 * Sum_of_a_node.cpp
 * Given a binary tree with nodes populated. Design an algo to print all the paths that sum to that value
 *  Created on: Apr 30, 2015
 *      Author: Athakur
 */

#include <iostream>
#include <vector>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

node* newNode (const int val)
{
	node* temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->value = val;
	return temp;
}


const int& getValue(node* root)
{
	return root->value;
}

// find the height of the tree to allocate space for the vector
int getMaxHeight(node* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = getMaxHeight(root->left);
	int rightHeight = getMaxHeight(root->right);
	return (max(leftHeight, rightHeight) + 1);
}

// print the path of the target sums
void printPath(vector<int>& paths, int start, int end)
{
	for (int i=start; i<=end;++i)
	{
		if (paths[i] == 0)
			cout << "NULL" << " ";
		else
			cout << paths[i] << " ";
	}
	cout << endl;
}

void generatePaths(node* root, vector<int>& paths, int depth, const int sum)
{
	// base case
	if (root == NULL)
		return;

	paths[depth] = getValue(root);
	int total = 0;

	// Hit the sum ? Print the depth
	for (int i=depth; i>=0; --i)
	{
		 total+=paths[i];
		 if (total == sum)
			printPath(paths, i, depth);
	}

	// tarverse one level down and sum from the level up the tree
	// to find alternate paths giving the same sum
	generatePaths(root->left, paths, depth+1, sum);
	generatePaths(root->right, paths, depth+1, sum);
}

int main()
{
	node* root = newNode(10);
	root->left = newNode(7);
	root->right = newNode(11);
	root->left->left = newNode(22);
	root->left->right = newNode(19);
	root->right->left = newNode(15);
	root->right->right = newNode(13);
	root->left->left->left = newNode(17);
	vector<int> paths (getMaxHeight(root));
	generatePaths(root, paths, 2, 36);
	return 0;
}
