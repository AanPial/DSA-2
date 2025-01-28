#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int v;
    int u_to_v_Weight;
};
int main()
{
    
    vector<Edge> Graph[5];

    Graph[0]={{1,5},{2,2}};
    Graph[1]={{3,1},{4,2}};
    Graph[2]={{3,7}};
    Graph[3]={{4,3}};
    Graph[4]={};

    for(int i=0;i<4;i++)
    {
        cout<<"vertex "<<i<<" : ";
        for(Edge p:Graph[i])
        {
            cout<<"("<<p.v<<" Weigth : "<<p.u_to_v_Weight<<")";
        }
        cout<<endl;
    }
}