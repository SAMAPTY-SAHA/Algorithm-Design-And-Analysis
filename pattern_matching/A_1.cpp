#include<bits/stdc++.h>
using namespace std;
int main()
{
    string t="aabaaabca";
    string p="aabc";

    int l_t=t.length();
    int l_p=p.length();
    int f=0;

    for(int i=0;i<l_t-l_p;i++)
    {
        for(int j=0;j<l_p;j++)
        {
            if(t[i+j]==p[j])
                f++;
            else
                f=0;
        }
        if(f==l_p)
            cout << i+1 <<endl;
    }

}
