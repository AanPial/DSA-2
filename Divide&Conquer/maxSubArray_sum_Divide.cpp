#include<bits/stdc++.h>
using namespace std;
#define infinity INT_MIN
struct maximumSubSum{
    int maxsubsum=0;
    int leftIndex;
    int rightIndex;
};
maximumSubSum CrossingCount(int arr[],int low,int mid,int high)
{
    int sum=0;
    int Lsum=infinity;
    int LeftIdx;
    for(int i=mid;i>=low;i--)
    {
        sum+=arr[i];
        if(sum>Lsum)
        {
            Lsum=sum;
            LeftIdx=i;
        }
    }
    sum=0;
    int Rsum=infinity;
    int RightIdx;
    for(int i=mid+1;i<=high;i++)
    {
        sum+=arr[i];
        if(sum>Rsum)
        {
            Rsum=sum;
            RightIdx=i;
        }
    }
    return {Lsum+Rsum,LeftIdx,RightIdx};
}
maximumSubSum findMaxSubSum(int arr[],int low,int high)
{
    if(low==high)
    {
        return {arr[low],low,low};
    }
    else
    {
        int mid=(low+high)/2;
        maximumSubSum left=findMaxSubSum(arr,low,mid);
        maximumSubSum right=findMaxSubSum(arr,mid+1,high);
        maximumSubSum crossingSum=CrossingCount(arr,low,mid,high);//index soho ber kora lagbe tai structure e defined hobe
        if (left.maxsubsum >= right.maxsubsum && left.maxsubsum >= crossingSum.maxsubsum) {
            return left;
        } else if (right.maxsubsum >= left.maxsubsum && right.maxsubsum >= crossingSum.maxsubsum) {
            return right;
        } else {
            return crossingSum;
        }
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
    maximumSubSum result=findMaxSubSum(arr,0,n-1);
    printf("Summation: %d; Indices: (%d, %d)\n", result.maxsubsum,result.leftIndex,result.rightIndex);
    
    for(int i=result.leftIndex; i<=result.rightIndex; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}