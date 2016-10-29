#include<iostream>
#include<stdio.h>
using namespace std;
 int n,k,sum;
int cigaratte(int n,int a)
{
    if(n==0)
        return 0;
    return n+(cigaratte((n+a)/k,(n+a)%k));
}
int main()
{
    int n,k,sum;
    while(1)
    {
cin>>n>>k;


        cout<<cigaratte(n,0)<<endl;
    }
}
