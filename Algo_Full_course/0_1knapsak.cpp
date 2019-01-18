/*
n=4
w v
2 3
3 7
4 5
5 9
max 5
*/
#include<bits/stdc++.h>
using namespace std;
/*int Max(int a,int b)
{
    return (a>b)?a:b;
}*/

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
                cout << k[i][j] << " ";
            }
            else if(wt[i-1]<=j)
            {
                k[i][j]=max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
                                cout << k[i][j] << " ";
            }
            else
               {

                k[i][j]=k[i-1][j];
                        cout << k[i][j] << " ";
               }
        }
        cout << endl;
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
    int l=sizeof(weight)/sizeof(weight[0]);

    int maxW;
    cin >> maxW;
    cout << knapsak(maxW,weight,val,l);

}
