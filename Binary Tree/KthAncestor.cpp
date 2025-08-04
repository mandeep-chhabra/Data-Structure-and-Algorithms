#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *solve(Node *root, int &k, int node)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == node)
        return root;

    Node *left = solve(root->left, k, node);
    Node *right = solve(root->right, k, node);

    if (left || right)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left ? left : right;
    }
    return nullptr;
}

int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (ans == nullptr || ans->data == node)
        return -1;
    return ans->data;
}

int main()
{
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int node = 5;
    int k = 2;

    int ancestor = kthAncestor(root, k, node);
    if (ancestor != -1)
        cout << k << "-th ancestor of node " << node << " is: " << ancestor << endl;
    else
        cout << k << "-th ancestor of node " << node << " does not exist." << endl;

    return 0;
}
