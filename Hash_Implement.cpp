#include<bits/stdc++.h>
using namespace std;
#define SIZE 20

struct Data{
     string name;
     int age;
     double height;
};

struct DataItem{

    int key;
    struct Data* data;
};
struct DataItem *dataList[SIZE];
struct DataItem*item;
struct DataItem *singleItem;

int getHashCode(int key)
{
    return key%SIZE;
}

struct DataItem*search(int key)
{
        int hashIndex=getHashCode(key);

        while(dataList[hashIndex]!=NULL)
        {
            if(dataList[hashIndex]->key==key)
                return dataList[hashIndex];
            hashIndex%=SIZE;
        }
        return NULL;

};

struct DataItem*insert(int key,string name,int age,double height)
{
    struct DataItem*item=(struct DataItem*)malloc(sizeof(struct DataItem));
    struct Data*ditem=(struct Data*)malloc(sizeof(struct Data));

    item->key=key;
    ditem->name=name;
    ditem->age=age;
    ditem->height=height;
    item->data=ditem;

    int hashIndex=getHashCode(key);

    while(dataList[hashIndex]!=NULL)
    {
        if(dataList[hashIndex]->key==key)

             return dataList[hashIndex];
             ++hashIndex;
             hashIndex%=SIZE;
    }

    return dataList[hashIndex]=item;

};

/*void display()
{
    for(int i=0;i<SIZE;i==)
}*/

int main()
{
    //struct DataItem*item=(struct DataItem*)malloc(struct DataItem);

    insert(12,"puja",21,47.5);
    insert(12,"Lima",22,48.5);

        //struct Data*d=(struct Data*)malloc(sizeof(struct Data));


    item=search(12);

    if(item!=NULL)
        cout <<  "found : " <<  item->key << " " << item->data->name << " " <<  item->data->age << " " << item->data->height << endl;
    else
        cout << "not found " << endl;

}
