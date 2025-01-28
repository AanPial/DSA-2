#include<bits/stdc++.h>
using namespace std;
struct compare
{
    bool operator()(int A1,int A2)
    {
        if(A1>A2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    priority_queue<int> pq1;//max heap initialization
    priority_queue<int,vector<int>,compare> pq2;//min heap initialization

    //Max Heap Priority queue
    pq1.push(10);
    pq1.push(11);
    pq1.push(12);
    pq1.push(13);
    cout<<"Max Heap : "<<endl;
    while(!pq1.empty())
    {
        cout<<pq1.top()<<endl;
        pq1.pop();
    }

    //Max Heap Priority queue
    pq2.push(10);
    pq2.push(11);
    pq2.push(12);
    pq2.push(13);
    cout<<"Max Heap : "<<endl;
    while(!pq2.empty())
    {
        cout<<pq2.top()<<endl;
        pq2.pop();
    }

}