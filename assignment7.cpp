//Assignment No 7
#include<iostream>
using namespace std;
struct graph
{
	int s,d,c;
}
graph[10],mst[10];
int n=0,mn=0;

int main()
{
	cout<<"Enter the no of edges: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the source: ";
		cin>>graph[i].s;
		cout<<"Enter the destination: ";
		cin>>graph[i].d;
		cout<<"Enter the edge value: ";
		cin>>graph[i].c;
	}
//bubblesort
	struct graph temp;
	for(int i = 1; i<n; i++)
	{
		for(int j = 0; j<n-i; j++)
		{


			if(graph[j].c>graph[j+1].c)
			{
				temp = graph[j];
				graph[j] = graph[j+1];
				graph[j+1] = temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
	int sflag=0,dflag=0;
		for(int j=0;j<mn;j++)
		{
		if(graph[i].s==mst[j].s || graph[i].s==mst[j].d)
		{
			sflag=1;
		}
		if(graph[i].d==mst[j].d || graph[i].d==mst[j].s)
		{
			dflag=1;
		}}
		if(sflag==0 || dflag==0)
		{
		mst[mn]=graph[i];
		mn++;
		}

	}

	cout<<"\nthe Graph is:\n";
		cout<<"Src\tDest\tCost";
		for(int i=0;i<n;i++)
		{

			cout<<"\n"<<graph[i].s<<"\t"<<graph[i].d<<"\t"<<graph[i].c;
		}
		cout<<"\nthe mst is:\n";
		cout<<"Src\tDest\tCost";
		for(int i=0;i<mn;i++)
		{

			cout<<"\n"<<mst[i].s<<"\t"<<mst[i].d<<"\t"<<mst[i].c;
		}


}
