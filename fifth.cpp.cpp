//Assignment No 3
#include<iostream>
using namespace std;
int cqueue[5];
int front=0,rear=0,n=5;

void insertq(int val)
{
  if(((rear+1)%n)==front)
  {
      cout<<"Queue is full"<<endl;
      return;
  }
  else
  {
      cqueue[rear]=val;
      rear=(rear+1)%n;
  }
}
void deleteq()
{
  if(front==rear)
  {
    cout<<"Queue is empty"<<endl;
  }
  else
  {
    cout<<"The element deleted is: "<<cqueue[front];
    front=((front+1)%n);
  }
}
void display()
{
   for(int i=front;i!=rear;i=((i+1)%n))
   {
   cout<<"The element inserted is:"<<cqueue[front];
   }
}

int main()
{
  int ch,val;
cout<<"\n1)Insert\n2)Delete\n3)Display\n4)Exit";
do {
   cout<<"\nEnter choice : ";
   cin>>ch;
   switch(ch) {
      case 1:
      cout<<"Input for insertion: ";
      cin>>val;
      insertq(val);
      break;

      case 2:
      deleteq();
      break;

      case 3:
      display();
      break;

      case 4:
      cout<<"Exit";
      break;
      default: cout<<"Incorrect!";
   }
} while(ch != 4);
return 0;
}
