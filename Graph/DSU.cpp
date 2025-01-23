#include <bits/stdc++.h>
using namespace std;
struct DSU
{
    int vertices;
    vector<int> parent;
    vector<int> Rank_;
    DSU(int v)
    {
        vertices = v;
        parent.resize(v);
        Rank_.resize(v);

        for (int i = 0; i < v; i++)
        {
            set(i);
        }
    }
    void set(int x)
    {
        parent[x] = x;
        Rank_[x] = 0;
    }
    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        else
        {
            int repx = find(parent[x]); // using path Compression
            parent[x] = repx;
            return repx;
        }
    }
    bool Union(int u, int v)
    {
        int repU = find(u);
        int repV = find(v);
        if (repU == repV)
        {
            return false;
        }
        else
        {
            if (repU > repV)
            {
                parent[repV] = repU;
            }
            else if (repU < repV)
            {
                parent[repU] = repV;
            }
            else
            {
                parent[repU] = repV;
                Rank_[repV] += 1;
            }
            return true;
        }
    }
};
int main()
{
    cout << "Enter size : ";
    int v;
    cin >> v;
    DSU *p = new DSU(v);
    
    int choice;
    while (1)
    {
        err:
        printf("\nMenu : \n0.Exit\n1.find\n2.Union\n3.Print\n");
        cout << "Enter choice : ";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            cout << "Enter value to find : ";
            int x;
            cin >> x;
            int result = p->find(x);
            cout << "Representative is : " << result << endl;
        }
        else if (choice ==2)
        {
            cout << "Enter U and V : ";
            int u, v;
            cin >> u >> v;
            bool result = p->Union(u, v);
        }
        else if (choice==3)
        {
            for (int i = 0; i < v; i++)
            {
                cout << "Parent of " << i << " is: ";
                cout << p->parent[i] << endl;
            }
        }
        else
        {
            goto err;
        }
    }
}