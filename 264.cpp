#include<iostream>

using namespace std;
#define N 4500
#define M 10000000
struct rational
{
    int up;
    int down;
}ratNum[N][N] ;

rational tem[M];

int fillTemp()
{
    for(int i=0;i<N;i++)
    {
        int bal=N-i;
        for(int j=0;j<bal;j++)
        {
            ratNum[i][j].up=i+1;
            ratNum[i][j].down=j+1;
        }
    }
}


void rectfunc(int r,int c,int diagonal,int index)
{
    if(r<0 || c<0 || index>M)
    return;
    tem[index].up=ratNum[r][c].up;
    tem[index].down=ratNum[r][c].down;
      diagonal++;
        if(r==0)
    {
        if(c%2)
        {
            for(int i=0;i<c+diagonal;i++)
            {
                ++index;
                c-=1;
                r+=1;
                rectfunc(r,c,diagonal,index);
            }
        }else
            {
                ++index;
                c+=1;
                rectfunc(r,c,diagonal,index);

            }

    }
            if(c==0)
    {
        if(r%2)
        {

            {
                ++index;

                r+=1;
                rectfunc(r,c,diagonal,index);
            }
        }else
            { for(int i=0;i<r+diagonal;i++){
             ++index;
                c+=1;
                r-=1;
                rectfunc(r,c,diagonal,index);
            }


            }
    }
}

int main()
{
    fillTemp();

    rectfunc(0,0,0,1);
    int n;
    while(cin>>n)
    {
        if(n<=0)
            return 0;
        cout<<"TERM "<<n<<" IS "<<tem[n].up<<"/"<<tem[n].down<<endl;
    }
}
