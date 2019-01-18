#include<bits/stdc++.h>
using namespace std;
int findCoinNum(int coins[],int numOfCoins,int money)
{

    int values[money+1];
    memset(values,0,sizeof(values));
    values[0]=1;
    int i=0,j=0,max_1=0;
    for(int i=0;i<numOfCoins;i++)
    {
        for(j=coins[i];j<=money;j++)
        {

                 values[j]+=values[j-coins[i]];
                 max_1=max(max_1,values[j]);
        }
    }
    //return values[money];
    return max_1;
}
int main()
{
    int coins[]={1,2};
    int money=5;
    int numOfCoins=2;
    printf("%d\n",findCoinNum(coins,numOfCoins,money));
}

