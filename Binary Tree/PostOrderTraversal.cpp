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

void post(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    post(root->left, res);
    post(root->right, res);
    res.push_back(root->data);
}

vector<int> postOrder(Node *root)
{
    vector<int> res;
    post(root, res);
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
        Postorder: 4 5 2 3 1
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrder(root);

    cout << "Postorder Traversal: ";
    for (int val : result)
        cout << val << " ";

    return 0;
}
