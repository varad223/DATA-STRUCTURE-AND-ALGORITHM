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
int i;
for(i=0;pf[i]!=NULL;i++)
{}
i=i-1;
  for(;i>=0;i--)
  {
if(pf[i]=='+'||pf[i]=='-'||pf[i]=='*'||pf[i]=='/')
{
new1=new node;
new1->data=pf[i];
new1->l=pop();
new1->r=pop();
push(new1);
}
else
{
new1=new node;
new1->data=pf[i];
new1->l=NULL;
new1->r=NULL;
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
void noninOrder()
{
}
int main()
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
}
