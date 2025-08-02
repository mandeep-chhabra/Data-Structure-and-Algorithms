#include <iostream>
using namespace std;

// Definition for a binary tree node.
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

// Function to find LCA
Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

// Utility function to insert nodes (for demonstration only)
Node *insertExampleTree()
{
    // Sample Tree:
    //         3
    //        / \
    //       5   1
    //      / \ / \
    //     6  2 0  8
    //       / \
    //      7   4

    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    return root;
}

int main()
{
    Node *root = insertExampleTree();

    int n1, n2;
    cout << "Enter two node values to find their LCA: ";
    cin >> n1 >> n2;

    Node *ancestor = lca(root, n1, n2);

    if (ancestor != NULL)
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << ancestor->data << endl;
    else
        cout << "One or both nodes not found in the tree." << endl;

    return 0;
}
