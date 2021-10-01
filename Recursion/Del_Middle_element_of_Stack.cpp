#include <bits/stdc++.h>
using namespace std;

void PrintStack(stack<int> s)
{
    // If stack is empty then return
    if (s.empty())
        return;

    int x = s.top();

    // Pop the top element of the stack
    s.pop();

    // Recursively call the function PrintStack
    PrintStack(s);

    // Print the stack element starting
    // from the bottom
    cout << x << " ";

    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

void delMidElement(stack<int> &s, int mid)
{
    if (mid == 1)
    {
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();

    mid--;
    delMidElement(s, mid);

    s.push(temp);
}
main()
{
    stack<int> s({1, 2, 3, 4, 5});

    PrintStack(s);
    
    int mid;
    if (s.size() % 2 != 0)
        mid = s.size() / 2 + 1;
    else
        mid = s.size() / 2;

    // After deleting element
    delMidElement(s, mid);
    cout << "--> Stack after deleting mid element";
    PrintStack(s);
}