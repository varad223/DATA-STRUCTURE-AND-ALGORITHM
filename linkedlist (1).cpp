//Assignment NO 2 next in VKC1.cpp
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};

struct node *head=NULL;

void create ()
{
	struct node *p;
	p = new node();
	cout<<"\n Enter Node    : ";
	cin>>p->data;
	p->next =NULL;
	head = p;
}
void display ()
{
	node* p;
	p=head;

	while (p!=NULL)
	{
		cout<<p->data<<"  ";
		p=p->next;
	}
}

struct node *insert_first(node *head,int x)
{
	node *p;
	p= new node();
	p->data=x;
	p->next=head;
	head=p;
	return(head);
}

struct node *insert_middle(node *head,int x)
{
	int n;
	node *p,*q,*r;
	p=new node();
	p->data=x;
	q=head;
	cout<<"\n Enter node after which new node to be involved  : ";
	cin>>n;
	while(q->data!=n)
	{
		q=q->next;
	}
	r=q->next;
	q->next=p;
	p->next=r;
	return(head);
}
struct node *insert_last(node *head,int x)
{
	node *p,*q;
	p=new node();
	p->data=x;
	p->next=NULL;
	q=head;
	while(q->data!=NULL)
	{
		q=q->next;
	}
	q->next=p;

	return(head);
}
int main()
{
	int ch,x;
	do
	{
		cout<<"\n*********************MENU*********************";
		cout<<"\n1) Create \n2) Display \n3) Enter First Node \n4) Enter Middle Node \n5) Exit";
		cout<<"\nEnter Your choise   : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				create();
			break;

			case 2:
				display();
			break;

			case 3:
				cout<<"Enter Node Data ";
				cin>>x;
				head=insert_first(head, x);
			break;
			case 4:
				cout<<"Enter Middle Data ";
				cin>>x;
				head=insert_middle(head, x);
			break;
		}
	}while(ch!=5);
}
