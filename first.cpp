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
//quick_sort started
int partition(struct student s[10],int l,int r)
{
	int i,j;

	struct student temp,pivot;
	pivot=s[l];
	i=l+1;
	j=r;
	do
	{
		while(s[i].rollno<pivot.rollno && i<=r)
		{
			i++;
		}
		while(s[j].rollno>pivot.rollno)
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
	}
int main()
{
	int ch;
	do
	{
		cout<<"\n-----------------------------";
		cout<<"\n1:Create Database";
		cout<<"\n2:Display Database";
		cout<<"\n3:Search By roll no";
		cout<<"\n4:Display the first 3 toppers(quick sort)";
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
			{
				float m;
				cout<<"\nEnter the roll no:- ";
				cin>>m;
				for(int i=0;i<n;i++)
				{

					if(m==s[i].rollno)
					{
					cout<<"\n**********student database***********";
					cout<<"\nRoll no\t\tName\t\tMarks";
					cout<<"\n"<<s[i].rollno<<"\t\t"<<s[i].name<<"\t\t"<<s[i].marks<<"\n";
					}
				}
			break;
			}
				case 4:
			{//quick sort

				quick_sort(s,0,n-1);
			cout<<"\n**********student database***********";
				cout<<"\nRoll no\t\tName\t\tMarks";
				cout<<"\n*************************************";
				for(int i=0;i<n;i++)
				{
					cout<<"\n"<<s[i].rollno<<"\t\t"<<s[i].name<<"\t\t"<<s[i].marks;
				}
				break;
			}
		}
	}while(ch!=5);
}
