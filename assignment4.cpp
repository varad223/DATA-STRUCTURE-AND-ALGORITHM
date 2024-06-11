//Assignment No 4
#include<iostream>
using namespace std;
struct node
{
char data;
struct node*l,*r;
};
char pf[10];
int top=-1;
node*stack[20];
void push(node *tree)
{
top++;
stack[top]=tree;
}
node*pop()
{
top--;
return(stack[top+1]);
}
void exptre()
{
node*new1;
for(int i=0;pf[i]!='\0';i++)
{
if(pf[i]=='+'||pf[i]=='-'||pf[i]=='*'||pf[i]=='/')
{
new1=new node;
new1->data=pf[i];
new1->r=pop();
new1->l=pop();
push(new1);
}
else
{
new1=new node;
new1->data=pf[i];
new1->r=NULL;
new1->l=NULL;
push(new1);
}
}}
void exptrep()
{
node*new1;
for(int i=0;pf[i]!='\0';i++)
{
if(pf[i]=='+'||pf[i]=='-'||pf[i]=='*'||pf[i]=='/')
{
  new1=new node;
  new1->data=pf[i];
  new1->r=NULL;
  new1->l=NULL;
  push(new1);
  }
else
{
new1=new node;
new1->data=pf[i];
new1->r=pop();
new1->l=pop();
push(new1);
}
}}
void preorder(node*tree)
{
if(tree!=NULL)
{
cout<<tree->data;
preorder(tree->l);
preorder(tree->r);
}
}
void inorder(node*tree)
{
if(tree!=NULL)
{
inorder(tree->l);
cout<<tree->data;
inorder(tree->r);
}
}
void postorder(node*tree)
{
if(tree!=NULL)
{
postorder(tree->l);
postorder(tree->r);
cout<<tree->data;
}
}
int main()
{
  int ch;
  do
  {
    cout<<"\n-----------------------------";
    cout<<"\n1:postfix operations";
    cout<<"\n2:prefix operations";
    cout<<"\n-----------------------------";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {

        cout<<"\nEnter the postfix expression: ";
        cin>>pf;
        exptre();
        cout<<"\npreorder expresion is: ";
        preorder(stack[0]);
        cout<<"\npostorder expression is: ";
        postorder(stack[0]);
        cout<<"\ninorder expression is: ";
        inorder(stack[0]);
        cout<<"\n";
        return 0;
        break;
      }
      case 2:
      {

        cout<<"\nEnter the prefix expression: ";
        cin>>pf;
        exptrep();
        cout<<"\npreorder expresion is: ";
        preorder(stack[0]);
        cout<<"\npostorder expression is: ";
        postorder(stack[0]);
        cout<<"\ninorder expression is: ";
        inorder(stack[0]);
        cout<<"\n";
        return 0;
        break;
      }
    }
	}while(ch!=3);
}
