#include <bits/stdc++.h>
using namespace std;
int value(char ch)
{
    if (ch == 'a')
        return 0;
    if (ch == 'b')
        return 1;
    if (ch == 'c')
        return 2;
    if (ch == 'd')
        return 3;
    if (ch == 'e')
        return 4;
    if (ch == 'f')
        return 5;
    if (ch == 'g')
        return 6;
    if (ch == 'h')
        return 7;
    if (ch == 'i')
        return 8;
    if (ch == 'j')
        return 9;
    if (ch == 'k')
        return 10;
    if (ch == 'l')
        return 11;
    if (ch == 'm')
        return 12;
    if (ch == 'n')
        return 13;
    if (ch == 'o')
        return 14;
    if (ch == 'p')
        return 15;
    if (ch == 'q')
        return 16;
    if (ch == 'r')
        return 17;
    if (ch == 's')
        return 18;
    if (ch == 't')
        return 19;
    if (ch == 'u')
        return 20;
    if (ch == 'v')
        return 21;
    if (ch == 'w')
        return 22;
    if (ch == 'x')
        return 23;
    if (ch == 'y')
        return 24;
    if (ch == 'z')
        return 25;
    return -1;
}
int main()
{
    int count = 0;
    string str;
    string pttrn = "hznu";
    cin >> str;
    int pts = 0;
    int sts = 0;

    int n = str.length();
    int m = pttrn.length();

    for (int i = 0; i < pttrn.length(); i++)
    {
        pts += value(pttrn[i]);
    }
    for (int i = 0; i < m; i++)
    {
        sts += value(str[i]);
    }

    int flag = 0;
    if (sts == pts)
    {
        flag = 1;
        for (int j = 0; j < m; j++)
        {
            if (str[j] != pttrn[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            count++;
        }
    }

    for (int i = 1; i <= n - m; i++)
    {
        sts = sts - value(str[i - 1]) + value(str[i + m - 1]);

        if (sts == pts)
        {
            flag = 1;
            for (int j = 0; j < m; j++)
            {
                if (str[i + j] != pttrn[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
