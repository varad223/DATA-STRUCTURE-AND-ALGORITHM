#include <iostream>
#include <cstring>
using namespace std;
struct student
{
	int rollno;
	char name[10];
	float marks;
};
struct student s[10];
int n;
/*int partition(struct student s[10],int l,int r)
{
	int i,j;

	struct student temp,pivot;
	pivot=s[l];
	i=l+1;
	j=r;
	do
	{
		while(s[i].marks<pivot.marks && i<=r)
		{
			i++;
		}
		while(s[j].marks>pivot.marks)
		{
			j--;
		}
		if(i<j)
		{
			temp=s[i];
			s[i]=s[j];
			s[j]=temp;
		}
	}while(i<j);
	temp=pivot;
	s[l]=s[j];
	s[j]=temp;
	return(j);
}
void quick_sort(struct student s[10],int l,int r)
	{
		int j;
		if(l<r)
		{
			j=partition(s,l,r);
			quick_sort(s,l,j-1);
			quick_sort(s,j+1,r);
		}
	}*/
int main()
{
	int ch;
	do
	{
		cout<<"\n-----------------------------";
		cout<<"\n1:Create Database";
		cout<<"\n2:Display Database";
		cout<<"\n3:Sort By Roll no(bubble sort)";
		cout<<"\n4:Search By Name(binary search)";
		cout<<"\n5:EXIT";
		cout<<"\n-----------------------------";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{

				cout<<"\nEnter no of student: ";
				cin>>n;
				cout<<"\nEnter the data: ";
				for(int i=0;i<n;i++)
				{
					cout<<"\n--------------------------------------";
					cout<<"\nenter roll no: ";
					cin>>s[i].rollno;
					cout<<"\nenter name: ";
					cin>>s[i].name;
					cout<<"\nenter marks: ";
					cin>>s[i].marks;
					cout<<"\n--------------------------------------";
				}
			break;
			}
			case 2:
			{
				cout<<"\n**********student database***********";
				cout<<"\nRoll no\t\tName\t\tMarks";
				cout<<"\n*************************************";
				for(int i=0;i<n;i++)
				{
					cout<<"\n"<<s[i].rollno<<"\t\t"<<s[i].name<<"\t\t"<<s[i].marks;
				}
			break;
			}
			case 3:
			{//bubble sort
				struct student temp;
				for(int j=1;j<n;j++)
				{
				for(int i=0;i<n-j;i++)
				{
					if(s[i].rollno>s[i+1].rollno)
					{
						temp=s[i];
						s[i]=s[i+1];
						s[i+1]=temp;
					}
				}
				}
				cout<<"\n**********student database***********";
				cout<<"\nRoll no\t\tName\t\tMarks";
				cout<<"\n*************************************";
				for(int i=0;i<n;i++)
				{
					cout<<"\n"<<s[i].rollno<<"\t\t"<<s[i].name<<"\t\t"<<s[i].marks;
				}
				break;
			}
			case 4:
			{//binary search
				char x[10];
				int i=0,j=(n-1),mid,flag=0;
				cout<<"Enter a name want to search: ";
				cin>>x;
				while(i<=j)
				{
					int mid=(i+j)/2;
					if(strcmp(x,s[mid].name)==0)
					{
						cout<<"Student present at position: "<<mid+1;
						cout<<"\n"<<s[mid].rollno<<"\t\t"<<s[mid].name<<"\t\t"<<s[i].marks;
						flag=1;
						break;
					}
					else if(strcmp(x,s[mid].name)>0)
					{
						i=mid+1;
					}
					else if(strcmp(x,s[mid].name)<0)
					{
						j=mid-1;
					}
				}
				if(flag==0)
				cout<<"\nStudent is not present in the data";
				break;
			}
		}
	}while(ch!=5);
}
