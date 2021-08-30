# Linked List
*This post will containts some grammar mistakes, I will very appreciate if you correct me*

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
To start working with linked, first we must to define a Node, assume that I want to store integer element in each Node so I use `int data`.
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
To easy to working with Linked List, I define a list with two pointers to the **first element** and the **last element** of the list.
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
After we have Node and List, we need to add Node to List to complete the Linked List.
```cpp
//add to the back of the list
void addNode(List &list, Node *added_node) {
	if(isEmpty(list))
	{
		list.head = added_node;
		list.tail = added_node;
		return;
	}
	list.tail->next = added_node;
	list.tail = added_node;
}
```



