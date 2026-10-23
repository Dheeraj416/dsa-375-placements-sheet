/*
QUESTION:-

There are three rods A, B and C. n disks of different sizes are stacked on rod A
with the smallest disk on the top. Move all the disks to rod C, moving one disk
at a time and never placing a bigger disk on a smaller one. Solve it
iteratively (without recursion) and print every move in the form
"Move disk X from P to Q", where the disks are numbered from 1 (smallest) to n.

Constraints:
1 <= n <= 15

Example 1:

Input:
n = 3

Output:
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C

Example 2:

Input:
n = 2

Output:
Move disk 1 from A to B
Move disk 2 from A to C
Move disk 1 from B to C
*/

/*
APPROACH:-

-> The puzzle needs exactly 2^n - 1 moves. In the iterative method, the moves follow a fixed repeating pattern of three steps.
-> Let source = A, auxiliary = B, destination = C. If n is odd, use the pair order (A, C), (A, B), (B, C). If n is even, swap the roles of B and C in the first two pairs, so the order is (A, B), (A, C), (B, C).
-> For move number i from 1 to 2^n - 1: if i % 3 == 1 make the legal move between the first pair, if i % 3 == 2 make the legal move between the second pair, and if i % 3 == 0 make the legal move between B and C.
-> A legal move between two rods means: if one rod is empty, move the top disk of the other rod onto it. Otherwise move the smaller top disk onto the bigger one. Only one direction is legal, so there is no choice to make.
-> We keep the real rods as three stacks, so the program can tell which disk is on top of which rod.
-> The number of moves is 2^n - 1, so the time is 2^N where N is the number of disks.
-> The stacks together hold N disks, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void moveDisk(stack<int> &from, stack<int> &to, char fromName, char toName)
{
    int disk = from.top();
    from.pop();
    to.push(disk);

    cout << "Move disk " << disk << " from " << fromName << " to " << toName << "\n";
}

void legalMove(stack<int> &first, stack<int> &second, char firstName, char secondName)
{
    if (first.empty())
    {
        moveDisk(second, first, secondName, firstName);
    }
    else if (second.empty())
    {
        moveDisk(first, second, firstName, secondName);
    }
    else if (first.top() < second.top())
    {
        moveDisk(first, second, firstName, secondName);
    }
    else
    {
        moveDisk(second, first, secondName, firstName);
    }
}

void towerOfHanoi(int n)
{
    stack<int> rods[3];
    char names[3] = {'A', 'B', 'C'};

    for (int disk = n; disk >= 1; disk--)
    {
        rods[0].push(disk);
    }

    int firstPair = 2;
    int secondPair = 1;
    if (n % 2 == 0)
    {
        firstPair = 1;
        secondPair = 2;
    }

    int totalMoves = (1 << n) - 1;

    for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 1)
        {
            legalMove(rods[0], rods[firstPair], names[0], names[firstPair]);
        }
        else if (i % 3 == 2)
        {
            legalMove(rods[0], rods[secondPair], names[0], names[secondPair]);
        }
        else
        {
            legalMove(rods[1], rods[2], names[1], names[2]);
        }
    }
}

int main()
{
    int n = 3;

    towerOfHanoi(n);

    return 0;
}

/*
TIME COMPLEXITY = O(2^N)
SPACE COMPLEXITY = O(N)
*/
