#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAX 1000001
/*help from: http://www.geeksforgeeks.org/sieve-of-eratosthenes/
https://github.com/rabiulcste/UVaOJ-Solutions/blob/master/uva%2010533.c
*/

bool prime[MAX];
int d_prime[MAX];
using namespace std;
int sum(int pr)
{
    int sum=0;
    while(pr!=0)
    {
        sum=sum+(pr%10);
        pr/=10;

    }
    return sum;
}
void sievePrime()
{
    int count=0;
    int n=MAX;
    memset(prime,true,sizeof(prime));
  /*  for(int i=4;i<=MAX;i+=2) //doing so increases runtime
        prime[i]=false;*/
    for(int i=2; i*i<=n; i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*2; j<=n; j+=i)
                prime[j]=false;
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(prime[i]==true && prime[sum(i)]==true)
            count++;
        d_prime[i]=count;
      //  cout<<i<<" : "<<d_prime[i]<<" \n";
        /*   int temp=sum(i);
           if(prime[temp]==true)
           {
               cout<<i<<" ";
           }*/

    }

}

int main()
{
    /*int n = 30;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    sievePrime(n);
    return 0;*/

    int t,a,b;
    sievePrime();
    scanf("%d",&t);
    while(t--)
    {
        if(t<0)break;
        scanf("%d %d",&a,&b);

    //    cout<<" ** "<<d_prime[b]<<"   \t "<<d_prime[a-1]<<endl;
        printf("%d\n",(d_prime[b]-d_prime[a-1]));
    }
}
