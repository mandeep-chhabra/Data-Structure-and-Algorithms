#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int ans = 0;

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int maxHeight = max(left, right) + 1;
    ans = max(ans, left + right);
    return maxHeight;
}

int diameter(Node *root)
{
    ans = 0;
    height(root);
    return ans;
}

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string s; iss >> s;)
        ip.push_back(s);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size())
    {
        Node *currNode = q.front();
        q.pop();

        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = new Node(stoi(currVal));
            q.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;

        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = new Node(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    string treeStr;
    getline(cin, treeStr);

    Node *root = buildTree(treeStr);
    cout << diameter(root) << endl;

    return 0;
}
