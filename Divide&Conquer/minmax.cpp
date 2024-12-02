#include<bits/stdc++.h>
using namespace std;
struct minimumMaximum
{
    int min;
    int max;
};
minimumMaximum MiniMax(int arr[],int l,int r)
{
    if(l==r)
    {
        return {arr[l],arr[l]};
    }
    else if(l+1==r)
    {
        return {min(arr[l],arr[r]),max(arr[l],arr[r])};
    }
    else
    {
        int mid=(l+r)/2;
        minimumMaximum left=MiniMax(arr,l,mid);
        minimumMaximum right=MiniMax(arr,mid+1,r);
        minimumMaximum p;
        p.min=min(left.min,right.min);
        p.max=max(left.max,right.max);
        return p;
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
    minimumMaximum x=MiniMax(arr,0,n-1);
    cout<<"Minimum : "<<x.min<<"\nMaximum : "<<x.max<<endl;

    return 0;
}