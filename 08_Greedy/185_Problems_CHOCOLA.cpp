/*
QUESTION:-

A chocolate bar is made of m x n unit squares, and it has m - 1 horizontal break
lines and n - 1 vertical break lines. Breaking the chocolate along a line has a
cost, which is given for every line. When a line is used, the break is made in
every piece that the line passes through at that moment, and the cost of the
break is the cost of the line multiplied by the number of pieces it is applied
to. Find the minimum total cost to break the whole bar into the m x n unit
squares.

Constraints:
2 <= m, n <= 1000
0 <= cost of a line <= 1000

Example 1:

Input:
m = 6, n = 4
horizontal = [2,1,3,1,4]
vertical = [4,1,2]

Output:
42

Example 2:

Input:
m = 2, n = 2
horizontal = [1]
vertical = [1]

Output:
3
*/

/*
APPROACH:-

-> A line that is used later is applied to more pieces, so it costs more. So the most expensive lines should be used first, when there are only few pieces.
-> Sort the horizontal costs and the vertical costs in decreasing order.
-> Keep rows = 1 (the number of horizontal strips made so far) and cols = 1 (the number of vertical strips made so far).
-> Repeatedly take the larger one of the two next costs. If it is a horizontal line, the break is applied to cols pieces, so add cost * cols to the total and increase rows by 1. If it is a vertical line, add cost * rows and increase cols by 1.
-> When one list is finished, apply all the remaining lines of the other list in the same way.
-> Let M and N be the sizes of the bar. Sorting costs M * log M + N * log N, and the merge costs M + N, so the time is M * log M + N * log N.
-> Only the cost lists are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long minimumBreakCost(vector<int> &horizontal, vector<int> &vertical)
{
    sort(horizontal.begin(), horizontal.end(), greater<int>());
    sort(vertical.begin(), vertical.end(), greater<int>());

    int i = 0;
    int j = 0;
    long long rows = 1;
    long long cols = 1;
    long long total = 0;

    while (i < (int)horizontal.size() && j < (int)vertical.size())
    {
        if (horizontal[i] >= vertical[j])
        {
            total += horizontal[i] * cols;
            rows++;
            i++;
        }
        else
        {
            total += vertical[j] * rows;
            cols++;
            j++;
        }
    }

    while (i < (int)horizontal.size())
    {
        total += horizontal[i] * cols;
        rows++;
        i++;
    }

    while (j < (int)vertical.size())
    {
        total += vertical[j] * rows;
        cols++;
        j++;
    }

    return total;
}

int main()
{
    vector<int> horizontal = {2, 1, 3, 1, 4};
    vector<int> vertical = {4, 1, 2};

    cout << minimumBreakCost(horizontal, vertical) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(M * log M + N * log N)
SPACE COMPLEXITY = O(1)
*/
