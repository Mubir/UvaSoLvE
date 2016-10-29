#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
using namespace std;
void swap(char *a,char *b)
{
    char t=*a;
    *a=*b;
    *b=t;
}
void reverse(char str[], int l, int h)
{
   while (l < h)
   {
       swap(&str[l], &str[h]);
       l++;
       h--;
   }
}
int compare(const void *a,const void *b)
{
    return(*(char*)a-*(char*)b);
}



int findceil(char a[],char first,int st,int ed)
{
    int ceilIndex=st;
    for(int i=st; i<=ed; i++)
    {
        if(a[i]>first&&a[i]<a[ceilIndex])
            ceilIndex=i;

    }
    return ceilIndex;
}

void printPermuaation(char a[])
{
     int cnt=0;
    int length=strlen(a);
    int i=0;
    qsort(a,length,sizeof(a[0]),compare);
    bool finish=false;
    while(!finish)
    {
      //  if(cnt==n)
        cout<<a<<endl;
      //  break;
        for(i=length-2; i>=0; i--)
            if(a[i]<a[i+1])
                break;
        if(i==-1)
            finish=true;
        else
        {
            int second=findceil(a,a[i],i+1,length-1);
            swap(&a[i],&a[second]);
            //qsort(a+i+1,length-i-1,sizeof(a[0]),compare);
            reverse( a, i + 1, length - 1 );
        }
        cnt++;
    }
}
int main()
{
    //char str[] = "ABC";
    char str[20];
    int i;
    cin>>i;
      int num=0;
    while(i){
      //  fgets(str, 63, stdin);
scanf("%s",&str);
      //  cin>>num;
    printPermuaation( str );
    cout<<endl<<endl;
    i--;
    }

    return 0;
}
