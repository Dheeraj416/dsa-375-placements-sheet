/*
QUESTION:-

A deque (double ended queue) allows insertion and removal at both ends.
Implement a Stack and a Queue using a deque. The stack needs push(x), pop(),
top() and isEmpty(). The queue needs push(x), pop(), front() and isEmpty().
pop() removes the element and returns it. It is never called on an empty
structure. isEmpty() returns 1 when empty and 0 otherwise.

Constraints:
1 <= number of operations <= 100000
1 <= x <= 100000

Example 1:

Input:
Stack: push(10), push(20), push(30), pop(), top()
Queue: push(10), push(20), push(30), pop(), front()

Output:
30 20
10 20

Example 2:

Input:
Stack: push(7), push(8), pop(), pop(), isEmpty()
Queue: push(7), push(8), pop(), pop(), isEmpty()

Output:
8 7 1
7 8 1
*/

/*
APPROACH:-

-> For the stack we need last in first out, so we use only one end of the deque: the back.
-> Stack push uses push_back, stack pop reads back() and then calls pop_back, and stack top reads back().
-> For the queue we need first in first out, so we add at the back and remove from the front.
-> Queue push uses push_back, queue pop reads front() and then calls pop_front, and queue front reads front().
-> isEmpty is simply the empty() of the deque.
-> All the deque operations at the two ends take constant time, so every operation costs 1.
-> The deque stores N elements, where N is the number of elements pushed, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct StackUsingDeque
{
    deque<int> data;

    void push(int x)
    {
        data.push_back(x);
    }

    int pop()
    {
        int x = data.back();
        data.pop_back();
        return x;
    }

    int top()
    {
        return data.back();
    }

    int isEmpty()
    {
        if (data.empty())
        {
            return 1;
        }
        return 0;
    }
};

struct QueueUsingDeque
{
    deque<int> data;

    void push(int x)
    {
        data.push_back(x);
    }

    int pop()
    {
        int x = data.front();
        data.pop_front();
        return x;
    }

    int front()
    {
        return data.front();
    }

    int isEmpty()
    {
        if (data.empty())
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    StackUsingDeque stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    cout << stack1.pop() << " ";
    cout << stack1.top() << "\n";

    QueueUsingDeque queue1;
    queue1.push(10);
    queue1.push(20);
    queue1.push(30);
    cout << queue1.pop() << " ";
    cout << queue1.front() << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(N)
*/
