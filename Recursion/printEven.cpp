#include<bits/stdc++.h>
using namespace std;
void printEven(int n)
{
    if(n<2)
    {
        return;
    }
    else
    {
        printEven(n-1);
        if(n%2==0)
        {
            cout<<n<<" ";
        }
    }
}
int main()
{
    int n;
    cin>>n;
    printEven(n);
}