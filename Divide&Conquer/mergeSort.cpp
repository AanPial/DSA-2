#include<bits/stdc++.h>
using namespace std;
#define infinity 0x7F7F7F7F
void combine(int arr[],int l,int mid,int h)
{
    int left[mid-l+2];
    int right[h-mid+3];
    int idx=0;

    //preparing left sub array
    for(int i=l;i<=mid;i++)
    {
        left[idx]=arr[i];
        idx++;
    }
    left[idx]=infinity;
    idx=0;
    //preparing right sub array
    for(int i=mid+1;i<=h;i++)
    {
        right[idx++]=arr[i];
    }
    right[idx]=infinity;

    int i=0,j=0;
    idx=l;

    while(left[i]!=infinity || right[j]!=infinity)
    {
        if(left[i]<right[j])
        {
            arr[idx]=left[i];
            i++;
        }
        else
        {
            arr[idx]=right[j];
            j++;
        }
        idx++;
    }
}
void mergesort(int arr[],int l,int h)
{
    if(l==h)
    {
        return;
    }
    else
    {
        int mid=(l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        combine(arr,l,mid,h);
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
    cout<<"Before mergesort : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    mergesort(arr,0,n-1);
    cout<<"\nAfter mergesort : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}