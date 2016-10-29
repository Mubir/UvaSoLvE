#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#define MAX 1005
using namespace std;
int dx[]= {0,0,1,-1};
int dy[]= {-1,1,0,0};
queue<pair<int,int> > Q;
vector<vector<bool> > block;
bool color[MAX][MAX];
int dist[MAX][MAX];
int x,y;
bool isVisitable(pair<int,int> v)
{
if(v.first<0||v.first>=x || v.second<0||v.second>=y || block[v.first][v.second]==true)
    return false;
return true;
}
int BFS(int srcx,int srcy,int destx,int desty)
{

    pair<int ,int>u,v;
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
        {
            color[i][j]=false;
            dist[i][j]=-100;
        }
       color[srcx][srcy]=true;
       dist[srcx][srcy]=0;
       Q.push(make_pair(srcx,srcy));
       while(!Q.empty())
       {//cout<<"BFS  ";
           u=Q.front();
           Q.pop();
           for(int i=0;i<4;i++)
           {
               v.first=u.first+dx[i];
               v.second=u.second+dy[i];
               if(!color[v.first][v.second] && isVisitable(v))
               {
                   color[v.first][v.second]=true;
                  // cout<<"V "<<dist[v.first][v.second];
                   dist[v.first][v.second]=dist[u.first][u.second]+1;
                  // cout<<"*V "<<dist[v.first][v.second]<<endl;
                  // cout<<v.first<<"--- "<<v.second<<endl;
                   Q.push(v);
               }

           }
       }
      //for(int i=x; i>=0; i--)
     /* for(int i=0; i<x; i++)
      {
            for(int j=0; j<y; j++)
         //for(int j=y; j>=0; j--)
        {

            cout<<dist[i][j]<<"\t";
        }cout<<endl;
      }*/

return dist[destx][desty];
}
int main()
{
   /* freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    int srcx,srcy,destx,desty,blockrows,blocknum,blockposx,blockposy;

    while(cin>>x>>y)
    {
        if(x==0 && y==0)
            break;

        block=vector<vector<bool> > (x,vector<bool>(y,false));
              cin>>blockrows;
        while(blockrows--)
        {
            cin>>blockposx;
            cin>>blocknum;
            while(blocknum--)
            {
                cin>>blockposy;
                block[blockposx][blockposy]=true;
            }
        }
        cin>>srcx>>srcy>>destx>>desty;
    cout<<BFS(srcx,srcy,destx,desty)<<endl;
    }
}
