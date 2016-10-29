#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u,int v);
    void topology(int v,stack<int > &Q,bool visited[]);
    void dfsTopology();
};

Graph::Graph(int V)
{
    this->V=V+1;
    adj=new list<int>[V+1];
}
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}

void Graph::topology(int v,stack<int> &Q,bool visited[])
{
    visited[v]=true;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
        {
            topology(*i,Q,visited);
        }
    }
    Q.push(v);

}

void Graph::dfsTopology()
{
    bool *visited=new bool[V];
    stack<int> Q;
    for(int i=0;i<V;i++)
        visited[i]=false;

    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
            topology(i,Q,visited);
    }
    while(!Q.empty())
    {//cout<<"hello "<<endl;
        if(Q.top()!=0)
        cout<<Q.top()<<" ";
        Q.pop();
    }
    cout<<endl;
}


int main()
{
   int N,M,u,v;
    while(true){

        cin>>N;

    Graph g(N);
    if(N==0 && M==0)
        return 0 ;
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>u;cin>>v;
        g.addEdge(u,v);
    }
    g.dfsTopology();

    }



    return 0;
}
