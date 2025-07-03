#include <iostream>
using namespace std;

class twoStacks
{
public:
    int arr[200];
    int top1 = -1;
    int top2 = 200;

    twoStacks() {}

    void push1(int x)
    {
        if (top1 + 1 < top2)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack Overflow on push1" << endl;
        }
    }

    void push2(int x)
    {
        if (top2 - 1 > top1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            cout << "Stack Overflow on push2" << endl;
        }
    }

    int pop1()
    {
        if (top1 == -1)
        {
            return -1;
        }
        int temp = arr[top1];
        top1--;
        return temp;
    }

    int pop2()
    {
        if (top2 == 200)
        {
            return -1;
        }
        int temp = arr[top2];
        top2++;
        return temp;
    }
};

int main()
{
    twoStacks ts;

    ts.push1(10);
    ts.push1(20);
    ts.push1(30);

    ts.push2(40);
    ts.push2(50);
    ts.push2(60);

    cout << "Pop from stack1: " << ts.pop1() << endl; // 30
    cout << "Pop from stack1: " << ts.pop1() << endl; // 20

    cout << "Pop from stack2: " << ts.pop2() << endl; // 60
    cout << "Pop from stack2: " << ts.pop2() << endl; // 50

    return 0;
}
