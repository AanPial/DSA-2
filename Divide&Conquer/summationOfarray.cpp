#include<bits/stdc++.h>
using namespace std;
int sum(int arr[],int l,int r)
{
    if(l==r)
    {
        return arr[l];
    }
    else
    {
        int mid=(l+r)/2;
        int x=sum(arr,l,mid);
        int y=sum(arr,mid+1,r);
        int r=x+y;
        return r;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x=sum(arr,0,n-1);
    cout<<"Total sum : "<<x<<endl;

    return 0;
}