 /**
Graph Coloring

3
2

0  1
1  2

*/

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std ;

int V ;// node V
vector<int> *adj ;

void addEdge(int v, int w)
{
    adj[v].push_back(w) ;
    adj[w].push_back(v) ;
}

void greedyColoring()
{
    int result[V] ;
    result[0] = 0 ;

    for(int u=1;u<V;u++) result[u] = -1 ;

    bool available[V];

    for(int cr=0;cr<V;cr++) available[cr] = false ;

    for(int u=1;u<V;u++)
    {
        vector<int> :: iterator i;

        for(i=adj[u].begin();i!=adj[u].end();++i)
        {
            cout << "re : " << result[*i] << endl;

            if(result[*i] != -1) available[result[*i]] = true ;
        }

        int cr ;
        for(cr=0;cr<V;cr++)
        {
            if(available[cr] == false)
            {

                break;
            }
        }

        result[u] = cr ;


        for(i=adj[u].begin();i!=adj[u].end();++i)
        {

            if(result[*i] != -1) available[result[*i]] = false ;
        }
    }

    for(int u=0;u<V;u++)
    {
        cout<<"Vertex : "<<u<<" ---> Color : "<<result[u]<<endl;

    }
}

int main()
{
    int edge ;
    int v, w;
    scanf("%d %d", &V, &edge) ;

    adj = new vector<int>[V] ;

    for(int i=0;i<edge;i++)
    {
        cin>>v>>w ;
        addEdge(v, w) ;
    }

    greedyColoring() ;

    return 0 ;
}
