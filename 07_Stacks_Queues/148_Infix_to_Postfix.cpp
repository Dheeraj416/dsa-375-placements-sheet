/*
QUESTION:-

Convert an infix expression to a postfix expression. The operands are single
letters or digits. The operators are +, -, *, / and ^ (power), and the
expression can contain parentheses. The operators + - have the lowest
precedence, then * /, then ^. All operators are left associative except ^,
which is right associative.

Constraints:
1 <= length of expression <= 100000
The expression is always valid.

Example 1:

Input:
expression = "a+b*(c^d-e)^(f+g*h)-i"

Output:
abcd^e-fgh*+^*+i-

Example 2:

Input:
expression = "A*(B+C)/D"

Output:
ABC+*D/
*/

/*
APPROACH:-

-> Read the expression from left to right and use a stack to hold the operators and the opening brackets. The answer string is built in result.
-> If the character is an operand (a letter or a digit), append it to result directly.
-> If the character is '(', push it on the stack.
-> If the character is ')', pop operators from the stack into result until '(' is on the top, then pop and discard the '('.
-> If the character is an operator, first pop operators from the stack into result as long as the top is not '(' and the top operator must be done before the current one. That is the case when the top has a higher precedence, or an equal precedence and the current operator is left associative (not ^). Then push the current operator.
-> At the end, pop all remaining operators from the stack into result.
-> Let N be the length of the expression. Each character is pushed and popped at most once, so the time is N.
-> The stack can hold up to N characters, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}

string infixToPostfix(string expression)
{
    stack<char> operators;
    string result = "";

    for (int i = 0; i < (int)expression.size(); i++)
    {
        char c = expression[i];

        if (isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                result += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else
        {
            while (!operators.empty() && operators.top() != '(')
            {
                int topPrecedence = precedence(operators.top());
                int currentPrecedence = precedence(c);

                if (topPrecedence > currentPrecedence || (topPrecedence == currentPrecedence && c != '^'))
                {
                    result += operators.top();
                    operators.pop();
                }
                else
                {
                    break;
                }
            }
            operators.push(c);
        }
    }

    while (!operators.empty())
    {
        result += operators.top();
        operators.pop();
    }

    return result;
}

int main()
{
    string expression = "a+b*(c^d-e)^(f+g*h)-i";

    cout << infixToPostfix(expression) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
