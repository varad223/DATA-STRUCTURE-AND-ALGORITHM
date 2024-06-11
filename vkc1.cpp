//Assignment No 2 previous in linkedlist.cpp
#include <iostream>
using namespace std;
struct node
{
	char data;
	struct node*next;
};
class stack
{
	public:
	struct node*top;
	stack()
	{
		top=NULL;
	}
	void push(int x)
	{
	node*temp;
	temp=new node();
	temp->data=x;
		if(IsEmpty())
		{
			temp->next=NULL;
			top=temp;
		}
		else
		{
			temp->next=top;
			top=temp;
		}
	}
	int IsEmpty()
	{
		if(top==NULL)
		return(1);
		else
		return(0);
	}
	char pop()
	{
		node*p;
		int x;
		if(!IsEmpty())
		{
			x=top->data;
			p=top;
			top=top->next;
			delete(p);

		}return(x);
	}
};
int main()
{
int n,ch;
	stack s;
	do
	{
	cout<<"\n-----------------------------";
		cout<<"\n1:push";
		cout<<"\n2:pop";
		cout<<"\n3:EXIT";
		cout<<"\n-----------------------------";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"\nEnter the no to push:";
				cin>>n;
				s.push(n);
			break;
			}
			case 2:
			{
				cout<<"\nPop item is: "<<s.pop();
				cout<<"\nPop item is: "<<s.pop();
			break;
			}

		}
	}while(ch!=3);
	cout<<"------THANK YOU------";
}
