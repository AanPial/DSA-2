#include<bits/stdc++.h>
using namespace std;
struct Counting
{
    int dig=0;
    int even=0;
};
int countDigit(int n)
{
    if(n>=0 && n<=9)
    {
        return 1;
    }
    else
    {
        int m=1;
        int frnd=countDigit(n/10);
        return m+frnd;
    }
}
int countEvenDigit(int n)
{
    if(n>=0 && n<=9)
    {
        return (n % 2 == 0) ? 1 : 0;
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
        int frnd=countEvenDigit(n/10);
        return m+frnd;
    }
}
Counting countDE(int n)
{
    if(n>=0 && n<=9)
    {
        if(n%2==0)
        {
            return {1,1};
        }
        else
        {
            return {1,0};
        }
    }
    else
    {
        int m=((n%10)%2==0)?1:0;
        Counting frnd=countDE(n/10);
        Counting p;
        p.dig=p.dig+1+frnd.dig;
        p.even=p.even+m+frnd.even;
        return p;
    }
}
int main()
{
    int n;
    cin>>n;
    int x=countDigit(n);
    int y=countEvenDigit(n);
    Counting z=countDE(n);
    cout<<"Digits : "<<x<<endl;
    cout<<"Even Digits : "<<y<<endl;
    cout<<"**Dig = "<<z.dig<<" **Even = "<<z.even<<endl;
}
