#include <bits/stdc++.h>
using namespace std;
#define infinity INT_MAX

int main()
{
    cout << "Enter total amount : ";
    int n;
    cin >> n;
    int dpTable[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dpTable[i] = infinity;
    }
    int parent[n + 1];///stores the paths

    dpTable[0] = 0;
    parent[0] = 0;

    cout << "Enter total number of coins : ";
    int c;
    cin >> c;
    cout << "Enter the coins : ";
    int coin[c];
    for (int i = 0; i < c; i++)
    {
        cin >> coin[i];
    }
    sort(coin, coin + c);
    for (int i = 1; i <= n; i++)
    {
        int Min = infinity;
        int idx = -1;
        for (int j = 0; j < c; j++)
        {
            if (i >= coin[j] && (dpTable[i - coin[j]] + 1) < Min)
            {
                Min = dpTable[i - coin[j]] + 1;
                idx = coin[j];
            }
        }
        dpTable[i] = Min;
        parent[i] = idx;
    }

    cout << "\n\nTotal " << dpTable[n] << " coins needed.\n" << endl;

    cout<<"The Coins are : ";
    int i=n;
    while(i!=0)
    {
        cout<<parent[i]<<" ";
        i=i-parent[i];
    }

    cout<<"\n\n";
    cout<<"Cache memory for choosen coins road : ";
    for (int i = 0; i <=n; i++)
    {
        cout<< parent[i]<<" ";
    }
    cout<<endl;
    cout<<"Cache memory for coins : ";
    for (int i = 0; i <=n; i++)
    {
        cout<< dpTable[i]<<" ";
    }

    return 0;
}
