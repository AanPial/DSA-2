#include<bits/stdc++.h>
using namespace std;
int binsearch(int arr[],int l,int r,int key)
{
    if(l>r)
    {
        return false;
    }
    else
    {
        int mid=(l+r)/2;
        if(arr[mid]==key)
        {
            return true;
        }
        else if(arr[mid]<key)
        {
            return binsearch(arr,mid+1,r,key);
        }
        else if(arr[mid]>key)
        {
            return binsearch(arr,l,mid-1,key);
        }
    }
}
int main()
{
    int arr[5]={1,2,5,7,10};
    bool x=binsearch(arr,0,4,1);
    if(x==true)
    {
        cout<<"Value found."<<endl;
    }
    else
    {
        cout<<"Value not found."<<endl;
    }
}