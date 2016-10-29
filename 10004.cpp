#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int v);
    void addEdge(int u,int v);
    bool isBioconnected();
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}
void Graph::addEdge(int u,int v)
{
    //cout<<" Adding edge "<<endl;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool Graph::isBioconnected()
{
    //cout<<"WTF....  22 \n";
    int color[V];
    for(int i=0; i<V; i++)
        color[i]=-1;
    color[0]=1;
    queue <int> q;
    q.push(0);
    //cout<<" 0 entering.."<<endl;
    list<int>::iterator i;
    while(!q.empty())
    {
        //cout<<" entering.."<<endl;
        int u=q.front();
        q.pop();
        for(i=adj[u].begin(); i!=adj[u].end(); i++)
        {
            if(color[*i]==-1)
            {
                color[*i]=1-color[u];
                //cout<<u<<" Color : "<<color[u]<<"\t"<<*i<<" Color : "<<color[*i]<<endl;
                q.push(*i);
            }
            else if(color[*i]==color[u])
            {
                // cout<<u<<" Color : "<<color[u]<<"\t"<<*i<<" Color : "<<color[*i]<<endl;
                return false;
            }

        }
    }
    return true;
}


int main()
{
    int N,p,a,b;


    /* if(V>((N*(N-1))/2))
         return 0;*/

    while(true)
    {
         cin>>N;
    Graph g(N);
        if(N<=0)
           return 0;
       cin>>p;
        for(int i=0; i<p; i++)
        {
            // cout<<"WTF....";
            cin>>a;
            cin>>b;

            g.addEdge(a,b);
        }
        g.isBioconnected()?cout<<"BICOLORABLE."<<endl:cout<<"NOT BICOLORABLE."<<endl;
    }

}
