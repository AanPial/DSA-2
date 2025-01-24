#include<bits/stdc++.h>
using namespace std;
struct DSU
{
    int vertices;
    vector<int> parent;
    vector<int> Rank_;
    DSU(int v)
    {
        vertices = v;
        parent.resize(v);
        Rank_.resize(v);

        for (int i = 0; i < v; i++)
        {
            set(i);
        }
    }
    void set(int x)
    {
        parent[x] = x;
        Rank_[x] = 0;
    }
    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        else
        {
            int repx = find(parent[x]); // using path Compression
            parent[x] = repx;
            return repx;
        }
    }
    bool Union(int u, int v)
    {
        int repU = find(u);
        int repV = find(v);
        if (repU == repV)
        {
            return false;
        }
        else
        {
            if (repU > repV)
            {
                parent[repV] = repU;
            }
            else if (repU < repV)
            {
                parent[repU] = repV;
            }
            else
            {
                parent[repU] = repV;
                Rank_[repV] += 1;
            }
            return true;
        }
    }
};
struct Edges
{
    int u;
    int v;
    int weight;
};
bool Compare(Edges A1,Edges A2)
{
    return A1.weight<A2.weight;
}
int main()
{
    int E,V;
    cin>>E>>V;
    Edges Graph[E];

    for(int i=0;i<E;i++)
    {
        cin>>Graph[i].u>>Graph[i].v>>Graph[i].weight;
    }
    
    sort(Graph,Graph+E,Compare);
    cout<<"\nGraph : "<<endl;
    
    for(int i=0;i<E;i++)
    {
        cout<<"Edges : "<<Graph[i].u<<" "<<Graph[i].v<<" = "<<Graph[i].weight<<endl;
    }


    DSU *p=new DSU(V);
    cout<<"\nMST : "<<endl;

    int sum=0;
    for(int i=0;i<E;i++)
    {
        bool x=p->Union(Graph[i].u,Graph[i].v);
        if(x==true)
        {
            cout<<"Edges : "<<Graph[i].u<<" "<<Graph[i].v<<" = "<<Graph[i].weight<<endl;
            sum+=Graph[i].weight;
        }
        
    }
    cout<<"\nMinimum Spanning Tree (Cost): "<<sum<<endl<<endl;

    return 0;
}