/*
QUESTION:-

Implement k stacks in a single array of size n. The array space must be used
efficiently: a push must succeed whenever any cell of the array is free, no
matter which stack it belongs to. Support push(x, s), which pushes x on stack s,
and pop(s), which pops and returns the top of stack s. A push on a full array is
ignored, and a pop on an empty stack returns -1. The stacks are numbered from 0.

Constraints:
1 <= k <= n <= 100000
1 <= x <= 100000

Example 1:

Input:
k = 3, n = 10
push(15, 2), push(45, 2), push(17, 1), push(49, 1), push(39, 1),
push(11, 0), push(9, 0), push(7, 0), pop(2), pop(1), pop(0)

Output:
45 39 7

Example 2:

Input:
k = 2, n = 2
push(1, 0), push(2, 0), push(3, 1), pop(1), pop(0)
(the third push is ignored because the array is full)

Output:
-1 2
*/

/*
APPROACH:-

-> Besides the data array arr of size n, keep a top array of size k (the index of the top element of every stack, -1 if empty) and a link array of size n.
-> The link array has two uses. For a cell that holds an element, link[i] is the index of the element just below it in the same stack (-1 if none). For a free cell, link[i] is the index of the next free cell. So the free cells form a chain, and freeSpot points to the first free cell.
-> At the start all cells are free: link[i] = i + 1, the last link is -1, and freeSpot = 0.
-> push(x, s): if freeSpot is -1 the array is full, so ignore. Otherwise take index = freeSpot, move freeSpot to link[index], store x in arr[index], set link[index] = top[s] (the old top of this stack) and then top[s] = index.
-> pop(s): if top[s] is -1 return -1. Otherwise take index = top[s], set top[s] = link[index], put the cell back in the free chain (link[index] = freeSpot, freeSpot = index) and return arr[index].
-> Every operation changes a few indexes, so the time is 1 per operation.
-> The three arrays take about N + K space, where N is the array size and K the number of stacks.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct KStacks
{
    vector<int> arr;
    vector<int> top;
    vector<int> link;
    int freeSpot;

    KStacks(int k, int n)
    {
        arr.assign(n, 0);
        top.assign(k, -1);
        link.assign(n, -1);

        for (int i = 0; i < n - 1; i++)
        {
            link[i] = i + 1;
        }
        link[n - 1] = -1;

        freeSpot = 0;
    }

    void push(int x, int s)
    {
        if (freeSpot == -1)
        {
            return;
        }

        int index = freeSpot;
        freeSpot = link[index];

        arr[index] = x;
        link[index] = top[s];
        top[s] = index;
    }

    int pop(int s)
    {
        if (top[s] == -1)
        {
            return -1;
        }

        int index = top[s];
        top[s] = link[index];

        link[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main()
{
    KStacks stacks(3, 10);

    stacks.push(15, 2);
    stacks.push(45, 2);
    stacks.push(17, 1);
    stacks.push(49, 1);
    stacks.push(39, 1);
    stacks.push(11, 0);
    stacks.push(9, 0);
    stacks.push(7, 0);

    cout << stacks.pop(2) << " ";
    cout << stacks.pop(1) << " ";
    cout << stacks.pop(0) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(N + K)
*/
