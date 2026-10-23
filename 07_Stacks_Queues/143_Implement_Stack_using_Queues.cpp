/*
QUESTION:-

Implement a last in, first out (LIFO) stack using only one queue. The stack
must support push(x), pop(), top() and isEmpty(), and also size(). Only the
standard queue operations (push to back, pop from front, peek at front, size
and empty) may be used on the underlying queue.

Constraints:
1 <= x <= 1000000
At most 100 operations are performed.

Example 1:

Input:
push(1), push(2), push(3), top(), pop(), top(), size()

Output:
3 3 2 2

Example 2:

Input:
push(7), top(), pop(), isEmpty()

Output:
7 7 true
*/

/*
APPROACH:-

-> A queue is first in, first out, so to imitate a stack the newest element must always be at the front of the queue.
-> On push, add the new element at the back of the queue, then rotate the queue size - 1 times: move the front element to the back each time.
-> After the rotations the new element is at the front and the older elements follow it in reverse arrival order.
-> Now pop is just removing the front of the queue and top is just reading the front.
-> push costs O(N) because of the rotations, while pop, top, size and isEmpty cost O(1).
-> Only a single queue is used, so no second queue is needed.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

class StackUsingQueue
{
private:
    queue<int> data;

public:
    void push(int value)
    {
        data.push(value);

        int rotations = (int)data.size() - 1;

        for (int i = 0; i < rotations; i++)
        {
            data.push(data.front());
            data.pop();
        }
    }

    int pop()
    {
        if (data.empty())
        {
            return -1;
        }

        int value = data.front();
        data.pop();
        return value;
    }

    int top()
    {
        if (data.empty())
        {
            return -1;
        }

        return data.front();
    }

    bool isEmpty()
    {
        return data.empty();
    }

    int size()
    {
        return (int)data.size();
    }
};

int main()
{
    StackUsingQueue stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.top() << "\n";
    cout << stack.pop() << "\n";
    cout << stack.top() << "\n";
    cout << stack.size() << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
