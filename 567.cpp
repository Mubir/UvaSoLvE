#include<iostream>
#include<list>
#include<queue>
#include<stdio.h>
using namespace std;
queue<int>Q;
list<int> *adj;
int cost[21];
int BFS(int source,int dest)
{
    bool visited[21];


    for(int i=0; i<=20; i++)
    {
        visited[i]=false;
        cost[i]=0;
    }
    visited[source]=true;
    cost[source]=0;
    Q.push(source);
    int u;
list<int>::iterator i;
    while(!Q.empty())
    { // cout<<"working";
        u=Q.front();
        Q.pop();
     // cout<<u<<endl;

        for(i=adj[u].begin(); i!=adj[u].end(); i++)
        {
           // if(!visited[*i] && *i!=dest)
           if(!visited[*i])
            {
                visited[*i]=true;
                cost[*i]=cost[u]+1;
               // cout<<"\n$$ "<<cost[*i];
                Q.push(*i);
            }
        /*  else if(*i==dest)
            {
                visited[*i]=true;
              //  cout<<" \n\n** got it boy"<<*i<<" ==  "<<dest<<"  ++ ";
                cost[*i]=cost[u]+1;
               // cout<<cost[u];
                return cost[*i];
            }*/
        }
    }
    //return 0;
}

int main()
{

freopen("input.txt","r",stdin);
////freopen("output.txt","w",stdout);
    int i, j, k, test = 0;
    int n;
    while(scanf("%d", &n) == 1)
    {
        //int adj[21][21] = {};
 Q={};
        adj=new list<int>[21];
        for(i = 1; i <= 19; i++)
        {
            if(i != 1)
                cin>>n;
            while(n--)
            {//cout<<"main"<<endl;
                cin>>k;
                adj[i].push_back(k) ;
                adj[k].push_back(i);
            }
        }
        cin>>n;
        //cout<<"Test Set # "<<++test<<endl;
        printf("Test Set #%d\n", ++test);
        while(n--)
        {
           cin>>i>>j;
           // cout<<" ";
            //int sh=BFS(i,j);
           BFS(i,j);
            printf("%2d to %2d: %d\n", i, j,cost[j]);

            //printf("%2d to %2d: %d\n", i, j,BFS(i,j));
          // cout<<i<<" to "<<j<<" : "<<cost[j]<<endl;
        }
         cout<<endl;
    }
}
