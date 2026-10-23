/*
QUESTION:-

You are given the lengths of N words and a line width k. Place the words in
lines, in the given order, so that every line holds as many characters as
possible without crossing the width k. Words in a line are separated by exactly
one space. The cost of a line is the square of the number of unused characters
(the extra spaces at its end). The last line costs nothing. Return the minimum
total cost of placing all the words.

Constraints:
1 <= N <= 500
1 <= words[i] <= k <= 2000

Example 1:

Input:
words = [3,2,2,5]
k = 6

Output:
10
(lines: "3" costs 3 * 3 = 9, "2 2" costs 1 * 1 = 1, "5" is the last line and costs 0)

Example 2:

Input:
words = [3,2,2]
k = 4

Output:
5
(lines: "3" costs 1, "2" costs 4, "2" is the last line and costs 0)
*/

/*
APPROACH:-

-> Greedily filling every line is not always the cheapest, because a very empty line costs a lot. So we use dynamic programming over the position of the first word of a line.
-> Let best[i] be the minimum cost to place the words from i to the end. best[N] = 0 (no words left).
-> For the words from i onwards, try to put the words i..j in one line for j = i, i + 1, ... as long as their total length plus the single spaces between them is at most k.
-> The cost of that line is (k - used)^2, except that if j is the last word the line costs 0. Then add best[j + 1], the best cost of the remaining words.
-> best[i] is the smallest total over all valid j. We fill best from i = N - 1 down to 0.
-> The answer is best[0].
-> Let N be the number of words. For every i we try up to N values of j, so the time is N * N.
-> The best array has N + 1 cells, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int wordWrap(vector<int> &words, int k)
{
    int n = words.size();
    vector<int> best(n + 1, INT_MAX);
    best[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int used = -1;

        for (int j = i; j < n; j++)
        {
            used = used + words[j] + 1;

            if (used > k)
            {
                break;
            }

            int lineCost = 0;

            if (j != n - 1)
            {
                lineCost = (k - used) * (k - used);
            }

            best[i] = min(best[i], lineCost + best[j + 1]);
        }
    }

    return best[0];
}

int main()
{
    vector<int> words = {3, 2, 2, 5};
    int k = 6;

    int answer = wordWrap(words, k);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N)
*/
