/*
QUESTION:-

Given a balanced expression, find whether it contains duplicate parentheses. A
pair of parentheses is a duplicate if it directly surrounds another pair of
parentheses, so the outer pair is not needed. For example "((a+b))" has
duplicate parentheses. Return true if the expression has duplicate parentheses
and false otherwise.

Constraints:
1 <= length of expression <= 100000
The expression has operands, operators and balanced parentheses.

Example 1:

Input:
expression = "((a+b)+((c+d)))"

Output:
true
(the pair around "(c+d)" is a duplicate)

Example 2:

Input:
expression = "(a+b)*(c+d)"

Output:
false
*/

/*
APPROACH:-

-> Push every character on a stack except ')'.
-> When a ')' comes, look at the top of the stack. If the top is '(' then there is nothing between this ')' and the '(' before it. That means the inner part was already removed as a pair, so this pair is a duplicate. Return true.
-> Otherwise pop the stack until a '(' is on the top, which removes the contents of this pair, and pop that '(' too.
-> If we reach the end without finding such a case, there are no duplicates, so return false.
-> Let N be the length of the expression. Every character is pushed and popped at most once, so the time is N.
-> The stack can hold up to N characters, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool hasDuplicateParentheses(string expression)
{
    stack<char> characters;

    for (int i = 0; i < (int)expression.size(); i++)
    {
        char c = expression[i];

        if (c == ')')
        {
            if (characters.top() == '(')
            {
                return true;
            }

            while (characters.top() != '(')
            {
                characters.pop();
            }
            characters.pop();
        }
        else
        {
            characters.push(c);
        }
    }

    return false;
}

int main()
{
    string expression = "((a+b)+((c+d)))";

    bool answer = hasDuplicateParentheses(expression);

    if (answer)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
