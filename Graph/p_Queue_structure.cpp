#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int u;
    int v;
    int weight;
};
struct compare
{
    bool operator()(Edge A1,Edge A2)
    {
        return A1.weight>A2.weight;
    }
};
int main()
{
    int E = 7;
    int V = 5;

    Edge edges[7] = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 6},
        {2, 3, 3},
        {2, 4, 5},
        {3, 4, 7},
    };

    priority_queue<Edge,vector<Edge>,compare>pq;
    
    //edge(u,v) and weight(v) push korsi
    for(int i=0;i<E;i++)
    {
        pq.push(edges[i]);
    }

    for(int i=0;i<E;i++)
    {
        Edge n=pq.top();
        cout<<n.u<<"->"<<n.v<<" : "<<n.weight<<endl;
        pq.pop();
    }

}