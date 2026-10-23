/*
QUESTION:-

You are given n appointments in the order in which they are booked. Every
appointment is a pair [start, end] (both ends included). Two appointments
conflict if they have at least one common time point. For every appointment, in
the booking order, print all the earlier booked appointments that conflict with
it, one line for each pair, in the form "[s,e] conflicts with [s2,e2]". The
earlier appointments of the same new appointment are printed in increasing order
of their start time (appointments with the same start time are printed in the
booking order).

Constraints:
1 <= n <= 100000
1 <= start <= end <= 1000000000

Example 1:

Input:
appointments = [[1,5],[3,7],[10,15],[4,12]]

Output:
[3,7] conflicts with [1,5]
[4,12] conflicts with [1,5]
[4,12] conflicts with [3,7]
[4,12] conflicts with [10,15]

Example 2:

Input:
appointments = [[1,2],[3,4],[2,3]]

Output:
[2,3] conflicts with [1,2]
[2,3] conflicts with [3,4]
*/

/*
APPROACH:-

-> Store the booked appointments in an interval tree. It is a BST in which each node holds one appointment and the tree is ordered by the start time. Each node also keeps maxHigh, the largest end time in its subtree.
-> The maxHigh value lets us skip a whole subtree: if the left subtree has maxHigh < start of the new appointment, none of its appointments can reach the new one, so we do not need to look there.
-> For a new appointment [low, high], search the tree in the inorder order: look into the left subtree if its maxHigh >= low, then check the node itself (conflict when node.low <= high and low <= node.high), then look into the right subtree only if node.low <= high (all the starts there are at least node.low).
-> Doing it in this order prints the conflicting appointments in increasing order of the start time.
-> After the search, insert the new appointment into the tree by its start time and update maxHigh on the way down.
-> Let N be the number of appointments and K the number of conflicts. For a balanced tree each search takes about log N plus the number of conflicts found, so the time is about N * log N + K. In the worst case (a skewed tree) it can be N * N.
-> The tree stores N appointments, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct IntervalNode
{
    int low;
    int high;
    int maxHigh;
    IntervalNode *left;
    IntervalNode *right;

    IntervalNode(int l, int h)
    {
        low = l;
        high = h;
        maxHigh = h;
        left = nullptr;
        right = nullptr;
    }
};

IntervalNode *insertInterval(IntervalNode *root, int low, int high)
{
    if (root == nullptr)
    {
        return new IntervalNode(low, high);
    }

    if (root->maxHigh < high)
    {
        root->maxHigh = high;
    }

    if (low < root->low)
    {
        root->left = insertInterval(root->left, low, high);
    }
    else
    {
        root->right = insertInterval(root->right, low, high);
    }

    return root;
}

void findConflicts(IntervalNode *root, int low, int high)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left != nullptr && root->left->maxHigh >= low)
    {
        findConflicts(root->left, low, high);
    }

    if (root->low <= high && low <= root->high)
    {
        cout << "[" << low << "," << high << "] conflicts with [" << root->low << "," << root->high << "]\n";
    }

    if (root->low <= high)
    {
        findConflicts(root->right, low, high);
    }
}

int main()
{
    vector<vector<int>> appointments = {{1, 5}, {3, 7}, {10, 15}, {4, 12}};
    IntervalNode *root = nullptr;

    for (int i = 0; i < (int)appointments.size(); i++)
    {
        findConflicts(root, appointments[i][0], appointments[i][1]);
        root = insertInterval(root, appointments[i][0], appointments[i][1]);
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
