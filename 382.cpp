#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{/*freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);*/
    int N,sum=0;
    cout<<"PERFECTION OUTPUT\n";
    while(1)
    {cin>>N;
        if(N==0)
            break;


            sum=0;
        for(int i=1;i<=N/2;i++)
        {
            if(N%i==0)
                {
                    ;sum=sum+i;}

        }

        printf("%5d  %s\n",N,sum==N?"PERFECT":sum>N?"ABUNDANT" : "DEFICIENT");
    }
    cout<<"END OF OUTPUT\n";
}
