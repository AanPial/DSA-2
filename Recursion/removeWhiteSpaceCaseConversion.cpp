#include<bits/stdc++.h>
using namespace std;
string sc(string str,int i)
{
    if(i==str.size())
    {
        return "";
    }
    else
    {
        char cur=str[i];
        string frnd=sc(str,i+1);
        if(cur>='A' && cur<='Z')
        {
            cur-='A';
            cur+='a';
        }
        if(cur == ' ')
        {
            return frnd;
        }
        else
        {
            return cur+frnd;
        }
    }
}
int main()
{
    string str;
    getline(cin,str);
    string x=sc(str,0);
    cout<<x<<endl;
}