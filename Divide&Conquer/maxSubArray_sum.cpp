#include <bits/stdc++.h>
using namespace std;
#define infinity INT_MIN

int CrSum(int arr[], int low, int mid, int high)
{
    int n = mid - low + 1, m = high - mid;
    int L[n];
    int R[m];
    int idx = 0;

    for (int i = low; i <= mid; i++)
    {
        L[idx] = arr[i];
        idx++;
    }

    idx = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        R[idx] = arr[i];
        idx++;
    }

    int lsum = infinity, rsum = infinity, left = 0, right = 0;

    idx = n - 1;
    while (idx >= 0)
    {
        left += L[idx];
        lsum = max(lsum, left);
        idx--;
    }

    idx = 0;
    while (idx < m)
    {
        right += R[idx];
        rsum = max(rsum, right);
        idx++;
    }

    return lsum + rsum;
}

int maxSubSum(int arr[], int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }
    else
    {
        int mid = (low + high) / 2;
        int leftsum = maxSubSum(arr, low, mid);
        int rightsum = maxSubSum(arr, mid + 1, high);
        int crossingsum = CrSum(arr, low, mid, high);
        return max(max(leftsum, rightsum), crossingsum);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x = maxSubSum(arr, 0, n - 1);
    cout << x << endl;

    return 0;
}
