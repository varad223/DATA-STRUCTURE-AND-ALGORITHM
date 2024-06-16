#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
typedef struct student
{
  int rollno;
  char div,name[20],add[30];
}stud;
void create();
void display();
void insert();
void search(int key);
void delete1(int key);
void modify(int key);

int main()
{
  int ch,x;
  do {
    cout<<"\n\t***MENU***\n1.Accept\n2.Display\n3.Insert\n4.Search\n5.Delete\n6.Modify\n7.Exit\nEnter your chioce: ";
    cin>>ch;
    switch(ch)
    {
      case 1:create();
      break;
      case 2:display();
      break;
      case 3:insert();
      break;
      case 4:cout<<"Enter roll no to search=";
      cin>>x;
      search(x);
      break;
      case 5:cout<<"Enter roll no to delete=";
      cin>>x;
      delete1(x);
      break;
      case 6:cout<<"Enter roll no to Modify=";
      cin>>x;
      modify(x);
      break;
    }
  } while(ch!=7);
  return 0;
}
ifstream fin;
ofstream fout;
fstream fm;
int n;
char fname[20];
void create()
{
  int i;
  stud s;
  cout<<"Enter name of file: ";
  cin>>fname;
  fin.open(fname,ios::out);
  cout<<"\n Enter no. of records:=";
  cin>>n;
  for(int i;i<n;i++)
  {
    cout<<"Enter roll no: ";
    cin>>s.rollno;
    cout<<"Enter name: ";
    cin>>s.name;
    cout<<"Enter division: ";
    cin>>s.div;
    cout<<"Enter Address: ";
    cin>>s.add;
    fm.write((char*)&s,sizeof(s));
  }
  fm.close();
}
void display()
{
  int i;
  stud s;
  fin.open(fname);
  cout<<"\nROLL NO\tNAME\tDIV\tADDRESS";
  //while(!fin.eof())
  for(int i=0;i<n;i++)
  {
    fin.read((char*)&s,sizeof(s));
    cout<<"\n"<<s.rollno<<"\t"<<s.name<<"\t"<<s.div<<"\t"<<s.add;
  }
  fin.close();
}
void insert()
{
  stud s;
  fout.open(fname,ios::app);
  cout<<"Enter roll no: ";
  cin>>s.rollno;
  cout<<"Enter name: ";
  cin>>s.name;
  cout<<"Enter division: ";
  cin>>s.div;
  cout<<"Enter Address: ";
  cin>>s.add;
  fout.write((char*)&s,sizeof(s));
  n++;
  fout.close();
}
void search(int key)
{
  stud s;
  int flag=0,i;
  fin.open(fname);
  for(int i=0;i<n;i++)
  {
    fin.read((char*)&s,sizeof(s));
    if(s.rollno==key)
    {
      cout<<"\nRecord is present their corresponding details are:";
      cout<<"\n"<<s.rollno<<"\t"<<s.name<<"\t"<<s.div<<"\t"<<s.add;
      flag=1;
    }
  }
  if(flag==0)
  cout<<"\nRoll no="<<key<<"is not present";
  fin.close();
}
void delete1(int key)
{
  stud s;
  int flag=0,i;
  fin.open(fname);
  fout.open("temp.txt",ios::out);
  for(int i=0;i<n;i++)
  {
    fin.read((char*)&s,sizeof(s));
    if(s.rollno==key)
    {
      cout<<"\nRecord is deleted ";
      flag=1;
    }
    else
    {
      fout.write((char*)&s,sizeof(s));
    }
  }
  if(flag==0)
  cout<<"\nRoll no="<<key<<"is not present";
  else
  n--;
  fin.close();
  fout.close();
  remove(fname);
  rename("temp.txt",fname);
}
void modify(int key)
{
  stud s;
  int flag=0,i;
  fin.open(fname);
  fout.open("temp.txt",ios::out);
  for(int i=0;i<n;i++)
  {
    fin.read((char*)&s,sizeof(s));
    if(s.rollno==key)
    {
      cout<<"Enter roll no: ";
      cin>>s.rollno;
      cout<<"Enter name: ";
      cin>>s.name;
      cout<<"Enter division: ";
      cin>>s.div;
      cout<<"Enter Address: ";
      cin>>s.add;
      fout.write((char*)&s,sizeof(s));
      flag=1;
    }
    else
    {
      fout.write((char*)&s,sizeof(s));
    }
  }
  if(flag==0)
  cout<<"\nRoll no="<<key<<"is not present";
  fin.close();
  fout.close();
  remove(fname);
  rename("temp.txt",fname);
}
