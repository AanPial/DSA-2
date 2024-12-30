#include<bits/stdc++.h>
using namespace std;

struct Activity{
    string name;
    int start;
    int end;
};
bool compare(Activity &A1,Activity &A2)
{
    if(A1.end<=A2.end)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin>>n;
    Activity activities[n];
    for(int i=0;i<n;i++)
    {
        cin>>activities[i].name;
        cin>>activities[i].start;
        cin>>activities[i].end;
    }
    //step 1: Sort the activities based on Finish time
    sort(activities,activities+n,compare);
    //step 2: picking non overlapping time
    cout << "Picked Activities" << endl;;

    cout << activities[0].name << " ";
    cout << "; Available: " << activities[0].end << endl;
    
    int nextAvailable=activities[0].end;

    for(int i=0;i<n;i++)
    {
        if(activities[i].start>=nextAvailable)
        {
            cout << activities[i].name << " ";
            cout << "; Available: " << activities[i].end << endl;
            nextAvailable=activities[i].end;
        }
    }
}