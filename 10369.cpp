#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
typedef pair<int,int> pi;
typedef vector <int> vi;
int x[500],y[500];
vector <pair<double,pi> > edge;

struct sets
{
    int parent;
    int rank;
};

int find(int x,struct sets set[])
{   int rnt;
    if(x!=set[x].parent)
        set[x].parent=find(set[x].parent,set);
    return set[x].parent;
}


void nion(int x,int y,struct sets set[])
{
    int i=find(x,set);
    int j=find(y,set);
    if(set[i].rank>set[j].rank)
    {
        set[j].parent=i;
      //  set[i].rank++;
    }
    else if(set[i].rank<set[j].rank)
    {
        set[i].parent=j;
       // set[j].rank++;
    }
    else
    {
        set[j].parent=i;
        set[i].rank++;
    }
}

int main()
{
   // freopen("input.txt","r",stdin);
    int k,a,n;
    cin>>k;
    while(k--)
    {
        cin>>a>>n;
        sets set[n];
        for(int i=0; i<n; i++)
        {
            cin>>x[i]>>y[i];
        }
        for(int i=0; i<n; i++)
        {
            set[i].parent=i;
            set[i].rank=0;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {

                double dist=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
              //  cout<<"** "<<dist<<endl<<endl;
                edge.push_back(make_pair(dist,pi(i,j)));
              //  cout<<edge.back().first<<" : "<<edge.back().second.first<<" : "<<edge.back().second.first<<endl;
            }
        }

        sort(edge.begin(),edge.end());

        double d=0;
        int run=0;
       // for(int i=0;i<(a);i++)
       while(run!=(n-a))
        {
            pair<double,pi> frnt=edge[run];
            int p=find(frnt.second.first,set);

            int q=find(frnt.second.second,set);


            if(p!=q)
            {
//cout<<p<<" : : : "<<q<<" :  "<<frnt.first<<endl;
                d=max(frnt.first,d);
                nion(frnt.second.first,frnt.second.second,set);
                run++;
            }
        }
        printf("%.2lf\n",d);
    }

}
