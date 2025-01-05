#include<bits/stdc++.h>
using namespace std;
struct knapsack{
    int item;
    double value;
    double weight;
    double perUnitvalue;
};
bool compare(knapsack &A1,knapsack &A2)
{
    if(A1.perUnitvalue>A2.perUnitvalue)
    {
        return true;
    }
    else
    {
        return false;
    }
}
double picked(knapsack arr[],int n,int capacity)
{
    double sum=0;
    int i=0;
    while(capacity>0)
    {
        if(capacity>=arr[i].weight)
        {
            cout<<arr[i].item<<" ";
            sum+=arr[i].value;
            capacity=capacity-arr[i].weight;
            arr[i].weight=0;
        }
        else
        {
            cout<<arr[i].item<<"(F)"<<endl;
            sum+=(arr[i].perUnitvalue*capacity);
            arr[i].weight=(arr[i].weight-capacity);
            capacity=0;
        }
        i++;
    }
    return sum;
}
int main()
{
    int n,capacity;
    cin>>n>>capacity;
    knapsack arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].item>>arr[i].value>>arr[i].weight;
        arr[i].perUnitvalue=arr[i].value/arr[i].weight;
    }
    sort(arr,arr+n,compare);
    cout<<"Picked Item : ";
    double result = picked(arr, n, capacity);
    cout<<"Total Profit = "<<result<<endl;

    return 0;
}