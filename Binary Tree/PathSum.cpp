#include <iostream>
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

bool hasPathSum(Node *root, int target)
{
    if (root == NULL)
        return false;

    if (root->left == NULL && root->right == NULL)
    {
        return root->data == target;
    }

    bool left = hasPathSum(root->left, target - root->data);
    bool right = hasPathSum(root->right, target - root->data);

    return left || right;
}

int main()
{
    // Constructing this binary tree:
    //        5
    //       / \
    //      4   8
    //     /   / \
    //    11  13  4
    //   /  \      \
    //  7    2      1

    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);

    int targetSum = 22;

    if (hasPathSum(root, targetSum))
    {
        cout << "Yes, there is a path with sum " << targetSum << endl;
    }
    else
    {
        cout << "No, there is no path with sum " << targetSum << endl;
    }

    return 0;
}
