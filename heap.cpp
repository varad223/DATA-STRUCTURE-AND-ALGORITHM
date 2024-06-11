#include <iostream>
using namespace std;
void MaxHeapify(int a[],int i,int n)
{
int j,temp;
temp=a[i];
j=2*i;
while(j<=n)
{
  if(j<n && a[j+1]>a[j])
  j=j+1;
  if(temp>a[j])
  break;
  else if(temp<=a[j])
  {
    a[j/2]=a[j];
    j=2*j;
  }
}
a[j/2]=temp;
return;
}
void buildmaxheap(int a[],int n)
{
  int i;
  for(i=n/2;i>=1;i--)
  MaxHeapify(a,i,n);
}
void maxheapsort(int a[],int n)
{
  int i,temp;
  for(i=n;i>=2;i--)
  {
    temp=a[i];
    a[i]=a[1];
    a[1]=temp;
    MaxHeapify(a,1,i-1);
  }
}
void MinHeapify(int a[],int i,int n)
{
int j,temp;
temp=a[i];
j=2*i;
while(j<=n)
{
  if(j<n && a[j+1]<a[j])
  j=j+1;
  if(temp<a[j])
  break;
  else if(temp>=a[j])
  {
    a[j/2]=a[j];
    j=2*j;
  }
}
a[j/2]=temp;
return;
}
void buildminheap(int a[],int n)
{
  int i;
  for(i=n/2;i>=1;i--)
  MinHeapify(a,i,n);
}
void minheapsort(int a[],int n)
{
  int i,temp;
  for(i=n;i>=2;i--)
  {
    temp=a[i];
    a[i]=a[1];
    a[1]=temp;
    MinHeapify(a,1,i-1);
  }
}
void print(int arr[],int n)
{
  cout<<"\nSorted data";
  for(int i=1;i<=n;i++)
  cout<<"->"<<arr[i];
  return;
}
int main()
{
  int ch,n,i;
  cout<<"enter the no of element:";
  cin>>n;
  int arr[n];
  for(i=1;i<=n;i++)
  {
    cout<<"enter element: ";
    cin>>arr[i];
  }
  do {
    cout<<"\n1.Heap sort using max heap";
    cout<<"\n2.Heap sort using min heap";
    cout<<"\n3.Exit";
    cout<<"\nEnter your choice:";
    cin>>ch;
    switch(ch)
    {
      case 1:buildmaxheap(arr,n);
      maxheapsort(arr,n);
      print(arr,n);
      break;
      case 2:buildminheap(arr,n);
      minheapsort(arr,n);
      print(arr,n);
      break;
      case 3:return 0;
      default:cout<<"\nInvalid choice!!Please enter your choice again"<<endl;
    }
  } while(ch!=3);
}
