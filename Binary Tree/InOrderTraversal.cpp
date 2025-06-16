#include <iostream>
#include <vector>
using namespace std;

// Node definition
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void in(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    in(root->left, res);
    res.push_back(root->data);
    in(root->right, res);
}

vector<int> inOrder(Node *root)
{
    vector<int> res;
    in(root, res);
    return res;
}

int main()
{
    /*
        Sample Binary Tree:
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

    vector<int> result = inOrder(root);

    cout << "Inorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}
