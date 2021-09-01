# Linked List
*This post may containts some grammar mistakes, I will very appreciate if you correct me.*

## Definition

- Linked list (danh sách liên kết) is a collection of data, **Linked List element was stored in a single node, each node contains two fields, a field stores its element value, and the other field stores a pointer to the next node**.

- A Linked List look similar like this:

![Link List](https://static.javatpoint.com/ds/images/linked-list.png)

## Types of Linked List
- Singly Linked List
- Doubly Linked List
- Circular Linked List
- *and so on...*

>**For easy to understand, I only cover Singly Linked List in this post and I will use Linked List instead of Singly Linked List for shorten.**
## Implementation Of Singly Linked List
To start working with linked list, first we must to define a Node, assume that I want to store integer value in each Node so that I use `int data`.
```cpp
struct Node {
	int data;
	Node* next;
};
```
Then we write a function to create a Node.
```cpp
Node* createNode(int value) {
	Node *new_node = new Node();
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}
```
Next we define a Linked List.\
To easy to working with Linked List, I define a list with two pointers point to the **first element** and the **last element** of the list.
```cpp
struct List {
	Node *head; //first element
	Node *tail; //last element
};

//Initalize an empty linked list
void initList(List list) {
	list.head = NULL;
	list.tail = NULL;
}
```
After we have Node and List, we need to add Node to List to complete the Linked List.\
*How to add a node to back of the list*
![add Tail](https://s3.ap-south-1.amazonaws.com/afteracademy-server-uploads/types-of-linked-list-and-operation-on-linked-list-insert-end-684624578d427ddd.png)
*Implementation*
```cpp
//add to the back of the list
void addTail(List &list, Node *new_node) {
	if(isEmptyList(list)) {
		list.head = new_node;
		list.tail = new_node;
		return;
	}
	list.tail->next = new_node;
	list.tail = new_node;
}
```
*How to add a node to front of the list*
![add Head](https://s3.ap-south-1.amazonaws.com/afteracademy-server-uploads/types-of-linked-list-and-operation-on-linked-list-insert-begin-c5d6d8aebb19c584.png)
*Implementation*
```cpp
//add to the front of the list
void addHead(List &list, Node *new_node) {
		if(isEmptyList(list)) {
		list.head = new_node;
		list.tail = new_node;
		return;
	}
	new_node->next = list.head;
	list.head = new_node;
}
```
## Basic Linked List Operations
*Visit [here](https://visualgo.net/en/list) for linked list operations visuallization.*
1. Traveral\
To traverse all the nodes.
```cpp
//simply go through each node
void traverse(List list) {
	Node *current_node = list.head;
	while(current_node != NULL) {
		cout << current_node->data << " ";
		current_node = current_node->next;
	}
}
```
2. Insertion\
Insert a `node` to `list` at the given `position`
```cpp
void insert(List &list, Node *new_node, int position) {
	// assume that our list started index is 0
	if(position < 0) { // to add a node at index < 0 is invalid
		cout << "Out of range\n";
		return;
	}
	// to add node at position 0 means "add to the front of the node"
	if(position == 0) { 
		addHead(list,new_node);
		return;
	}
	Node *current_node = list.head;
	// traverse to the given position
	while(position > 0) {
		position--;
		if(isEmptyNode(current_node)) {
			if(position > 0) { // to add a node to an index exceed list range
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
```
3. Deletion\
To delete a node at a given `position`.
```cpp
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
```