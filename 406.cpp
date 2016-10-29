#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<stdio.h>
using namespace std;
#define MAX 1100
bitset<1100> bs;
vector<int> primes;
void seive(long long upper)
{
    bs.set();
    bs[0]=bs[1]=0;
    for(long long i=2;i*i<=upper;i++)
    {
        if(bs[i]){
            for(long long j=i*i;j<=upper;j+=i)
        {
            bs[j]=0;
        }
        primes.push_back((int)i);
        }


    }
}

int main() {
    seive(1000);
    int N,C;
    while(scanf("%d %d", &N, &C) == 2) {
        int i = lower_bound(primes.begin(), primes.end(), N) - primes.begin();
        while(i >= primes.size() || primes[i] > N) i--;

        i++; // increment index to represent size
        int c = (i % 2)? C * 2 - 1 : C * 2; // get size of printed list

        int s = (i - c) > 0? (i - c) / 2 : 0; // calc start index
        int e = (i - c) > 0? s + c : i; // calc end index

        printf("%d %d:", N, C);
        for(int j = s; j < e; j++)
            printf(" %d", primes[j]);
        printf("\n\n");
    }
}
