#include<bits/stdc++.h>
using namespace std;
struct NURALAM
{
    int age;
    double balance;
};
int main()
{
    vector<NURALAM> nur;

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int age;
        double balance;
        cin >> age >> balance;
        nur.push_back({age, balance});
    }
    nur.pop_back();
    cout<<nur.size()<<endl;
    for(NURALAM x: nur)
    {
        cout<<x.age<<" ";
    }
}