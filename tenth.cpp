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
node *droot=NULL;
node *mroot=NULL;
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
void leafnode(node *root)
{
	if (root!=NULL)
	{
	    display(root->l);
	    if(root->l==NULL && root->r==NULL)
	    {
	    cout << root->data;
	    }
	    cout<<"\n";
	    display(root->r);
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
		cout<<"\n3:Search";
		cout<<"\n4:Display leaf nodes";
		cout<<"\n5:EXIT";
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
				cout<<"Enter element you want to serach: ";
				cin>>value;
				search(root,value);
				break;
			}
			case 4:
			{
				cout<<"\nLeaf nodes in tree is: ";
				leafnode(root);
				break;
			}
			case 5:
			{
					cout<<"THANK YOU";
				break;
			}
		}
	}while(ch!=5);
}
