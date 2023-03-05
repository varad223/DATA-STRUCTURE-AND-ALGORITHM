//Assignment no 1
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
int partition(struct student s[10],int l,int r)
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
	}
int main()
{
	int ch;


	do
	{
		cout<<"\n-----------------------------";
		cout<<"\n1:Create Database";
		cout<<"\n2:Display Database";
		cout<<"\n3:Search By Marks";
		cout<<"\n4:Search By Name";
		cout<<"\n5:Sort By Roll no(bubble sort)";
		cout<<"\n6:Display the first 3 toppers";
		cout<<"\n7:EXIT";
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
				cout<<"\nEnter the marks:- ";
				cin>>m;
				for(int i=0;i<n;i++)
				{

					if(m==s[i].marks)
					{
					cout<<"\n**********student database***********";
					cout<<"\nRoll no\t\tName\t\tMarks";
					cout<<"\n"<<s[i].rollno<<"\t\t"<<s[i].name<<"\t\t"<<s[i].marks<<"\n";
					}
				}
			break;
			}
			case 4:
			{
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
			case 5:
			{
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
				break;
			}
			case 6:
			{
				cout<<n-1;
				quick_sort(s,0,n-1);
			for(int i=n-1;i>=n-3;i--)
				{
					cout<<"\n"<<s[i].rollno<<"\t\t"<<s[i].name<<"\t\t"<<s[i].marks;
				}
				break;
			}
		}
	}while(ch!=7);
}


				/*OUTPUT
-----------------------------
1:Create Database
2:Display Database
3:Search By Marks
4:Search By Name
5:Sort By Roll no(bubble sort)
6:Display the first 3 toppers
7:EXIT
-----------------------------
Enter your choice: 1

Enter no of student: 5

Enter the data:
--------------------------------------
enter roll no: 78

enter name: aaa

enter marks: 65

--------------------------------------
--------------------------------------
enter roll no: 12

enter name: ccc

enter marks: 85

--------------------------------------
--------------------------------------
enter roll no: 2

enter name: eee

enter marks: 80

--------------------------------------
--------------------------------------
enter roll no: 22

enter name: fff

enter marks: 78

--------------------------------------
--------------------------------------
enter roll no: 32

enter name: hhh

enter marks: 90

--------------------------------------
-----------------------------
1:Create Database
2:Display Database
3:Search By Marks
4:Search By Name
5:Sort By Roll no(bubble sort)
6:Display the first 3 toppers
7:EXIT
-----------------------------
Enter your choice: 2

**********student database***********
Roll no		Name		Marks
*************************************
78		aaa		65
12		ccc		85
2		eee		80
22		fff		78
32		hhh		90
-----------------------------
1:Create Database
2:Display Database
3:Search By Marks
4:Search By Name
5:Sort By Roll no(bubble sort)
6:Display the first 3 toppers
7:EXIT
-----------------------------
Enter your choice: 3

Enter the marks:- 80

**********student database***********
Roll no		Name		Marks
2		eee		80

-----------------------------
1:Create Database
2:Display Database
3:Search By Marks
4:Search By Name
5:Sort By Roll no(bubble sort)
6:Display the first 3 toppers
7:EXIT
-----------------------------
Enter your choice: 4
Enter a name want to search: ccc
Student present at position: 2
12		ccc		85
-----------------------------
1:Create Database
2:Display Database
3:Search By Marks
4:Search By Name
5:Sort By Roll no(bubble sort)
6:Display the first 3 toppers
7:EXIT
-----------------------------
Enter your choice: 5

-----------------------------
1:Create Database
2:Display Database
3:Search By Marks
4:Search By Name
5:Sort By Roll no(bubble sort)
6:Display the first 3 toppers
7:EXIT
-----------------------------
Enter your choice: 2

**********student database***********
Roll no		Name		Marks
*************************************
2		eee		80
12		ccc		85
22		fff		78
32		hhh		90
78		aaa		65
-----------------------------
1:Create Database
2:Display Database
3:Search By Marks
4:Search By Name
5:Sort By Roll no(bubble sort)
6:Display the first 3 toppers
7:EXIT
-----------------------------
Enter your choice: 6
4
32		hhh		90
12		ccc		85
2		eee		80
-----------------------------
1:Create Database
2:Display Database
3:Search By Marks
4:Search By Name
5:Sort By Roll no(bubble sort)
6:Display the first 3 toppers
7:EXIT
-----------------------------
Enter your choice: 2

**********student database***********
Roll no		Name		Marks
*************************************
78		aaa		65
22		fff		78
2		eee		80
12		ccc		85
32		hhh		90
-----------------------------
1:Create Database
2:Display Database
3:Search By Marks
4:Search By Name
5:Sort By Roll no(bubble sort)
6:Display the first 3 toppers
7:EXIT
-----------------------------
Enter your choice: 7
(base) mmt-1@mmt1-OptiPlex-390:~/varad64it$ */
