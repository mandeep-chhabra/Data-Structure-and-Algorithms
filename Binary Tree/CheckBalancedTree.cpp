#include <iostream>
#include <cmath>
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

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;

    if (isBalanced(root->left) && isBalanced(root->right) &&
        abs(height(root->left) - height(root->right)) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    /*
            1
           / \
          2   3
         /
        4
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    if (isBalanced(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
