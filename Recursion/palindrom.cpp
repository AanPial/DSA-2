#include<bits/stdc++.h>
using namespace std;
bool isPalindrom(string str,int i,int j)
{
    if(i>=j)
    {
        return true;
    }
    else
    {
        if(str[i]!=str[j])
        {
            return false;
        }
        else
        {
            return isPalindrom(str,i+1,j-1);
        }
    }
}
int main()
{
    string str;
    getline(cin,str);
    int i=0,j=str.size()-1;
    bool s=isPalindrom(str,i,j);
    (s==true)?cout<<"Palindrom"<<endl : cout<<"Not Palindrom"<<endl;
}