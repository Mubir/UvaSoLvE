#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
int main()
{
    int n;
    queue<int> q;
    while(cin>>n)
    {
        if(n<=0)
            break;
        for(int i=1;i<=n;i++)
            q.push(i);
            cout<<"Discarded cards:";
        while(q.size()>1)
        {
            cout<<q.front();
            q.pop();
            if(q.size()>1)
                cout<<',';
            q.push(q.front());
            q.pop();
        }
        cout<<"\nRemaining card: "<<q.front()<<endl;
        q.pop();
    }
}
