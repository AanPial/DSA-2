#include<bits/stdc++.h>
using namespace std;

#define infinty INT_MAX

struct Pair //graph bananor jonno
{
    int v;
    int c_u_v;
};
struct nodeDistance //aita pair er motoi ...eita priority queue er jonno khola
{
    int node;
    int distance;
};

struct compare
{
    bool operator()(nodeDistance A1,nodeDistance A2)
    {
        return A1.distance>A2.distance;
    }
};

void pathPrinting(int parent[],int V)
{
    if(V==parent[V])
    {
        cout<<V;
        return;
    }
    else
    {
        pathPrinting(parent,parent[V]);
        cout<<"-->"<<V;
    }
}

void dijsktra(vector<Pair> Graph[],int V,int source)
{
    int distance[V];
    int parent[V];
    int optimal_path[V];

    for(int i=0;i<V;i++)
    {
        distance[i]=infinty;
        parent[i]=i;
        optimal_path[i]=0;
    }

    priority_queue <nodeDistance,vector<nodeDistance>,compare> pq;

    distance[source]=0;
    parent[source]=source;
    pq.push({source,0});

    while(!pq.empty())
    {
        nodeDistance currentlyVisiting=pq.top();
        pq.pop();
        int u=currentlyVisiting.node;
        optimal_path[u]=1;

        for(Pair p:Graph[u])
        {
            if(distance[u]+p.c_u_v<distance[p.v])
            {
                distance[p.v]=distance[u]+p.c_u_v;
                pq.push({p.v,distance[u]+p.c_u_v});
                parent[p.v]=u;
            }
        }
    }

    cout<<"Shortest path : "<<distance[4]<<endl;

    cout<<"Distance Array : ";
    for(int i=0;i<V;i++)
    {
        cout<<distance[i]<<" ";
    }

    cout<<"\nParent Array : ";
    for(int i=0;i<V;i++)
    {
        cout<<parent[i]<<" ";
    }

    cout<<endl;
    pathPrinting(parent,4);

}
int main()
{
    int V=5;

    vector<Pair> Graph[V];

    Graph[0]={{1,5},{2,2}};
    Graph[1]={{4,2},{3,1}};
    Graph[2]={{3,7}};
    Graph[3]={{4,3}};
    Graph[4]={};
    int source=0;
    dijsktra(Graph,V,source);

    return 0;
}