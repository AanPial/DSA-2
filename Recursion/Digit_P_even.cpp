#include<bits/stdc++.h>
using namespace std;
struct evenodd
{
    int even=0;
    int digit=0;
};
typedef struct evenodd evvodd;
evenodd countE_Digit(int n)
{
    if(n==0)
    {
        return {0,0};
    }
    else
    {
        int me=1;
        int me2;
        if((n%10)%2==0)
        {
            me2=1;
        }
        else
        {
            me2=0;
        }
        evenodd frnd=countE_Digit(n/10);
        evenodd p = {0, 0};
        p.digit=p.digit+me+frnd.digit;
        p.even=p.even+me2+frnd.even;
        return p;
    }
}
int main()
{
    int n;
    cin>>n;
    evenodd x=countE_Digit(n);
    cout<<"Total digit : "<<x.digit<<endl;
    cout<<"Total Even digit : "<<x.even<<endl;

    return 0;
}