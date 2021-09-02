/*
*
* @author: thantrannghiep
*
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    char Data;
    node*next;
};
struct Stack
{
    node*top;
};
node*CreateNode(int x){
    node*n= (node*)malloc(sizeof(node));
    if(n!=NULL){
        n->Data=x;
        n->next=NULL;
    }
    return n;
}
void initStack(Stack t){
    t.top=NULL;
}
// add element before "top"

void push(Stack &t , node* x){
    if(t.top==NULL){
        t.top=x;
        return;
    }
    x->next=t.top;
    t.top=x;
}
// delete element top 

void pop(Stack &t ){
    if(t.top == NULL){
        cout<<"\nStack is Empty ! \n";
        return;
    }
    // case stack has one element
    if(t.top !=NULL && t.top->next == NULL){
        free(t.top);
        t.top=NULL;
        return;
    }
    // case stack has many element
    if(t.top !=NULL && t.top->next != NULL){
        node * i =t.top->next;
        free(t.top);
        t.top=i;
    }
}

// check for valid brackets

bool Check(Stack &t , string n){
    int length = n.size();
    node* a= CreateNode('#');
    push(t,a);                      // add '#' check stack empty 
    for(int i = 0; i < length; i++ )
    {
        if(n[0] == ')' || n[0] == '}' || n[0] == ']' )
        {
            return false;
        }

        // push '(' '{' '['  into stack
        if(n[i] == '(' || n[i] == '{' || n[i] == '[' )
        {
            node* x = CreateNode(n[i]);
            push(t,x);
        }
        else
        {   
            if (t.top->Data == '#')    {   return false; }
            if (n[i]==')'&& t.top->Data == '(')    {   pop(t); }
            if (n[i]=='}'&& t.top->Data == '{')    {   pop(t); }
            if (n[i]==']'&& t.top->Data == '[')    {   pop(t); }
        }
    }
    if(t.top->Data !='#'){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    string n;
    Stack t;
    initStack(t);
    while(true){
        cout<<"\nInsert Bracket : ";
        cin>>n;    
        if(Check(t,n)==true){
            cout<<"\nTrue \n";
        }
        else{
            cout<<"\nFalse \n";
        }
    }
    return 0;
}

