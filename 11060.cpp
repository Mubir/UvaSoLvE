#include<iostream>
#include<stdio.h>
#include<list>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;
int indegree[201];
map<string,int> mi;
map<int,string> ms;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void BFSTOPOLOGY();
    void DFSTOPOLOGY(int i,bool* visited,stack<int> &queue);
    void DFS();
    void addEdge(char *u,char *v);
};

Graph::Graph(int V)
{
    this->V=V;
    adj = new list<int>[V];
}
void Graph::addEdge(char* u,char* v)
{
    adj[mi[u]].push_back(mi[v]);
}

void  Graph::BFSTOPOLOGY()
{
    list<int> queue;
    for(int i=0; i<V; i++)
    {
        if(indegree[i]==0)
        {
            queue.push_back(i);
            cout<<" Pushed id temp "<<ms[i]<<endl;
        }
    }
    for(int i=0; i<V; i++)
        cout<<ms[i]<<" : "<<indegree[i]<<endl;
    cout<<endl;
    list<int>:: iterator i;
    list<int> Q;
    while(!queue.empty())
    {
        int w=queue.front();
        queue.pop_front();
        Q.push_back(w);
        cout<<" pushing in main queue : "<<ms[w]<<endl;
        for(i=adj[w].begin(); i!=adj[w].end(); i++)
        {
            indegree[*i]--;
            cout<<"\n*** indegree of "<<ms[*i]<<"  --->>>>  "<<indegree[*i]<<"  for ( "<<ms[w]<<"--"<<ms[*i]<<endl;
            if(indegree[*i]==0)
            {
                cout<<"** in temp "<<ms[*i]<<endl;
                queue.push_back(*i);
            }
        }
    }
    for(int i=0; i<V; i++)
    {
        cout<<ms[Q.front()]<<" ";
        Q.pop_front();
    }
    cout<<endl;
}
void Graph::DFSTOPOLOGY(int u,bool* visited,stack<int> &queue)
{

    visited[u]=true;
    list<int> ::iterator i;
    for(i=adj[u].begin(); i!=adj[u].end(); i++)
    {
        if(!visited[*i])
            DFSTOPOLOGY(*i,visited,queue);
    }
    queue.push(u);

}
void Graph::DFS()
{
    bool visited[V];
    for(int i=0; i<V; i++)
        visited[i]=false;
    stack<int> queue;
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
            DFSTOPOLOGY(i,visited,queue);
    }
    while(!queue.empty())
    {
        cout<<ms[queue.top()]<<" ";
        queue.pop();
    }
    cout<<endl;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N;
    char arr[100],letter[110];
    while(1)
    {
        cin>>N;
        int M;

        if(N==0 )
            return 0 ;
        Graph g(N);

        for(int i=0; i<N; i++)
        {
            cin>>arr;
            mi[arr]=i;
            ms[i]=arr;
            indegree[i]=0;
        }
        cin>>M;
        for(int i=0; i<M; i++)
        {
            cin>>arr;
            cin>>letter;
            g.addEdge(arr,letter);
            indegree[mi[letter]]++;
        }
        g.DFS();
    }

}
