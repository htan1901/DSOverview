/*
*
* @author: htan1901
*
*/
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

bool isEmptyList(List list)
{
	return list.head == NULL;
}

bool isEmptyNode(Node *node) {
	return node == NULL;
}

//add to the back of the list
void addTail(List &list, Node *new_node) 
{
	if(isEmptyList(list))
	{
		list.head = new_node;
		list.tail = new_node;
		return;
	}
	list.tail->next = new_node;
	list.tail = new_node;
}

//add to the front of the list
void addHead(List &list, Node *new_node) 
{
		if(isEmptyList(list))
	{
		list.head = new_node;
		list.tail = new_node;
		return;
	}
	new_node->next = list.head;
	list.head = new_node;
}

void traverse(List list) 
{
	Node *current_node = list.head;
	while(current_node != NULL) 
	{
		cout << current_node->data << " ";
		current_node = current_node->next;
	}
}

void insert(List &list, Node *new_node, int position) 
{
	// assume that our list started index is 0
	if(position < 0) 
	{ // to add a node at index < 0 is invalid
		cout << "Out of range\n";
		return;
	}
	// to add node at position 0 means "add to the front of the node"
	if(position == 0) 
	{ 
		addHead(list,new_node);
		return;
	}
	Node *current_node = list.head;
	// traverse to the given position
	while(position > 0) 
	{
		position--;
		if(isEmptyNode(current_node)) 
		{
			if(position > 0) 
			{ // to add a node to an index exceed list range
				cout << "Out of range\n";
				return;
			} // the index is exactly the last index
			addTail(list, new_node);
			return;
		}
		current_node = current_node->next;
	}
	new_node->next = current_node->next;
	current_node->next = new_node;
	return;
}

void deleteNode(List &list, int position) {
	if(position < 0) //out of range, nothing happend
		return;
	Node *current_node = list.head;
	// traverse to the given position
	while(position > 0) {
		position--;
		if(current_node == NULL) //out of range, nothing happend
				return;
		current_node = current_node->next;
	}
	if(current_node == list.head) {
		Node *del_node = current_node;
		list.head = current_node->next;
		free(del_node); //free memory
		return;
	}
	if(current_node == list.tail) {
		Node *new_tail;
		for(Node *i = list.head; i->next != current_node; i = i->next) //search for new tail
			new_tail = i;
		list.tail = new_tail; //update new tail
		free(current_node); //free memory
		return;
	}
	Node *del_node = current_node;
	current_node->next = current_node->next->next;
	free(del_node);
	return;
}