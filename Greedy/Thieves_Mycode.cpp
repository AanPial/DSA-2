#include<bits/stdc++.h>
using namespace std;
struct KnapSack
{
    int item;
    double weight;
    double value;
    double value_by_weight;
};
bool compare(KnapSack A,KnapSack B)
{
    if(A.value_by_weight>B.value_by_weight)
    {
        return true;
    }
    else
    {
        return false;
    }
}
double Pick(KnapSack arr[],int n,int capacity)
{
    double value_sum=0;
    int idx=0;
    while(capacity!=0 && idx < n)
    {
        if(capacity>=arr[idx].weight)
        {
            value_sum+=arr[idx].value;
            capacity=capacity-arr[idx].weight;

            arr[idx].value=0;
            arr[idx].weight=0;
            arr[idx].value_by_weight=0;
        }
        else
        {
            value_sum+=arr[idx].value_by_weight*capacity;

            arr[idx].value=arr[idx].value-(arr[idx].value_by_weight*capacity);
            arr[idx].weight=arr[idx].weight-capacity;
            arr[idx].value_by_weight=arr[idx].value/arr[idx].weight;
            capacity=0;
        }
        idx++;
    }
    return value_sum;
}
int main()
{
    int n;
    cin>>n;
    int capacity;
    cin>>capacity;
    KnapSack box[n];
    for(int i=0;i<n;i++)
    {
        cin>>box[i].item;
        cin>>box[i].weight;
        cin>>box[i].value;
        box[i].value_by_weight = box[i].value/box[i].weight;
    }
    sort(box,box+n,compare);

    double result=Pick(box,n,capacity);
    int thief=1;

    cout<<"Total for thief "<<thief <<" Value : "<<result<<endl;

    thief=2;
    while (result > 0) {
       
        sort(box, box + n, compare);

        result = Pick(box, n, capacity);
        if (result != 0) { 
            cout << "Total for thief " << thief << " Value : " << result << endl;
            thief++;
        }
    }
    cout<<"Total number of thieves : "<<thief-1<<endl;

    return 0;
}