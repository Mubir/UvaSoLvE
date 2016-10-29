
#include<iostream>
#include <list>
#include<stdio.h>
int indegree[100];
using namespace std;


class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    //indegree[w]++;
}

void Graph::BFS()
{

    list<int> queue;

    for(int i = 0; i < V; i++)
    {

        if(indegree[i]==0)
        {
            queue.push_back(i);
        }
    }
    list<int>::iterator i;
    list<int> q;
    while(!queue.empty())
    {

        int  s = queue.front();
        // cout << s << " ";
        queue.pop_front();
        q.push_back(s);

        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            indegree[*i]--;

            if(indegree[*i]==0)
            {
                queue.push_back(*i);
            }
        }
    }
    for(int i=0; i<V; i++)
    {
        cout<<(q.front()+1)<<" ";
        q.pop_front();
    }
    cout<<endl;
}


int main()
{
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);

    int N,M;
    while(1)
    {
        cin>>N;
        cin>>M;
        if(N==0 && M==0)
            return 0 ;
        for(int i=0; i<N; i++)
        {
            indegree[i]=0;
        }
        Graph g(N);
        int u,v;
        for(int i=0; i<M; i++)
        {
            cin>>u;
            cin>>v;
            g.addEdge(u-1,v-1);
            indegree[v-1]++;
        }
        g.BFS();
    }
    return 0;
}
