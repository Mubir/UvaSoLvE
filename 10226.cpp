#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include <stdio.h>
//https://f0rth3r3c0rd.wordpress.com/2011/08/28/uva-10226-hardwood-species/
using namespace std;
int main()
{
    char buffer[40];
    int cas;
    cin>>cas;
    cin.ignore(2);
    while(cas--)
    {
        map<string,int> m;
        vector<string>trees;
        int total=0;
        while(gets(buffer)&&buffer[0])
        {
            string in(buffer);
            if(!m[in])
            {
                m[in]=1;
                trees.push_back(in);
            }
            else
            {
                m[in]++;
            }
            total++;

        }
        sort(trees.begin(),trees.end());
        for(int i=0;i<trees.size();i++)
        {
            cout<<trees[i]<<" ";
            printf("%.4lf\n",(m[trees[i]]*100)/total);
        }
        if(cas)
            putchar('\n');
    }
}
