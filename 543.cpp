#include<iostream>
#include<bitset>
#include<vector>
#include<map>
using namespace std;
bitset<1000000>bs;
vector<long long> primes;

void seive()
{
    bs.set();
    bs[0]=bs[1]=0;
    for(long long i=2;i*i<=1000000;i++)
    {
        if(bs[i]){
            for(long long j=i*i;j<=1000000+1;j+=i)
        {
            bs[j]=0;
        }
        primes.push_back((int)i);

        }


    }
}
int main()
{
    int N,i;
    seive();
    while(cin>>N)
    {
        if(N==0)
            break;
        for(i=0;i<primes.size();i++){
            if(bs[N-primes[i]])
            break;
        }

        cout<<N<<" = "<<primes[i]<<" + "<<N-primes[i]<<endl;;
    }
}
