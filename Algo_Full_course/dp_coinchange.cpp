#include<bits/stdc++.h>
using namespace std;
int mincoins(int coins[],int m,int v)
{
    int table[v+1];
    table[0]=0;
    for(int i=1; i<=v; i++)
    {
        table[i]=99999;
    }
    for(int i=1; i<=v; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << "coin " << coins[j] << endl;
            if(coins[j]<=i)
            {

                int sub_res=table[i-coins[j]];
                //cout << "sub_res " << sub_res<< endl;
                if(sub_res!=99999 && sub_res+1<table[i])

                    table[i]=sub_res+1;
                    cout << "table " << i << " : " << table[i] << endl;

            }
        }

    }
    return table[v];
}
int main()
{
   // int coins[]= {9,6,5,1};
   int coins[]={1,2};
    int m=sizeof(coins)/sizeof(coins[0]);
    int v=5;
    cout << "number of coins " << mincoins(coins,m,v);
    return 0;


}

/*
coin 1 2
value 3

*/

