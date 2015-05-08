/*
 * number_as_list.cpp
 * represent two numbers as linked list, add the two and return the sum
 *  Created on: Apr 8, 2015
 *      Author: Athakur
 */

#include <iostream>
#include <math.h>
using namespace std;

struct node
{
	int data;
	node* next;
	node() : data(0), next(NULL) {}
}*head(NULL), *current(NULL);

node* int_to_list(int a)
{
	node* list = new node;
	list->data = a%10;
	list->next = NULL;
	if (head == NULL)
		head = current = list;
	while(a>0)
	{
	a=a/10;
	current->data = a%10;
	current = current->next;
	}
	return head;
}

node* sum(node& a, node& b)
{
	node* list = new node;
	if (list == NULL || &a == NULL || &b == NULL)
		return NULL;
	list->data = a.data + b.data;
	list->next = NULL;
	if (head == NULL)
		head = current = list;
	else
	{
		current->next = list;
		current = list;
	}
	return head;
}

void print(node* list)
{
	node* temp = list;
	if (list == NULL)
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
	cout << endl;
}


int main()
{
	node* list_a = int_to_list(315);
	print(list_a);
	node* list_b = int_to_list(592);
	print(list_b);
	node* result = sum(*list_a, *list_b);
	print(result);
	return 0;
}
