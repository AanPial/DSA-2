//0112310479
#include <bits/stdc++.h>
using namespace std;

struct Characters
{
    char c;
    int index;
    int frequency;
    string code1;
};

struct BinaryTreeNode
{
    Characters node;
    struct BinaryTreeNode *left, *right;
};

bool compare(Characters &A1, Characters &A2)
{
    return A1.frequency < A2.frequency;
}
bool compare2(Characters &A1, Characters &A2)
{
    return A1.c < A2.c;
}
struct Compare
{
    bool operator()(const BinaryTreeNode* A1, const BinaryTreeNode* A2)
    {
        return A1->node.frequency > A2->node.frequency;  // Compare by frequency min heap er jonno
    }
};

BinaryTreeNode* newNodeCreate(Characters value) {
    BinaryTreeNode* temp = new BinaryTreeNode;
    temp->left = temp->right = NULL;
    temp->node = value;
    return temp;
}

void findLeaves(BinaryTreeNode *node, string s, Characters arr[], int n) {
    if (node == NULL)
        return;

    if (node->left == NULL && node->right == NULL) {
        //tree tar j leaf node ti paisi oitar correponding character tay(from the Characters Array) er code ti boshay dibo
        for (int i = 0; i < n; i++) {
            if (arr[i].c == node->node.c) {
                arr[i].code1 = s;
                break;
            }
        }
        return;
    }

    //left tree er jonno 0 and Right er jonno 1
    findLeaves(node->left, s + "0", arr, n);
    findLeaves(node->right, s + "1", arr, n);
}

int main()
{
    string s;
    getline(cin, s);
    int len = s.size();
    
    // string tare sort kortesi frequency count er jonno
    sort(s.begin(), s.end());

    // total unique characters count korbo using for loop
    int n = 0;
    for (int i = 0; i < len; i++)
    {
        if (i == 0 || s[i] != s[i - 1])
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                n++;
            }
        }
    }

    // unique character er ekti array banaisi jar moddhe character er frequency ar code ta rakhbo
    Characters arr[n];

    int idx = 0, fcount = 0;
    for (int i = 0; i < len; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            fcount++;
            if (i == len - 1 || s[i] != s[i + 1])
            {
                arr[idx].c = s[i];
                arr[idx].index = idx;
                arr[idx].frequency = fcount;
                idx++;
                fcount = 0;
            }
        }
    }

    // abar frequency onujayi sort korechi(step for huffman coding)
    sort(arr, arr + n, compare);

    // abar jehetu pura array er sobchaite choto duiti element sum kore kore agabo tai priority queue(minheap) best option I guess
    
    //jehetu protiti freq use kore tree banabo tai priority queue er moddhe arr[i] er element gulo node onujayi dhukabo

    priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, Compare> pr1;
    // Push BinaryTreeNode* into the priority queue
    for (int i = 0; i < n; i++)
    {
        pr1.push(newNodeCreate(arr[i]));
    }

    // Construct the Huffman tree
    while (pr1.size() > 1)
    {
        BinaryTreeNode *A = pr1.top();
        pr1.pop();
        BinaryTreeNode *B = pr1.top();
        pr1.pop();

        Characters combined = {'\0', 0, A->node.frequency + B->node.frequency};
        BinaryTreeNode *C = newNodeCreate(combined);

        if(A->node.frequency<B->node.frequency)
        {
            C->left = A;
            C->right = B;
        }
        else
        {
            C->left = B;
            C->right = A;
        }
        

        pr1.push(C);  // Push BinaryTreeNode* into the priority queue
    }

    // The last remaining node is the root of the Huffman tree
    BinaryTreeNode *root = pr1.top();

    // proti leaf porjonto codes
    findLeaves(root, "", arr, n);
    sort(arr,arr+n,compare2);
    
    cout <<"\nCharacter          Frequency          Codeword"<< endl;
    cout <<"_________          _________          ________"<< endl;
    for (int i = 0; i < n; i++)
    {
        cout <<arr[i].c << "                    " << arr[i].frequency << "                " << arr[i].code1 << endl;
    }

    return 0;
}
