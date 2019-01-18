#include<bits/stdc++.h>
using namespace std;
int LCS(char x[],char y[],int xLength,int yLength)
{
    int matrix[xLength+1][yLength+1];
    int i=0,j=0;
    for(i=0;i<=xLength;i++)
    {

        for(j=0;j<=yLength;j++)
        {
            if(i==0 || j==0)
            {
                matrix[i][j]=0;
                cout << matrix[i][j] << " ";
            }
            else if(x[i-1]==y[j-1])
            {
                matrix[i][j]=matrix[i-1][j-1]+1;
                cout << matrix[i][j] << " ";
            }
            else
            {
                matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
                cout << matrix[i][j] << " ";
            }


        }
        cout << endl;
    }

    int lcslength=matrix[xLength][yLength];
    int index=lcslength;
    i=xLength;
    j=yLength;
    char lcsString[lcslength];

    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {

            lcsString[index-1]=x[i-1];
            --i;
            --j;
            --index;

        }
        else if(matrix[i-1][j]>matrix[i][j-1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    i=0;
    for(i=0;i<lcslength;i++)
    {
        printf("%c",lcsString[i]);
    }

    return lcslength;

}


/*int Max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;

}*/
int main()
{
    ///char x[]="abcd";
    ///char y[]="acfg";
    char y[]="abcd";
    char x[]="acfg";
    int xLength=strlen(x);
    int yLength=strlen(y);
    printf("  Length of LCS is %d\n",LCS(x,y,xLength,yLength));
}
