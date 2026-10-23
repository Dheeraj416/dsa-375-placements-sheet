/*
QUESTION:-

Implement two stacks in a single array of size n. Both stacks must be able to
grow, and a push must succeed as long as there is any free space in the array
(so you cannot give each stack a fixed half of the array). Support these
operations: push1(x), push2(x), pop1() and pop2(). A push on a full array is
ignored, and a pop on an empty stack returns -1.

Constraints:
1 <= n <= 100000
1 <= x <= 100000

Example 1:

Input:
n = 5
push1(2), push1(3), push2(4), pop1(), pop2(), pop1(), pop1()

Output:
3 4 2 -1

Example 2:

Input:
n = 2
push1(10), push2(20), push1(30), pop1(), pop2()
(the third push is ignored because the array is full)

Output:
10 20
*/

/*
APPROACH:-

-> Let the first stack grow from the left end of the array and the second stack grow from the right end. They grow towards each other.
-> Keep two indexes: top1 starts at -1 (empty) and top2 starts at n (empty).
-> push1: if top1 + 1 < top2 there is a free cell. Then increase top1 and store the value there.
-> push2: if top1 + 1 < top2 there is a free cell. Then decrease top2 and store the value there.
-> pop1: if top1 >= 0, return arr[top1] and decrease top1. Otherwise return -1.
-> pop2: if top2 < n, return arr[top2] and increase top2. Otherwise return -1.
-> The array is full exactly when top1 + 1 == top2, so no space is wasted.
-> Every operation takes constant time, so the time is 1 per operation.
-> The array takes N space where N is the size n.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct TwoStacks
{
    vector<int> arr;
    int size;
    int top1;
    int top2;

    TwoStacks(int n)
    {
        size = n;
        arr.assign(n, 0);
        top1 = -1;
        top2 = n;
    }

    void push1(int x)
    {
        if (top1 + 1 < top2)
        {
            top1++;
            arr[top1] = x;
        }
    }

    void push2(int x)
    {
        if (top1 + 1 < top2)
        {
            top2--;
            arr[top2] = x;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        return -1;
    }

    int pop2()
    {
        if (top2 < size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        return -1;
    }
};

int main()
{
    TwoStacks stacks(5);

    stacks.push1(2);
    stacks.push1(3);
    stacks.push2(4);

    cout << stacks.pop1() << " ";
    cout << stacks.pop2() << " ";
    cout << stacks.pop1() << " ";
    cout << stacks.pop1() << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(1)
SPACE COMPLEXITY = O(N)
*/
