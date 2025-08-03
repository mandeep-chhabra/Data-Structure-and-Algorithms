#include <iostream>
#include <vector>
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

vector<int> result;

void leftViewHelper(Node *node, int level)
{
    if (node == nullptr)
        return;

    if (level == result.size())
    {
        result.push_back(node->data);
    }

    leftViewHelper(node->left, level + 1);
    leftViewHelper(node->right, level + 1);
}

vector<int> leftView(Node *root)
{
    result.clear();
    leftViewHelper(root, 0);
    return result;
}

int main()
{
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> view = leftView(root);

    cout << "Left view of the binary tree: ";
    for (int val : view)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
