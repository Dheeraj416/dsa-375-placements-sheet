/*
QUESTION:-

At a party there are N people numbered from 0 to N - 1. A celebrity is a person
who is known by everybody else but does not know anybody. You are given an N x N
matrix knows where knows[a][b] = 1 means that person a knows person b, and 0
means a does not know b. Find the celebrity, or return -1 if there is no
celebrity. There is at most one celebrity.

Constraints:
2 <= N <= 1000
knows[i][i] = 0

Example 1:

Input:
knows = [[0,1,0],[0,0,0],[0,1,0]]

Output:
1

Example 2:

Input:
knows = [[0,1],[1,0]]

Output:
-1
*/

/*
APPROACH:-

-> Eliminate people instead of checking everybody against everybody. Use two pointers, top = 0 and down = N - 1.
-> If top knows down, top cannot be the celebrity (a celebrity knows nobody), so move top forward.
-> Else if down knows top, down cannot be the celebrity, so move down backward.
-> If neither knows the other, neither of them can be the celebrity, so move both pointers.
-> Each comparison removes at least one person, so after N - 1 comparisons at most one candidate remains.
-> The remaining candidate is only a possibility, so verify it: it must know nobody and everybody else must know it.
-> If the pointers crossed or the verification fails, there is no celebrity.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int findCelebrity(vector<vector<int>> &knows)
{
    int n = (int)knows.size();
    int top = 0;
    int down = n - 1;

    while (top < down)
    {
        if (knows[top][down] == 1)
        {
            top++;
        }
        else if (knows[down][top] == 1)
        {
            down--;
        }
        else
        {
            top++;
            down--;
        }
    }

    if (top > down)
    {
        return -1;
    }

    int candidate = top;

    for (int i = 0; i < n; i++)
    {
        if (i == candidate)
        {
            continue;
        }

        if (knows[candidate][i] == 1 || knows[i][candidate] == 0)
        {
            return -1;
        }
    }

    return candidate;
}

int main()
{
    vector<vector<int>> knows = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    int answer = findCelebrity(knows);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
