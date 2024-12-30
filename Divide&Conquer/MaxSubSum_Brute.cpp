#include<bits/stdc++.h>
using namespace std;
int subArrSum(int arr[],int i,int j)
{
    int sum=0;
    for(int idx=i;idx<=j;idx++)
    {
        sum+=arr[idx];
        printf("%d ", arr[idx]);
    }
    printf("; Summation: %d; Indices: (%d, %d)\n",sum,i,j);
    return sum;
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

    cout<<"\n"<<endl;

    int maxSubsum=INT_MIN;
    int leftIndex;
    int rightIndex;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int result=subArrSum(arr,i,j);
            if(result > maxSubsum)
            {
                maxSubsum=result;
                leftIndex=i;
                rightIndex=j;
            }
        }
    }
    printf("\n\nMaximum Sum: %d; Indices: (%d, %d)\n",maxSubsum,leftIndex,rightIndex);

    return 0;
}