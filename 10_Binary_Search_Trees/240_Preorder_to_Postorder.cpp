/*
QUESTION:-

You are given the preorder traversal of a binary search tree (all values are
different). Print the postorder traversal of the same tree, without building
the tree.

Constraints:
1 <= number of nodes <= 100000
1 <= value <= 1000000

Example 1:

Input:
preorder = [40,30,35,80,100]

Output:
35 30 100 80 40

Example 2:

Input:
preorder = [8,5,1,7,10,12]

Output:
1 7 5 12 10 8
*/

/*
APPROACH:-

-> The first value of a preorder traversal is the root. The next values that are smaller than the root form the left subtree, and then the values larger than the root form the right subtree.
-> Use a recursive function with an index into the array (shared by all calls) and a range (low, high) of values that are allowed for the subtree it is going to read.
-> Look at pre[index]. If it is outside the range, it does not belong to this subtree, so return without using it.
-> Otherwise it is the root of this subtree: move the index forward, read the left subtree with the range (low, value), read the right subtree with the range (value, high), and then add the value to the answer. Adding the root after both subtrees is exactly the postorder.
-> Let N be the number of nodes. Each value is used once, so the time is N.
-> The answer takes N space, and the recursion goes as deep as the tree, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void toPostorder(vector<int> &pre, int &index, long long low, long long high, vector<int> &post)
{
    if (index >= (int)pre.size())
    {
        return;
    }

    int value = pre[index];

    if (value <= low || value >= high)
    {
        return;
    }

    index++;

    toPostorder(pre, index, low, value, post);
    toPostorder(pre, index, value, high, post);

    post.push_back(value);
}

int main()
{
    vector<int> pre = {40, 30, 35, 80, 100};
    vector<int> post;
    int index = 0;

    toPostorder(pre, index, LLONG_MIN, LLONG_MAX, post);

    for (int i = 0; i < (int)post.size(); i++)
    {
        cout << post[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
