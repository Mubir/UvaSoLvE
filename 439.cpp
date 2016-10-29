#include<iostream>
#include<queue>
#include<string>
#include<stdio.h>
using namespace std;
int dest[9][9];
int dx[]={2,  2, -2, -2, 1, -1,  1, -1};
int dy[]={1, -1,  1, -1, 2,  2, -2, -2};
bool color[9][9];
queue <pair<int,int> >Q;
bool isVisitable(pair<int ,int> v)
{
    if(v.first<=0 || v.second<=0 || v.first>8 || v.second>8 || color[v.first][v.second])
        return false;
    return true;
}
int KnightMove(int srcX,int srcY)
{
    pair<int ,int > u,v;
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            dest[i][j]=0;
            color[i][j]=false;
        }

        }
        Q.push(make_pair(srcX,srcY));
        dest[srcX][srcY]=0;
        color[srcX][srcY]=true;
        while(!Q.empty())
        {
            u=Q.front();
            Q.pop();
            for(int i=0; i<8; i++)
                {
                    v.first=u.first+dx[i];
                    v.second=u.second+dy[i];

                    if(!color[v.first][v.second] && isVisitable(v))
                    {
                        color[v.first][v.second]=true;
                        dest[v.first][v.second]=dest[u.first][u.second]+1;
                        Q.push(v);
                    }
                }
            }

 /*  for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            cout<<dest[i][j]<<" ";

        }
        cout<<endl;
        }*/
    }
   // for()

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    string s,d;
    int srcX,srcY,destX,destY;
    while(cin>>s>>d)
    {
        srcX=s[0]-'a'+1;
        srcY=s[1]-'0';
        destX=d[0]-'a'+1;
        destY=d[1]-'0';

        KnightMove(srcX,srcY);
        cout<<"To get from "<<s<<" to "<<d<<" takes "<<dest[destX][destY]<<" knight moves."<<endl;
    }
}
