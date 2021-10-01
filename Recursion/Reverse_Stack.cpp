#include<bits/stdc++.h>
using namespace std;
void PrintStack(stack<int> s);

void insert(stack<int>& s, int temp)
{
    if(s.empty())
    {
        s.push(temp);
        return;
    }

    int tempval = s.top();
    s.pop();

    insert(s,temp);

    s.push(tempval);

}
void ReverseStack(stack<int>& s){

    if(s.size()==0)
        return;

    int temp = s.top();
    s.pop();

    ReverseStack(s);
    
    insert(s,temp);

    
}
main()
{
    stack<int> s({1, 2, 3, 4, 5});

    PrintStack(s);

    ReverseStack(s);


    PrintStack(s);
}


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