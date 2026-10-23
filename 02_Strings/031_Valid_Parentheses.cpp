/*
QUESTION:-

Given a string s containing only the characters '(', ')', '{', '}', '[' and
']', determine whether the string is valid. A string is valid if every open
bracket is closed by the same type of bracket and the brackets are closed in
the correct order.

Constraints:
1 <= s.length <= 10000

Example 1:

Input:
s = "()[]{}"

Output:
true

Example 2:

Input:
s = "(]"

Output:
false
*/

/*
APPROACH:-

-> Use a stack to remember the open brackets that are still waiting for their closing bracket.
-> Go through the string. If the character is an opening bracket, push it on the stack.
-> If it is a closing bracket, the stack must not be empty and its top must be the matching opening bracket. Pop it. Otherwise the string is invalid.
-> The most recently opened bracket must be closed first, which is exactly the last in, first out behaviour of a stack.
-> At the end the stack must be empty. If open brackets are left over, the string is invalid.
-> A single pass over the string is enough.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string &text)
{
    stack<char> openBrackets;

    for (int i = 0; i < text.size(); i++)
    {
        char current = text[i];

        if (current == '(' || current == '{' || current == '[')
        {
            openBrackets.push(current);
        }
        else
        {
            if (openBrackets.empty())
            {
                return false;
            }

            char top = openBrackets.top();
            openBrackets.pop();

            if (current == ')' && top != '(')
            {
                return false;
            }

            if (current == '}' && top != '{')
            {
                return false;
            }

            if (current == ']' && top != '[')
            {
                return false;
            }
        }
    }

    return openBrackets.empty();
}

int main()
{
    string text = "()[]{}";

    bool answer = isValid(text);

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
