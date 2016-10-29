#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct subset
{
    int parent;
    int rank;
};
void initialize(struct subset set[],int n)
{
    for(int i=0; i<n; i++)
    {
        set[i].parent=i;
        set[i].rank=0;
    }
}
/*
int find(int i,struct subset sets[])
{
    if(i==sets[i].parent)
        return i;// sets[i].parent=i;
    else
    return (sets[i].parent=find(sets[i].parent,sets));

    // cout<<" * "<<sets[i].parent<<endl;
   // return sets[i].parent;
*/

int find(int i,struct subset sets[])
{
    if(i!=sets[i].parent)
        sets[i].parent=find(sets[i].parent,sets);
    return sets[i].parent;
}

void Union(struct subset sets[],int i,int j)
{
    int x=find(i,sets);
    int y=find(j,sets);

    if(sets[x].rank>sets[y].rank)
    {
        sets[y].parent=x;
    }
    else if(sets[x].rank<sets[y].rank)
    {
        sets[x].parent=y;
    }
    else
    {
        sets[y].parent=x;
        sets[x].rank++;
    }
}

struct edge
{
    int src;
    int dest;
    int weight;
};

struct graph
{
    int V,E;
    struct edge *Edge;
};

struct graph *CreateGraph(int e,int v)
{
    struct graph *Graph=(struct graph *)malloc(sizeof(struct graph));
    Graph->E=e;
    Graph->V=v;
    Graph->Edge=( struct edge *)malloc(Graph->E*sizeof(struct edge));
    return Graph;
}
void deallocate(struct graph* gp)
{
   delete[] gp->Edge;
  // delele[] gp;
}
int myComp(const void* a, const void* b)
{
    struct edge* a1 = (struct edge*)a;
    struct edge* b1 = (struct edge*)b;
    return a1->weight > b1->weight;
}
int main()
{
  freopen("input.txt","r",stdin);
    int k,l=0;
    int V,E,cost,src,dest,weight;
    cin>>k;
    while(k--)
    {
        cin>>V>>E>>cost;
        struct graph *gp= CreateGraph(E,V);
        struct subset sets[V];
        initialize(sets,V);
         int cnt=V;
for(int i=0;i<V; i++)
        {
/*
            gp->Edge[i].src=NULL;
            gp->Edge[i].dest=NULL;
            gp->Edge[i].weight=NULL;*/
            cout<<" ** "<<gp->Edge[i].weight<<" : "<<sets[i].parent<<endl;
        }
        for(int i=0;i<E; i++)
        {
            cin>>src>>dest>>weight;
            gp->Edge[i].src=src-1;
            gp->Edge[i].dest=dest-1;
            gp->Edge[i].weight=weight;
          //  cout<<" adding : "<<gp->Edge[i].src<<" : "<<gp->Edge[i].dest<<" : "<<gp->Edge[i].weight<<endl;
        }
        qsort(gp->Edge,gp->E,sizeof(gp->Edge[0]),myComp);
//        sort(gp->Edge.begin(),gp->Edge.end());
        int mst=0;
        for(int i=0; i<E; i++)
        {
            struct edge frnt=gp->Edge[i];
            int x=find(frnt.src,sets);
            int y=find(frnt.dest,sets);
          //  cout<<"("<<x<<","<<y<<"):  "<<frnt.src<<" : "<<frnt.dest<<" : "<<frnt.weight;
            if(x!=y)
            {
                mst+=frnt.weight;
          //  cout<<"   Mst : "<<mst<<endl;
                Union(sets,x,y);
                cnt--;
            }
        }
       cout<<endl;
       int totalcost=0;
      /*  for(int i=1; i<=V; i++)
        {
          // cout<<" i :"<<i<<" Parent : "<<sets[i].parent<<" logic : "<<(sets[i].parent==i);
            cnt+=(sets[i].parent==i);
           // cout<<" Tree : "<<cnt<<endl;
            /// totalcost+=(cost*cnt);
        }*/
       // delete gp;
        l++;
         initialize(sets,V);
         for(int i=0;i<E; i++)
        {

            gp->Edge[i].src=NULL;
            gp->Edge[i].dest=NULL;
            gp->Edge[i].weight=NULL;}
        cout<<"Case #"<<l<<": ";
        cout<<(mst+(cost*cnt))<<" "<<cnt<<endl;
deallocate(gp);
    }
}
