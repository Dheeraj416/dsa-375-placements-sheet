/*
QUESTION:-

Evaluate a postfix (reverse Polish) expression. The expression is a string in
which every operand is a single digit (0 to 9) and the operators are +, -, *
and /. The division is an integer division. Return the value of the expression.

Constraints:
1 <= length of expression <= 100000
The expression is always valid.

Example 1:

Input:
expression = "231*+9-"

Output:
-4
(2 + 3 * 1 = 5, and 5 - 9 = -4)

Example 2:

Input:
expression = "123+*8-"

Output:
-3
(1 * (2 + 3) = 5, and 5 - 8 = -3)
*/

/*
APPROACH:-

-> In a postfix expression the operator comes after its two operands, so we can evaluate it from left to right using a stack.
-> If the character is a digit, convert it to a number and push it on the stack.
-> If the character is an operator, pop two numbers. The first one popped is the right operand b and the second one popped is the left operand a.
-> Compute a op b and push the result back on the stack.
-> When the whole string is read, exactly one number is left on the stack. That is the answer.
-> Let N be the length of the expression. Every character is handled once with constant work, so the time is N.
-> The stack can hold up to N numbers, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string expression)
{
    stack<int> values;

    for (int i = 0; i < (int)expression.size(); i++)
    {
        char c = expression[i];

        if (c >= '0' && c <= '9')
        {
            values.push(c - '0');
        }
        else
        {
            int b = values.top();
            values.pop();
            int a = values.top();
            values.pop();

            if (c == '+')
            {
                values.push(a + b);
            }
            else if (c == '-')
            {
                values.push(a - b);
            }
            else if (c == '*')
            {
                values.push(a * b);
            }
            else
            {
                values.push(a / b);
            }
        }
    }

    return values.top();
}

int main()
{
    string expression = "231*+9-";

    cout << evaluatePostfix(expression) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
