#include<iostream>
#include<math.h>
#include<string.h>
#include <iomanip>
#include<stdio.h>
using namespace std;

double point[100][2];
int n;
void findFricle()
{
    bool intree[100];
    double dist[100];
    double sum=0;
    memset(intree,0,sizeof(intree));
    for(int i=0;i<100;i++)
        dist[i]=10000;
double ax;
    int v=0;
    dist[v]=0;
    while(!intree[v])
    {
        intree[v]=1;sum+=dist[v];
        for(int i=0;i<n;i++)
        {
            if(!intree[i]){ax=sqrt(pow((point[v][0]-point[i][0]),2)+pow((point[v][1]-point[i][1]),2));
            if(ax<dist[i])
            {
                dist[i]=ax;
            }}

        }

        v=0;
        int mn=1000;

        for(int i=0;i<n;i++)
        {
            if(!intree[i] && dist[i]<mn)
            {
                v=i;
                mn=dist[i];
            }
        }
    }

   printf("%.2f",sum);
}

int main()
{


freopen("input.txt","r",stdin);
    int iter;
    double a,b;
    cin>>iter;
    while(iter--){

            cin>>n;

    for(int i=0;i<n;i++)
    {cin>>a>>b;
        point[i][0]=a;
        point[i][1]=b;
    }
    findFricle();
    cout<<endl<<endl;
    }



}
