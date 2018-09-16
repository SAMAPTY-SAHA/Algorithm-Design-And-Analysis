#include<bits/stdc++.h>
using namespace std;
#define SIZE 20

struct DataItem{
    int data;
    int key;
};

struct DataItem*dataList[SIZE];
struct DataItem*item;
//struct DataItem*singleItem;

int getHashCode(int key)
{
    int v= key%SIZE;
    cout << "index : " << v << endl;
    return key%SIZE;
}

struct DataItem *search(int key)
{
    int hashIndex=getHashCode(key);

    cout << "hashIndex : " << hashIndex << endl;

    while(dataList[hashIndex]!=NULL)
    {

        if(dataList[hashIndex]->key==key)

            return dataList[hashIndex];

        ++hashIndex;

        hashIndex%=SIZE;
    }
    return NULL;

};
struct DataItem*insert(int key,int data)
{
    struct DataItem*item=(struct DataItem*)malloc(sizeof(struct DataItem));
    item->data=data;
    item->key=key;
    int hashIndex=getHashCode(key);

    while(dataList[hashIndex]!=NULL)
    {
        ++hashIndex;

        hashIndex%=SIZE;

    }
   //cout << "insert : " << dataList[hashIndex]->data << " " <<  dataList[hashIndex]->key << endl;
    return dataList[hashIndex]=item;
};
int main()
{
   /* singleItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    singleItem->data = -1;
    singleItem->key = -1;*/

    insert(11,15);
    insert(12,24);
    insert(13,34);
    insert(15,32);

    item=search(12);

    if(item!=NULL)
    {
        cout << "found : " << item->data<< endl;
    }
    else
        cout << "not found" << endl;

}
