#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define MAX 1500
bool isPrime[MAX];

void definePrime()
{
    memset(isPrime,true,sizeof(isPrime));
   /* for(int i=2; i*i<=MAX; i++)
    {
        if(isPrime[i]==true)
        {
            for(int j=i*2; j<=MAX; j+=i)
            {
                isPrime[j]=false;
            }
        }

    }*/
    for(int i=2; i*i<=MAX; i++)
    {
        if(isPrime[i]==true)
        {
            for(int j=i*2; j<=MAX; j+=i)
                isPrime[j]=false;
        }
    }
}

int main()
{
    definePrime();
    char s[27];
    int sum=0;
    while(gets(s))
    {
        for(int i=0;i<strlen(s);i++)
           if(s[i]>='a' & s[i]<='z')
            sum=s[i]-'a'+1;
            else
                sum=s[i]-'A'+27;
    if(isPrime[sum]==true)
        prinf("It is a prime word.");
    else
        printf("It is not a prime word.")

       sum=0;
    }
}
