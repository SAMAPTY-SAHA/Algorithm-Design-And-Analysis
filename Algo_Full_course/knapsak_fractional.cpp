#include<bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};

bool cmp(struct Item a,struct Item b)
{

    double ratio1=(double)(a.value/a.weight);
    double ratio2=(double)(a.value/a.weight);
    return ratio1>ratio2;
}
int main()
{
    Item items[]= {{60,10},{100,20},{120,30}};
    ///Item items[]={{20,10},{30,10},{40,10},{50,5}};
    int allowedWeight=50;
    ///    int allowedWeight=16;
    int i=0;
    int n=sizeof(items)/sizeof(items[0]);
    cout << "size :" << n << endl;
    sort(items,items+n,cmp);
    double currentValue=0.0;
    int currenWeight=0;
    for(int i=0; i<n; i++)
    {
        if(currenWeight+items[i].weight<=allowedWeight)
        {
            currentValue+=items[i].value;
            currenWeight+=items[i].weight;
        }
        else
        {
            int remainWeight=allowedWeight-currenWeight;
            double valueOfRemainWeight=items[i].value*(( (double)remainWeight/items[i].weight));
            currenWeight+=remainWeight;
            currentValue+=valueOfRemainWeight;
            break;
        }
    }
    printf("%.2f %d",currentValue,currenWeight);

}
