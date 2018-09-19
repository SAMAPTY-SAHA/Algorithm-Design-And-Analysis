



#include<bits/stdc++.h>
using namespace std;
int maxi(int a,int b)
{
    return (a>b)?a:b;
}

int knapsak(int w,int wt[],int val[],int n)
{

    int k[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            {
                k[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                k[i][j]=maxi(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][w]);
            }
            else
                k[i][j]=k[i-1][w];
        }
    }
    return k[n][w];
}
int main()
{
    int n,w;
    cin >> n;
    int val[n],weight[n];

    for(int i=0;i<n;i++)
    {

        cin >> weight[i];
        cin >> val[i];
    }

    int maxW;
    cin >> maxW;
    cout << knapsak(maxW,weight,val,n);
}

