/*
QUESTION:-

Given a queue of integers, reverse the order of its elements using only the
standard queue operations (push, pop, front, empty, size) and one extra stack.

Constraints:
1 <= number of elements <= 100000
1 <= element <= 100000

Example 1:

Input:
queue = [5,24,9,6,8,4,1,2]   (front is 5)

Output:
[2,1,4,8,6,9,24,5]

Example 2:

Input:
queue = [4,3,1,10,2,6]

Output:
[6,2,10,1,3,4]
*/

/*
APPROACH:-

-> A stack gives the elements back in the opposite order, which is exactly what we need.
-> Remove all the elements from the front of the queue one by one and push them on a stack.
-> Now the last element of the queue is on the top of the stack.
-> Pop the elements from the stack one by one and push them into the queue. The queue now has the elements in reversed order.
-> Let N be the number of elements. Every element is moved twice, so the time is N.
-> The stack holds up to N elements, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> helper;

    while (!q.empty())
    {
        helper.push(q.front());
        q.pop();
    }

    while (!helper.empty())
    {
        q.push(helper.top());
        helper.pop();
    }
}

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

int main()
{
    vector<int> values = {5, 24, 9, 6, 8, 4, 1, 2};
    queue<int> q;
    for (int i = 0; i < (int)values.size(); i++)
    {
        q.push(values[i]);
    }

    reverseQueue(q);

    printQueue(q);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
