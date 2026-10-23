/*
QUESTION:-

Given a stack of integers, sort it so that the largest element is on top. You
may only use the stack operations push, pop, top and empty, and recursion. Do
not use any other data structure such as an array. Print the sorted stack from
top to bottom.

Constraints:
1 <= stack size <= 1000

Example 1:

Input:
stack (bottom to top) = [11, 2, 32, 3, 41]

Output:
41 32 11 3 2

Example 2:

Input:
stack (bottom to top) = [3, 2, 1]

Output:
3 2 1
*/

/*
APPROACH:-

-> Use recursion with two functions: sortStack and insertSorted.
-> sortStack removes the top element, recursively sorts the remaining stack, and then inserts the removed element back into its correct place.
-> insertSorted(value) puts a value into an already sorted stack. If the stack is empty or its top is not greater than the value, push the value directly.
-> Otherwise pop the top, insert the value into the smaller remaining stack recursively, and push the popped top back.
-> The recursion stack temporarily holds the elements that were removed, so no extra container is needed.
-> Every insertion can walk through the whole stack, which gives O(N^2) time overall.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &data, int value)
{
    if (data.empty() || data.top() <= value)
    {
        data.push(value);
        return;
    }

    int topValue = data.top();
    data.pop();

    insertSorted(data, value);

    data.push(topValue);
}

void sortStack(stack<int> &data)
{
    if (data.empty())
    {
        return;
    }

    int topValue = data.top();
    data.pop();

    sortStack(data);

    insertSorted(data, topValue);
}

int main()
{
    stack<int> data;

    data.push(11);
    data.push(2);
    data.push(32);
    data.push(3);
    data.push(41);

    sortStack(data);

    while (!data.empty())
    {
        cout << data.top() << " ";
        data.pop();
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N^2)
SPACE COMPLEXITY = O(N)
*/
