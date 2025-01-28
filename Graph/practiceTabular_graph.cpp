#include<bits/stdc++.h>
using namespace std;
struct Edges{
    int u;
    int v;
    int w;
};
int main()
{
    int E;
    cin>>E;
    Edges Graph[E];

    for(int i=0;i<E;i++)
    {
        cin>>Graph[i].u>>Graph[i].v>>Graph[i].w;
    }

    cout<<"Graph is : "<<endl;
    for(int i=0;i<E;i++)
    {
        cout<<Graph[i].u<<" to "<<Graph[i].v<<" = "<<Graph[i].w<<endl;
    }

}