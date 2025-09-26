#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

void printDeque(const deque<int> &dq)
{
    cout << "[";
    for (size_t i = 0; i < dq.size(); ++i)
    {
        cout << dq[i] << (i == dq.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

void rotateDeque(deque<int> &dq, int type, int k)
{
    if (dq.empty())
        return;
    k = k % dq.size();

    if (k == 0)
        return;

    if (type == 1)
    {
        for (int i = 0; i < k; i++)
        {
            int temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
        }
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            int temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
    }
}

int main()
{
    int size, k, type;
    cout << "Enter the number of elements in the deque: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Empty deque." << endl;
        return 0;
    }

    deque<int> dq;
    cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i)
    {
        int val;
        cin >> val;
        dq.push_back(val);
    }

    cout << "Enter rotation type (1 for right/clockwise, 2 for left/counter-clockwise): ";
    cin >> type;
    cout << "Enter rotation steps (k): ";
    cin >> k;

    cout << "Original Deque: ";
    printDeque(dq);

    rotateDeque(dq, type, k);

    cout << "Rotated Deque: ";
    printDeque(dq);

    return 0;
}