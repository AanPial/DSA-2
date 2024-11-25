#include<bits/stdc++.h>
using namespace std;
int countDigit(int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        int m;
        if((n%10)%2==0)
        {
            m=1;
        }
        else
        {
            m=0;
        }
        int frnd=countDigit(n/10);
        return m+frnd;
    }
}
int main()
{
    int n;
    cin>>n;
    int x=countDigit(n);
    cout<<x<<endl;
}