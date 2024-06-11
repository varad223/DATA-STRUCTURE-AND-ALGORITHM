#include<cstring>
#include<iostream>
using namespace std;
#define INF 9999999*****************
#define V 5
int G[V][V]={{0,4,0,5,2},{4,0,1,3,0},{0,1,0,8,0},{5,3,8,0,2},{2,0,0,2,0}};
int main()
{
	int no_edges;
	int selected[V];
	memset(selected,false,sizeof(selected));
	no_edges=0;
selected[0]=true;
int r;
int c;
cout<<"EDGE"<<":"<<"Weight";
cout<<endl;
while(no_edges<V-1)
{
r=0;
c=0;
int min=INF
//ddfsdfs
for(int i=0;i<V;i++)
{
	if(selected[i])
	{
		for(int j=0;j<V;j++)
		{
			if(selected[j]&&G[i][j])
			{
			if(min>G[i][j])
			{
				min=G[i][j];
				r=i;
				c=j;
			}
		}
		}
	}
}
cout<<r<<"-"<<c<<"-:"<<G[r][c];
cout<<endl;
selected[V]=true;
no_edges++;
}
return 0;
}
