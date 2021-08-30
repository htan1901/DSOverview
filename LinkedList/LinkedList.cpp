#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

struct List 
{
	Node *head; //first element
	Node *tail; //last element
};

Node* createNode(int value) 
{
	Node *new_node = new Node();
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}

//Initalize an empty linked list
void initList(List list) 
{
	list.head = NULL;
	list.tail = NULL;
}

bool isEmpty(List list)
{
	return list.head == NULL;
}

//add to the back of the list
void addNode(List &list, Node *added_node) 
{
	if(isEmpty(list))
	{
		list.head = added_node;
		list.tail = added_node;
		return;
	}
	list.tail->next = added_node;
	list.tail = added_node;
}
