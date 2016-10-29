#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<stdio.h>

using namespace std;
#define N 201
int adj[N][N];

int heavyCargo(int n,int str,int ed);

int main()
{
   // freopen("input.txt","r",stdin);
    int n,r,cas = 1;
    string str1,str2;
    while(cin>>n>>r)
    {
        if(n==0)
            break;
        int cnt=0,w;
        map<string,int> city;
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                adj[i][j]=0;

        for(int i=0; i<r; i++)
        {
            cin>>str1>>str2>>w;
            if(!city.count(str1))
                city[str1]= cnt++;
            if(!city.count(str2))
                city[str2]= cnt++;
            adj[city[str1]][city[str2]]= adj[city[str2]][city[str1]]= w;


        }
        for(int k=0;k<n;k++)
         for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(adj[i][k] && adj[k][j])
                adj[i][j]=max(adj[i][j],min(adj[i][k],adj[k][j]));

        cin>>str1>>str2;
        cout<<"Scenario #"<<cas++<<endl<<adj[city[str1]][city[str2]]<<" tons"<<endl<<endl;
    }
}

int heavyCargo(int n,int str,int ed)
{
    queue <int > Q;
    bool visited[N]= {};
    int weight[N]= {};
    Q.push(str);

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int v=1; v<=n; v++)
        {
         if(adj[u][v])
         {
             int mx=weight[u]?min(adj[u][v],weight[u]):adj[u][v];
             if(mx>weight[v])
             {
                 weight[v]=mx;
                 if(!visited[v])
                 {
                     Q.push(v);
                     visited[v]=true;
                 }
             }
         }
        }
    }
return weight[ed];
}
