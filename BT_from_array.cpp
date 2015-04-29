/*
 * Binary_tree_from_Array.cpp
 * Given a sorted array, create a binary tree of minimal height
 *  Created on: Apr 23, 2015
 *      Author: Athakur
 */

#include <iostream>

using namespace std;

struct BTNode
{
	int val;
	BTNode* lchild;
	BTNode* rchild;
	BTNode() : val(0), lchild(NULL), rchild(NULL) {}
};

BTNode* create_bin_tree_node(int v)
{
	BTNode *p = new BTNode;
	if (p != NULL)
	{
		p->val = v;
		p->lchild = NULL;
		p->rchild = NULL;
	}
	return p;
}

void create_balanced_binary_tree(BTNode** root, int arr[], int start, int end)
{
	if (start<=end)
	{
	int mid = (start+end+1)/2;
	*root = create_bin_tree_node(arr[mid]);
	create_balanced_binary_tree(&((*root)->lchild), arr, start, mid-1);
	create_balanced_binary_tree(&((*root)->rchild), arr, mid+1, end);
	}
}

void print_bin_tree(BTNode *root)
{
	if (root!=NULL)
	{
		cout << root->val << " ";
		print_bin_tree(root->lchild);
		cout << endl;
		print_bin_tree(root->rchild);
		cout << endl;
	}
}

int main()
{
	int arr[8];
	for(int i=0; i<8; ++i)
		arr[i] = i;
	BTNode* root = NULL;

	create_balanced_binary_tree(&root,arr, 0, 7);
	print_bin_tree(root);
	return 0;
}
