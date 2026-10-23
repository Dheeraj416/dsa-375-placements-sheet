/*
QUESTION:-

Given a string s that contains parentheses and letters, remove the minimum
number of invalid parentheses so that the resulting string is valid. Return all
the different strings that can be made (in any order). A string is valid if
every '(' has a matching ')' after it and every ')' has a matching '(' before
it. (In the example output the answers are printed in alphabetical order, one
per line.)

Constraints:
1 <= s.length <= 25
s contains lowercase letters, '(' and ')'
There are at most 20 parentheses in s.

Example 1:

Input:
s = "()())()"

Output:
(())()
()()()

Example 2:

Input:
s = "(a)())()"

Output:
(a())()
(a)()()

Example 3:

Input:
s = ")("

Output:
""
(the empty string)
*/

/*
APPROACH:-

-> We need the answers with the fewest removals. BFS visits the strings level by level, where level k holds all the strings made by removing exactly k parentheses. So the first level that contains a valid string gives the minimum removals.
-> Start with the original string in a queue and a set of visited strings (to avoid processing the same string twice).
-> Process one whole level at a time. For every string of the level, check if it is valid with a counter: add 1 for '(' and subtract 1 for ')'; the counter must never become negative and must be 0 at the end.
-> If a string is valid, add it to the answers. Once any valid string is found in a level, we stop going deeper after this level, but we still check all the other strings of this level.
-> If no string of the level is valid, create the next level: remove each parenthesis one at a time from each string and push the new unseen strings.
-> Sort the answers before printing so that the output order is fixed.
-> Let N be the length of the string. In the worst case there are 2^N different strings and checking one costs N, so the time is N * 2^N.
-> The queue and the visited set hold up to 2^N strings, so the space is N * 2^N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string &text)
{
    int balance = 0;

    for (char c : text)
    {
        if (c == '(')
        {
            balance++;
        }
        else if (c == ')')
        {
            balance--;
            if (balance < 0)
            {
                return false;
            }
        }
    }

    return balance == 0;
}

vector<string> removeInvalidParentheses(string s)
{
    vector<string> answers;
    set<string> visited;
    queue<string> level;

    level.push(s);
    visited.insert(s);

    bool found = false;

    while (!level.empty() && !found)
    {
        int size = level.size();

        for (int i = 0; i < size; i++)
        {
            string current = level.front();
            level.pop();

            if (isValid(current))
            {
                answers.push_back(current);
                found = true;
            }

            if (found)
            {
                continue;
            }

            for (int j = 0; j < (int)current.size(); j++)
            {
                if (current[j] != '(' && current[j] != ')')
                {
                    continue;
                }

                string next = current.substr(0, j) + current.substr(j + 1);

                if (visited.find(next) == visited.end())
                {
                    visited.insert(next);
                    level.push(next);
                }
            }
        }
    }

    sort(answers.begin(), answers.end());

    return answers;
}

int main()
{
    string s = "()())()";

    vector<string> answer = removeInvalidParentheses(s);

    for (string &text : answer)
    {
        cout << text << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * 2^N)
SPACE COMPLEXITY = O(N * 2^N)
*/
