#include<bits/stdc++.h>
using namespace std;
int digitSum(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        int me=n%10;
        int frnd=digitSum(n/10);
        int r=me+frnd;
        return r;
    }
}
int main()
{
    int n;
    cin>>n;
    int x=digitSum(n);
    cout<<x<<endl;
}