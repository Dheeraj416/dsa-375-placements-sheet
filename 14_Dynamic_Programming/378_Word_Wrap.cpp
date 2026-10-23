/*
QUESTION:-

You are given an array nums where nums[i] is the number of characters in the i-th
word, and a line width K. The words must be written in the given order, with one
space between two words on the same line, and every line can hold at most K
characters. The extra spaces of a line are the unused places at the end of the
line, and the cost of the line is (extra spaces)^2. The last line has no cost.
Break the words into lines so that the total cost is as small as possible, and
return that cost.

Constraints:
1 <= nums.size() <= 500
1 <= nums[i] <= K <= 100

Example 1:

Input:
nums = [3,2,2,5], K = 6

Output:
10
(line 1: the first word, cost (6 - 3)^2 = 9; line 2: the second and third word, which take 2 + 1 + 2 = 5 places, cost (6 - 5)^2 = 1; line 3: the last word, no cost)

Example 2:

Input:
nums = [3,2,2], K = 4

Output:
5
(line 1: cost 1, line 2: cost 4, last line: no cost)
*/

/*
APPROACH:-

-> Let dp[i] be the minimum cost to write the words from index i to the end. dp[n] = 0, because there are no words left.
-> To compute dp[i], try putting the words i to j on the first line, for j = i, i + 1, ... while the line still fits. The width of such a line is the sum of the word lengths plus one space between neighbours.
-> If the line has width w and does not end at the last word, its cost is (K - w)^2. If it ends at the last word, its cost is 0. The rest of the words cost dp[j + 1].
-> dp[i] is the smallest value of (cost of the line + dp[j + 1]) over all j. Stop when the line does not fit any more.
-> Fill i from the last word down to the first word. The answer is dp[0].
-> Let N be the number of words. For every word we try at most K words on the line (each word has at least one letter), so the time is N * K.
-> The dp array has N + 1 values, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int wordWrap(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = INT_MAX;
        int width = -1;

        for (int j = i; j < n; j++)
        {
            width = width + nums[j] + 1;

            if (width > k)
            {
                break;
            }

            int cost = 0;

            if (j != n - 1)
            {
                int extra = k - width;
                cost = extra * extra;
            }

            dp[i] = min(dp[i], cost + dp[j + 1]);
        }
    }

    return dp[0];
}

int main()
{
    vector<int> nums = {3, 2, 2, 5};
    int k = 6;

    cout << wordWrap(nums, k) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * K)
SPACE COMPLEXITY = O(N)
*/
