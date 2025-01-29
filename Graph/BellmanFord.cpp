#include <bits/stdc++.h>
using namespace std;
#define infinity 0x7F7F7F7F
struct Edges
{
    int u;
    int v;
    int c_u_v;
};
void bellmanford(Edges Graph[], int E, int source, int V)
{
    int distance[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        distance[i] = infinity;
        parent[i] = i;
    }
    distance[source] = 0;
    int count = 0;
    bool update = false;

    for (int i = 0; i < V ; i++)
    {
        update=false;
        for (int j = 0; j < E; j++)
        {
            if (distance[Graph[j].u] + Graph[j].c_u_v < distance[Graph[j].v])
            {
                distance[Graph[j].v] = distance[Graph[j].u] + Graph[j].c_u_v;
                parent[Graph[j].v] = Graph[j].u;
                update = true;
                count++;
            }
        }
        if (update == false)
        {
            break;
        }
    }
   /* cout<<count<<endl;
    cout<<update<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<distance[i]<<" ";
    }*/
    if (count == V-1 )
    {
        update = false;
        for (int j = 0; j < E; j++)
        {
            if (distance[Graph[j].u] + Graph[j].c_u_v < distance[Graph[j].v])
            {
                update = true;
            }
        }
    }
    if (update == true)
    {
        cout << "Negative cycle detected !" << endl;
        return;
    }
    else
    {
        cout << "Minimum cost from source : " << distance[2] << endl
             << endl;
    }
}
int main()
{
    int E, V;
    E=3;
    V = 3;
    Edges Graph[3];

    Graph[0] = {0, 1, 5};
    Graph[1] = {2,0, 2};
    Graph[2] = {1, 2, -4};

    int source = 0;
    bellmanford(Graph, E, source, V);
}