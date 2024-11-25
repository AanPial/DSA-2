#include<bits/stdc++.h>
using namespace std;
int smallest(int arr[],int n)
{
    if(n<0)
    {
        return arr[0];
    }
    else
    {
        int me=arr[n];
        int frnd=smallest(arr,n-1);
        return min(me,frnd);
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
    int x=smallest(arr,n-1);
    cout<<x<<endl;
}