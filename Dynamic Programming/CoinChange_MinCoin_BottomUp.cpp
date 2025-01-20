#include <bits/stdc++.h>
using namespace std;
#define infinity INT_MAX

int main()
{
    cout << "Enter total amount : ";
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = infinity;
    }
    int srr[n + 1];///stores the paths

    arr[0] = 0;
    srr[0] = 0;

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
            if (i >= coin[j] && (arr[i - coin[j]] + 1) < Min)
            {
                Min = arr[i - coin[j]] + 1;
                idx = coin[j];
            }
        }
        arr[i] = Min;
        srr[i] = idx;
    }

    cout << "\n\nTotal " << arr[n] << " coins needed.\n" << endl;

    cout<<"The Coins are : ";
    int i=n;
    while(i!=0)
    {
        cout<<srr[i]<<" ";
        i=i-srr[i];
    }

    cout<<"\n\n";
    cout<<"Cache memory for choosen coins road : ";
    for (int i = 0; i <=n; i++)
    {
        cout<< srr[i]<<" ";
    }
    cout<<endl;
    cout<<"Cache memory for coins : ";
    for (int i = 0; i <=n; i++)
    {
        cout<< arr[i]<<" ";
    }

    return 0;
}
