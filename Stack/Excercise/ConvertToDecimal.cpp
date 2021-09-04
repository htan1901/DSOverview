#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int Data;
    Node*next;
};
typedef Node*node;
struct Stack
{
    node top;
};
void initStack(Stack t)
{
    t.top=NULL;
}
node CreateNode( int x  )
{
    node a = (node)malloc(sizeof(Node));
    if(a!=NULL)
    {
        a->Data=x;
        a->next=NULL;
    }
    return a;
}
void push(Stack &t ,node x )
{
    if(t.top==NULL)
    {
        t.top=x;
        return;
    }
    x->next=t.top;
    t.top=x;
}
void Convert( Stack &t, int number ,int base_number )
{
    
    while (number !=0)
    {
        int remainder = number % base_number;
        node n=CreateNode(remainder);
        push(t,n);
        number/=base_number;
    } 
}
void Display(Stack t)
{
    
    node i=t.top;
    while (i !=NULL)
    {
        switch (i->Data)
        {         
            case 10:
                cout<<'A';
                break;
            case 11:
                cout<<'B';
                break;
            case 12:
                cout<<'C';
                break;
            case 13:
                cout<<'D';
                break;
            case 14:
                cout<<'E';
                break;
            case 15:
                cout<<'F';
                break;
            default:
                cout<<i->Data;
                break;
        }
        i=i->next;
    }
        
}
int main(){
    int number,Base;
    Stack t;
    initStack(t);
    cout<<"Number decimal: ";
    cin>>number;
    cout<<"\nBase_N : ";
    cin>>Base;
    Convert(t,number,Base);
    cout<<"\nNumber Decimal Convert to "<<Base<<" is : ";
    Display(t);
    return 0;
}
    
