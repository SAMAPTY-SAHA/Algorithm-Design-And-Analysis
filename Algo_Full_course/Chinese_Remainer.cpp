/**
    Chinese Remainder
*/
#include<bits/stdc++.h>
using namespace std;
int d,x,y;

void extendedEuclid(int a,int b)
{
    if(a == 0)
    {
       /// d = b;
        x = 0;
        y = 1;
    }
    else
    {
        extendedEuclid(b % a, a);
        int temp = y;
        y = x;
        x = temp - (b/a)*x;
    }
}

int modInverse(int a, int m)
{
    extendedEuclid(a,m);
    return (x % m + m) % m;
}

int findMinX(int num[], int rem[], int n)
{
    int prod = 1;
    int result = 0;

    for(int i = 0; i < n; i++)
        prod *= num[i];

    for(int i = 0; i < n; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }
    return result % prod;
}

int main()
{
    int num[] = {3,4,5};
    int rem[] = {2,3,1};
    int n = sizeof(num)/sizeof(num[0]);
    cout<<"X is "<<findMinX(num,rem,n);
    return 0;
}

