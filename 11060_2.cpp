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

void Graph::BFSTOPOLOGY()
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
        cout<<(ms[q.front()])<<" ";
        q.pop_front();
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
        g.BFSTOPOLOGY();
    }

}
