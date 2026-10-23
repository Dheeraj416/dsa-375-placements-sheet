/*
QUESTION:-

Given a string made only of the characters '(' and ')', find the length of the
longest valid (well formed) parentheses substring. A substring is valid if every
'(' has a matching ')' after it and the brackets are properly nested.

Constraints:
0 <= length of string <= 100000

Example 1:

Input:
s = ")()())"

Output:
4
(the longest valid substring is "()()")

Example 2:

Input:
s = "(()"

Output:
2
(the longest valid substring is "()")
*/

/*
APPROACH:-

-> Use a stack that stores indexes. First push -1. It marks the position just before the current valid stretch.
-> For every character at index i: if it is '(', push i.
-> If it is ')', pop the top. If the stack becomes empty, this ')' has no matching '(', so push i as the new marker for the start of the next valid stretch.
-> If the stack is not empty after the pop, the substring from stack.top() + 1 to i is valid, and its length is i - stack.top(). Update the best answer with it.
-> Return the best length found.
-> Let N be the length of the string. Each index is pushed and popped at most once, so the time is N.
-> The stack can hold up to N indexes, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> indexes;
    indexes.push(-1);
    int best = 0;

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
        {
            indexes.push(i);
        }
        else
        {
            indexes.pop();

            if (indexes.empty())
            {
                indexes.push(i);
            }
            else
            {
                best = max(best, i - indexes.top());
            }
        }
    }

    return best;
}

int main()
{
    string s = ")()())";

    cout << longestValidParentheses(s) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
