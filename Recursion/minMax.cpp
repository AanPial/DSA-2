#include<bits/stdc++.h>
using namespace std;

struct MinMax
{
    int min;
    int max;
};
typedef struct MinMax MinMax;
MinMax MNM(int *arr,int n)
{
   if(n<0)
   {
      return {arr[0],arr[0]};
   }
   else
   {
      int me=arr[n];
      MinMax frnd=MNM(arr,n-1);
      MinMax p;
      p.max=max(frnd.max,me);
      p.min=min(frnd.min,me);
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
    MinMax x=MNM(arr,n-1);
    cout<<"The Maximum value is : "<<x.max<<endl;
    cout<<"The Minimum value is : "<<x.min<<endl;

    return 0;
}