#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{/*freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);*/
    int n,x,y,z,i;
    cin>>n;
    i=0;
    while(n--)
    {
        cin>>x>>y>>z;
        i++;
    cout<<"Case "<<i<<": "<<(x>y?(x>z?(z>y?z:y):x):(y>z?(x>z?x:z):y))<<endl;

    }
}
