//Graph Representation Using adjacency list using Vector

#include<bits/stdc++.h>
using namespace std;



int main()
{
    int V = 5;
    vector< int > Graph[V];
    Graph[0] = {1, 2};
    Graph[1] = {2, 3};
    Graph[2] = {3};
    Graph[3] = {4};
    Graph[4] = {2};
    
    for(int i=0;i<V;i++)
    {
        cout<<"Vertex "<<i<<" : ";
        for(int x: Graph[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }


    return 0;
}