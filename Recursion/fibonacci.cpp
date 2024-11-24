#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n)
{
    if(n==1 || n==2)
    {
        return 1;
    }
    else
    {
        int frnd1=fibonacci(n-1);
        int frnd2=fibonacci(n-2);
        return frnd1+frnd2;
    }
}
int main()
{
    int n;
    cin>>n;
    int x=fibonacci(n);
    cout<<x<<endl;
}