#include<bits/stdc++.h>
using namespace std;
void reverse(string &str,int i,int j)
{
    if(i>=j)
    {
        return ;
    }
    else
    {
        swap(str[i],str[j]);
        reverse(str, i + 1, j - 1);

    }
}
int main()
{
    string str;
    getline(cin,str);
    int i=0,j=str.size()-1;
    reverse(str,i,j);
    cout<<str<<endl;
}