#include<bits/stdc++.h>
using namespace std;
#define infinity INT_MIN
int main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int arr[n+1];
    arr[0]=0;
    for(int i=1;i<=n;i++)
    {
        int A=infinity,B=infinity,C=infinity;
            if(i>=a)
            {
                int x=i-a;
                A=arr[x]+1;
            }
            if(i>=b)
            {
                int x=i-b;
                B=arr[x]+1;
            }
            if(i>=c)
            {
                int x=i-c;
                C=arr[x]+1;
            }
            arr[i]=max(max(A,B),C);
    }
    cout<<arr[n]<<endl;

}