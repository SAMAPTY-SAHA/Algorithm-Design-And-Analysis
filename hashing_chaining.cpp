#include<bits/stdc++.h>
using namespace std;
#define SIZE1 20
#define SIZE2 15
struct DataItem{
    int key;
    int value;
};

struct DataItem*dataList[SIZE1][SIZE2];
struct DataItem* item;
struct DataItem*singleItem;

int getHashCode(int key)
{
    return key%SIZE1;
}

struct DataItem*search(int key)
{
    int hashIndex=getHashCode(key);

    for(int i=0;i<SIZE2;i++)
    {
        if(dataList[hashIndex][i]!=NULL)
        {
            if(dataList[hashIndex][i]->key==key)
            {

                return dataList[hashIndex][i];
            }
        }
    }
    return NULL;
};



struct DataItem* insert(int key,int value)
{
    struct DataItem* item=(struct DataItem*)malloc(sizeof(struct DataItem));
    item->key=key;
    item->value=value;

    int hashIndex=getHashCode(key);

    for(int i=0;i<SIZE2;i++)
    {
        if(dataList[hashIndex][i] == NULL)
        {
            dataList[hashIndex][i]= item;
            break;
        }
    }

};

int main()
{

    insert(12,32);
    insert(13,60);
    insert(15,90);
    insert(20,65);
    insert(22,65);


    item=search(12);


    for(int i=0;i<SIZE1;i++)
    {
        for(int j=0;j<SIZE2;j++)
        {
            if(dataList[i][j] == item)
                cout<< " Found " << dataList[i][j]->key <<  " "<< dataList[i][j]->value << " " ;
            else

                cout << "...... " ;
        }
    }


}
