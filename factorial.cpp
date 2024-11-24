#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        int f=fact(n-1);
        int r=n*f;
        return r;
    }
}
int main()
{
    int n;
    cin>>n;
    int x=fact(n);
    cout<<x<<endl;
}