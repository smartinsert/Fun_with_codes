/*
 * Deleting_random_node.cpp
 * Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node
 *  Created on: Apr 8, 2015
 *      Author: Athakur
 */


#include <iostream>

using namespace std;

struct node
{
	int data;
	node* next;
	node() : data(0), next(NULL) {}
}*head(NULL), *current(NULL);

void add(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;

	if (head == NULL)
		head = current = temp;
	else
	{
		current->next = temp;
		current = temp;
	}
}

void erase(node* c)
{
	node* temp = c->next;
	c->next = temp->next;
	c->data = temp->data;
	delete temp;
}

void print()
{
	node* temp = head;
	if (head == NULL)
		return;
	while(temp)
	{
		cout << temp->data;
		if (temp->next == NULL)
			cout << endl;
		else
			cout << "->";
		temp = temp->next;
	}
	cout<< endl;
}

int main()
{
	add(2);
	add(7);
	add(5);
	add(3);
	add(4);
	add(1);
	print();
	node *c = head;
	erase(c->next);
	print();
	return 0;
}
