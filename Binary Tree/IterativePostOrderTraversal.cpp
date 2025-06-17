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

vector<int> postOrderIterative(Node *node)
{
    vector<int> res;
    if (node == NULL)
        return res;

    stack<Node *> s1, s2;
    s1.push(node);

    while (!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left != NULL)
            s1.push(temp->left);
        if (temp->right != NULL)
            s1.push(temp->right);
    }

    while (!s2.empty())
    {
        res.push_back(s2.top()->data);
        s2.pop();
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
             / \
            4   5
        Postorder: 4 5 2 3 1
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrderIterative(root);

    cout << "Postorder Traversal (Iterative): ";
    for (int val : result)
        cout << val << " ";

    return 0;
}
