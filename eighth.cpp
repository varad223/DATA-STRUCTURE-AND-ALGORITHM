#include<iostream>
using namespace std;
struct node
{
	int data;
	node *l,*r;
};
int arr[10];
int n;
node *root=NULL;
node *croot=NULL;
node *addnode(node *troot,int val)
{
	if(troot==NULL)
	{
	node *new1=new node;
	new1->data=val;
	new1->l=NULL;
	new1->r=NULL;
	return new1;
	}
	if(troot->data > val)
	{
		troot->l=addnode(troot->l,val);
	}
	else
	{
		troot->r=addnode(troot->r,val);
	}
	return troot;
}
void createtree()
{
	cout<<"Enter the no of elements want to insert: ";
	cin>>n;
	cout<<"Enter numbers:";
	for(int i=0;i<n;i++)
	{
	cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		root=addnode(root,arr[i]);
	}
}
void display(node *root)
{
	if (root!=NULL)
	{
	    display(root->l);
	    cout << root->data;
	    cout<<"\n";
	    display(root->r);
  }
}
void search(node *troot,int value)
{
	if(troot==NULL)
	{
		cout<<"Not found";
	}
	else if(troot->data==value)
	{
		cout<<"found";
	}
	else if(troot->data>value)
	{
		search(troot->l,value);
	}
	else
	{
		search(troot->r,value);
	}
}
node *deletenode(node *croot,int value)
{
	if(croot==NULL)
	{
		cout<<"Not found";
	}
	else if(croot->data==value)
	{
		cout<<"found";
	}
	else if(croot->data>value)
	{
		search(croot->l,value);
	}
	else
	{
		if((croot->l=NULL) && (croot->r==NULL))
		{
			return NULL;
		}
		else if(croot->l==NULL)
		{
			return croot->r;
		}
		else if(croot->r==NULL)
		{
			return croot->l;
		}
		else
		{
		    struct node*temp;
			temp=croot->r;
			while(temp->l!=NULL)
			temp=temp->l;
			croot->data=temp->data;
			return deletenode(croot->r,temp->data);
		}
	}
}
int main()
{
    int ch;
	do
	{
		cout<<"\n-----------------------------";
		cout<<"\n1:Insert the element";
		cout<<"\n2:Display tree";
		cout<<"\n3:Delete Element";
		cout<<"\n4:EXIT";
		cout<<"\n-----------------------------";
		cout<<"\nenter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
			    createtree();
			    break;
			}
			case 2:
			{
				cout<<"\nbinary search tree is: ";
				display(root);
				break;
			}
			case 3:
			{
			   int value;
				cout<<"Enter element you want to delete: ";
				cin>>value;
				deletenode(croot,value);
				break;
			}
			case 4:
			{
					cout<<"THANK YOU";
				break;
			}
		}
	}while(ch!=4);
}
