#include<bits/stdc++.h>
using namespace std;
int pow(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    else
    {
        int me=a;
        int frnd=pow(a,b-1);
        int r=me*frnd;
        return r;
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    int x=pow(a,abs(b));
    if(b>=0)
    {
        cout<<x<<endl;
    }
    else
    {
        cout<<1.0/x<<endl;
    }
    
}