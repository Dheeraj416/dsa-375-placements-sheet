/*
QUESTION:-

A board of size p x q is given. It has p - 1 horizontal cutting lines and q - 1
vertical cutting lines, and the cost of cutting along each line is given in the
arrays x (horizontal lines) and y (vertical lines). When a line is used, the cut
is made in every piece that the line passes through at that moment, and the
cost of the cut is the cost of the line multiplied by the number of pieces it is
applied to. Find the minimum total cost to cut the whole board into 1 x 1
squares.

Constraints:
2 <= p, q <= 1000
0 <= cost of a line <= 1000

Example 1:

Input:
p = 4, q = 4
x = [2,1,3]
y = [4,1,2]

Output:
27

Example 2:

Input:
p = 2, q = 2
x = [1]
y = [1]

Output:
3
*/

/*
APPROACH:-

-> A line used later is applied to more pieces, so it costs more. So the lines with the largest costs must be used first.
-> Sort both cost arrays in decreasing order and keep two counters: horizontalPieces = 1 and verticalPieces = 1.
-> Repeatedly pick the larger of the two next costs (if equal, pick from x). A horizontal cut passes through all the verticalPieces columns, so its price is cost * verticalPieces, and then horizontalPieces increases by 1. A vertical cut costs cost * horizontalPieces, and then verticalPieces increases by 1.
-> When one array is finished, use the rest of the other array in the same way.
-> Example 1: sorted x = 3, 2, 1 and y = 4, 2, 1. The order of cuts is y4 (4*1), x3 (3*2), x2 (2*2), y2 (2*3), x1 (1*3), y1 (1*4), which gives 4 + 6 + 4 + 6 + 3 + 4 = 27.
-> Let P and Q be the sides of the board. Sorting costs P * log P + Q * log Q and the merge costs P + Q, so the time is P * log P + Q * log Q.
-> Only the cost arrays are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long minimumCutCost(vector<int> &x, vector<int> &y)
{
    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());

    int i = 0;
    int j = 0;
    long long horizontalPieces = 1;
    long long verticalPieces = 1;
    long long total = 0;

    while (i < (int)x.size() && j < (int)y.size())
    {
        if (x[i] >= y[j])
        {
            total += x[i] * verticalPieces;
            horizontalPieces++;
            i++;
        }
        else
        {
            total += y[j] * horizontalPieces;
            verticalPieces++;
            j++;
        }
    }

    while (i < (int)x.size())
    {
        total += x[i] * verticalPieces;
        horizontalPieces++;
        i++;
    }

    while (j < (int)y.size())
    {
        total += y[j] * horizontalPieces;
        verticalPieces++;
        j++;
    }

    return total;
}

int main()
{
    vector<int> x = {2, 1, 3};
    vector<int> y = {4, 1, 2};

    cout << minimumCutCost(x, y) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(P * log P + Q * log Q)
SPACE COMPLEXITY = O(1)
*/
