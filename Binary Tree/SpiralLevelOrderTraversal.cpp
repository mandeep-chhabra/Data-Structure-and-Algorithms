#include <iostream>
#include <vector>
#include <stack>
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

vector<int> zigzagTraversal(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            res.push_back(temp->data);

            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            res.push_back(temp->data);

            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }

    return res;
}

// Main function
int main()
{
    /*
        Sample Tree:
                1
               / \
              2   3
             / \   \
            4   5   6

        Zigzag Traversal: 1 2 3 6 5 4
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> result = zigzagTraversal(root);

    cout << "Zigzag Level Order Traversal: ";
    for (int val : result)
        cout << val << " ";

    return 0;
}
