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

void initStack(Stack t){
    t.top=NULL;
}
node CreateNode(int x){
    node n = (node)malloc(sizeof(Node));
    if(n!=NULL){
        n->Data=x;
        n->next=NULL;
    }
    return n;
}
// add element before top
void push(Stack &t, node x){
    if( t.top ==NULL ){
        t.top=x;
        return;
    }
    x->next=t.top;
    t.top=x;
}

// delete element top

void pop(Stack &t){
    if(t.top != NULL && t.top->next == NULL){
        free(t.top);
        t.top=NULL;
        return;
    }
    if(t.top == NULL){
        cout<<"\nError: Stack is empty !\n";
        return;
    }
    else{
        node i=t.top->next;
        free(t.top);
        t.top=i;
    }
}

// check Stack empty

bool Empty(Stack t){
    return (t.top == NULL) ? false:true ;
}

// print the top element of the Stack
int Top(Stack t){
    return t.top->Data;
}

// add element to Stack

void GetStack(Stack &t, int n){
    for( int i=n ; i>0 ; i-- ){
        cout<<"Stack[ "<<i<<" ] = ";
        int temp;
        cin>>temp;
        node n =CreateNode(temp);
        push(t,n);
    }
}

// Display element in Stack

void Display(Stack t){
    cout<<endl;
    node i =t.top;
    while (i!=NULL)
    {
        cout<<i->Data<<" ";
        i=i->next;
    }
    
}
int main(){
    int n;
    Stack t;
    initStack(t);
    cout<<"\nEnter n: ";         // Enter the number of element of the Stack
    cin>>n;
    GetStack(t,n);
    Display(t);
    cout<<"\n Top is : "<<Top(t);
    return 0;
}
