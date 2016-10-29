#include<map>
#include<algorithm>
#include<iostream>
#include<string>
#include<stdio.h>
//https://github.com/lamphanviet/competitive-programming/blob/master/uva-online-judge/accepted-solutions/10226%20-%20Hardwood%20Species.cpp
using namespace std;
 int main()
 {
     map<string,int> trees;
     map<string,int>:: iterator it;
     int cs,sum;
     string s;
     cin>>cs;
     cin.ignore(2);
     while(cs--)
     {sum=0;
         while(getline(cin,s)&&s.length())
         {
             trees[s]++;
             sum++;

         }
         for(it=trees.begin();it!=trees.end();it++)
         {
             cout<<it->first<<" ";
           printf("%.4lf\n",(it->second)*100.0/(double)sum);
        }
        if (cs) cout << endl;
        trees.clear();
     }
 }
