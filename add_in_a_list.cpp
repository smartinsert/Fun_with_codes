/*
 * add_in_a_list.cpp
 * Statement: Add/Append in a list.
 *  Created on: Mar 31, 2015
 *      Author: Athakur
 */

#include <iostream>
#include <cstring>

using namespace std;

struct node
{
	int data;
	node* link;
	node() : data(0), link(NULL)
	{}
}*head(NULL), *current(NULL), *prev(NULL);

bool hash[100];

void add(int n)
{
	node* temp = new node;
	temp->data = n;
	temp->link = NULL;

	if(head == NULL)
		head = current = temp;
	else
	{
		current->link = temp;
		current = temp;
	}
}

void remove (int n)
{
	node* temp, *prev;
	temp = prev = head;

	if (temp == NULL)
	{
		cout << "Already an empty list";
		cout << endl;
		return;
	}
	else
	{
		while (temp)
		{
			if (temp->data == n)
			{
				prev->link = temp->link;
				delete temp;
				temp = prev->link;
			}
			temp = temp->link;
		}
	}
}

void remove_duplicates()
{
	node *temp = head->link, *prev = head;
	if (head == NULL)
		return;
	hash[head->data] = true;

	while (temp)
	{
		if(hash[temp->data])
		{
			prev->link = temp->link;
			delete temp;
			temp = prev->link;
		}
		else
		{
		hash[temp->data] = true;
		prev = temp;
		temp = temp->link;
		}
	}
}

void swap(node* a, node* b)
{
	node* temp = a;
	a = b;
	b = temp;
}
void sort()
{
	node* prev = head, *current = head->link, *temp = head->link;
	if (head == NULL)
		return;
	while(temp)
	{
		while (prev->data < current->data)
			current = current->link;
		if (current->data > prev->data)
		{
		swap(prev, current);
		prev = current;
		current = prev->link;
		}
		else
		{
		prev = temp;
		current = prev->link;
		}
		temp = temp->link;
	}
}
void print()
{
	node* show = head;
	if(show == NULL)
	{
	cout << "No element in link list" << endl;
	return;
	}
	else
	{
		while(show != NULL)
		{
			cout<< show->data;
			if (show->link == NULL)
				cout << endl;
			else
				cout << "->";
			show = show->link;
		}
	}
}


int main()
{
	memset(hash, false, sizeof(hash));
	add(10);
	add(20);
	add(30);
	add(40);
	print();
	remove(20);
	print();
	add(20);
	print();
	add(10);
	print();
	remove_duplicates();
	print();
	sort();
	print();
	return 0;
}
