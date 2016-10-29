#include<iostream>
#include<stdlib.h>
using namespace std;
unsigned min(unsigned a,unsigned b,unsigned c)
{
    if(a<b)
        return a<c?a:c;
    else
        return b<c?b:c;
    }
unsigned thUglyNum(unsigned n)
{
    unsigned *ugly=(unsigned*)malloc(sizeof(unsigned)*n);
    unsigned i2=0,i3=0,i5=0;
    unsigned next_ugly_num=1;
    unsigned multiple_of_2=2;
    unsigned multiple_of_3=3;
    unsigned multiple_of_5=5;
    *(ugly+0)=1;
    for(int i=1; i<n; i++)
    {
        next_ugly_num=min(multiple_of_2,multiple_of_3,multiple_of_5);
        *(ugly+i)=next_ugly_num;
        if(next_ugly_num==multiple_of_2)
        {
            i2=i2+1;
            multiple_of_2=*(ugly+i2)*2;
        }
         if(next_ugly_num==multiple_of_3)
        {
            i3=i3+1;
            //cout<<i3<<" ->"<<*(ugly+i3)<<"\t";
            multiple_of_3=*(ugly+i3)*3;
        }
        if(next_ugly_num==multiple_of_5)
        {
            i5=i5+1;

            multiple_of_5=*(ugly+i5)*5;
            //cout<<i5<<" ->"<<*(ugly+i5)<<","<<multiple_of_5<<"\t";
        }
    }
return next_ugly_num;
}
int main()
{
    cout<<"The 1500'th ugly number is "<<thUglyNum(1500)<<"."<<endl;
}
