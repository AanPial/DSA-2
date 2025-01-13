#include<bits/stdc++.h>
#define Max 100
#define notSet -1LL
using namespace std;

long long cache[Max+1];
long long fib(long long n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    if(cache[n] != notSet)
    {
        return cache[n];
    }
    else
    {
        long long f1=fib(n-1);
        long long f2=fib(n-2);
        long long total=f1+f2;
        cache[n]=total;
        return total;
    }
}
int main()
{
    int n;
    cin>>n;
    memset(cache,notSet,sizeof(cache));
    long long x=fib(n);
    
    cout<<n<<"th fibonacci is : "<<x<<endl;
    cout<<endl;
    cout<<"All the fibonacci from 0 to "<<n<<" is :"<<endl;
    for(int i=2;i<=n;i++)
    {
        cout<<cache[i]<<" ";
    }
}