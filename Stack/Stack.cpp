/*
*
* @author: ThanTranNghiep
*
*/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int Data;
    Node* next;
};
struct Stack
{
    Node* top;
};

typedef Node* node;

void initStack(Stack t)
{
    t.top=NULL;
}

node createNode(int value)
{
    node n = (node)malloc(sizeof(Node));
    if(n!=NULL)
    {
        n->Data=value;
        n->next=NULL;
    }
    return n;
}

// add new_node on top of the stack
void push(Stack &t, node new_node)
{
    if( t.top ==NULL )
    {
        t.top=new_node;
        return;
    }
    new_node->next=t.top;
    t.top=new_node;
}

//pop element out of stack
void pop(Stack &t)
{
    if(t.top != NULL && t.top->next == NULL)
    {
        free(t.top);
        t.top=NULL;
        return;
    }
    if(t.top == NULL)
    {
        cout<<"\nError: Stack is empty !\n";
        return;
    }
    else
    {
        node i=t.top->next;
        free(t.top);
        t.top=i;
    }
}

// check whether stack is empty
bool isEmpty(Stack t)
{
    return (t.top == NULL) ? false:true ;
}

// get the top element of the Stack
int top(Stack t)
{
    return t.top->Data;
}