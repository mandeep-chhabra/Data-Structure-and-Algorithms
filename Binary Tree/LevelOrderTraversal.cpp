#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> res;
    if (root == NULL)
        return res;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);

            level.push_back(node->data);
        }

        res.push_back(level);
    }

    return res;
}

int main()
{
    /*
        Sample Tree:
                1
               / \
              2   3
             / \   \
            4   5   6

        Level Order Output: [[1], [2, 3], [4, 5, 6]]
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<vector<int>> result = levelOrder(root);

    cout << "Level Order Traversal:\n";
    for (const auto &level : result)
    {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
