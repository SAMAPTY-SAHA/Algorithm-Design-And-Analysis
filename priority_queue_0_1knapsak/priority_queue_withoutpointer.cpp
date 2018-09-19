#include<bits/stdc++.h>
using namespace std;
struct Node
{

    int key;
    Node(int a)
    {
        key=a;
    }
};
struct compare
{
    bool operator() (Node a,Node b)
    {
        return (a.key > b.key);
    }
};

int main()
{
    Node a=1;
    Node b=51;
    Node c=6;

    priority_queue<Node,vector<Node>,compare>myQueue;

    myQueue.push(a);
    myQueue.push(b);
    myQueue.push(c);

    while(!myQueue.empty())
    {
          Node temp=myQueue.top();
             myQueue.pop();
        cout << temp.key << endl;
    }
}






