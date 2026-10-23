/*
QUESTION:-

Given a binary string s, find the maximum difference between the number of 0s
and the number of 1s (count of 0s minus count of 1s) over all substrings of s.
If the string contains only 1s, the answer is -1.

Constraints:
1 <= s.length <= 100000
s contains only the characters '0' and '1'.

Example 1:

Input:
s = "11000010001"

Output:
6
(the substring "00001000" has 7 zeros and 1 one)

Example 2:

Input:
s = "111"

Output:
-1
(every substring has more 1s than 0s, and the best choice is a single '1')
*/

/*
APPROACH:-

-> Give every '0' the value +1 and every '1' the value -1. Then for a substring, "number of 0s minus number of 1s" is just the sum of its values.
-> So the task is to find the maximum sum of a non-empty substring. This is the maximum subarray problem, solved by Kadane's algorithm.
-> Go from left to right and keep current, the best sum of a substring that ends at the current character. Either the substring starts here (current = value), or it extends the previous one (current = previous current + value). Take the larger one.
-> Keep best, the largest current seen so far. Start best with -1, because the answer can never be smaller than -1 (a single character gives +1 or -1).
-> Let N be the length of the string. We go through it once, so the time is N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int maxDifference(string s)
{
    int current = 0;
    int best = -1;

    for (int i = 0; i < (int)s.size(); i++)
    {
        int value = -1;

        if (s[i] == '0')
        {
            value = 1;
        }

        current = max(value, current + value);
        best = max(best, current);
    }

    return best;
}

int main()
{
    string s = "11000010001";

    cout << maxDifference(s) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
