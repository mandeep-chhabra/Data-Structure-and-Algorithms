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
        left = NULL;
        right = NULL;
    }
};

void pre(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    res.push_back(root->data);
    pre(root->left, res);
    pre(root->right, res);
}

vector<int> preorder(Node *root)
{
    vector<int> res;
    pre(root, res);
    return res;
}

int main()
{
    /*
        Sample Tree:
                1
               / \
              2   3
             / \
            4   5
        Preorder: 1 2 4 5 3
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = preorder(root);

    cout << "Preorder Traversal: ";
    for (int val : result)
        cout << val << " ";

    return 0;
}
