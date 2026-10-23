/*
QUESTION:-

Design a stack that supports push, pop, top and retrieving the minimum element,
all in constant time. Implement push(val), pop(), top() and getMin(). top() and
getMin() return -1 when the stack is empty.

Constraints:
-100000 <= val <= 100000
Every operation must run in O(1) time.

Example 1:

Input:
push(-2), push(0), push(-3), getMin(), pop(), top(), getMin()

Output:
-3 0 -2

Example 2:

Input:
push(5), push(7), getMin(), pop(), getMin()

Output:
5 5
*/

/*
APPROACH:-

-> Store pairs in a single stack: every pair holds the value itself and the minimum of the stack at the moment that value was pushed.
-> On push, the new minimum is min(value, minimum stored in the current top pair). For the very first element the minimum is the value itself.
-> On pop, simply remove the top pair. The pair below it still remembers the correct minimum for the smaller stack.
-> top returns the first part of the top pair, and getMin returns the second part of the top pair.
-> No searching is needed, so each operation takes constant time.
-> The price for this speed is storing one extra integer per element.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> data;

public:
    void push(int value)
    {
        if (data.empty())
        {
            data.push({value, value});
        }
        else
        {
            int currentMin = min(value, data.top().second);
            data.push({value, currentMin});
        }
    }

    void pop()
    {
        if (!data.empty())
        {
            data.pop();
        }
    }

    int top()
    {
        if (data.empty())
        {
            return -1;
        }

        return data.top().first;
    }

    int getMin()
    {
        if (data.empty())
        {
            return -1;
        }

        return data.top().second;
    }
};

int main()
{
    MinStack stack;

    stack.push(-2);
    stack.push(0);
    stack.push(-3);

    cout << stack.getMin() << "\n";

    stack.pop();

    cout << stack.top() << "\n";
    cout << stack.getMin() << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(N)
*/
