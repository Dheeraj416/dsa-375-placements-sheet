/*
QUESTION:-

Given a queue of integers and a number k, reverse the order of the first k
elements of the queue and leave the remaining elements in their original
order.

Constraints:
1 <= k <= number of elements <= 100000
1 <= element <= 100000

Example 1:

Input:
queue = [10,20,30,40,50,60,70,80,90,100]   (front is 10)
k = 5

Output:
[50,40,30,20,10,60,70,80,90,100]

Example 2:

Input:
queue = [1,2,3,4,5]
k = 3

Output:
[3,2,1,4,5]
*/

/*
APPROACH:-

-> Remove the first k elements from the front of the queue and push them on a stack.
-> Pop the stack one by one and push each element at the back of the queue. The k elements are now reversed, but they are at the back of the queue.
-> The remaining n - k elements are in front of them. Move each of those from the front to the back, one by one, n - k times.
-> After that the reversed k elements are at the front, followed by the untouched elements in their original order.
-> Let N be the number of elements. Each element is moved at most twice, so the time is N.
-> The stack holds k elements, so the space is K.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void reverseFirstK(queue<int> &q, int k)
{
    if (k <= 0 || k > (int)q.size())
    {
        return;
    }

    stack<int> helper;

    for (int i = 0; i < k; i++)
    {
        helper.push(q.front());
        q.pop();
    }

    while (!helper.empty())
    {
        q.push(helper.top());
        helper.pop();
    }

    int remaining = (int)q.size() - k;
    for (int i = 0; i < remaining; i++)
    {
        q.push(q.front());
        q.pop();
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
    vector<int> values = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    queue<int> q;
    for (int i = 0; i < (int)values.size(); i++)
    {
        q.push(values[i]);
    }

    reverseFirstK(q, 5);

    printQueue(q);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(K)
*/
