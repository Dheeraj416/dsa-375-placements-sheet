/*
QUESTION:-

You are given n pairs of numbers. In every pair the first number is smaller than
the second number. A pair (c, d) can follow a pair (a, b) in a chain if b < c.
Find the length of the longest chain that can be formed from the given pairs.
You can select the pairs in any order.

Constraints:
1 <= n <= 100000
0 <= a < b <= 1000000000

Example 1:

Input:
pairs = [[5,24],[39,60],[15,28],[27,40],[50,90]]

Output:
3
(the chain (5,24) -> (27,40) -> (50,90))

Example 2:

Input:
pairs = [[1,2],[7,8],[4,5]]

Output:
3
(the chain (1,2) -> (4,5) -> (7,8))
*/

/*
APPROACH:-

-> This is the same idea as the activity selection problem: a pair is an interval, and we want the maximum number of non overlapping intervals.
-> Sort the pairs by their second number (the end), in increasing order.
-> Keep the end of the last selected pair in lastEnd (start with a very small value). Go through the sorted pairs.
-> If the first number of the current pair is greater than lastEnd, select the pair: increase the answer and set lastEnd to the second number of this pair.
-> Choosing the pair that ends first always leaves the most room for the next pairs, which is why the greedy choice works.
-> Let N be the number of pairs. Sorting costs N * log N and one pass costs N, so the time is N * log N.
-> Sorting is done in place, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool compareBySecond(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

int maxChainLength(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), compareBySecond);

    int length = 0;
    long long lastEnd = -1;

    for (int i = 0; i < (int)pairs.size(); i++)
    {
        if (pairs[i][0] > lastEnd)
        {
            length++;
            lastEnd = pairs[i][1];
        }
    }

    return length;
}

int main()
{
    vector<vector<int>> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};

    cout << maxChainLength(pairs) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
