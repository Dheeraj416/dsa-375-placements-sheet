/*
QUESTION:-

Given a string num that contains only digits and an integer target, add the
binary operators '+', '-' or '*' between the digits (or add nothing, to join
digits into a bigger number) so that the expression evaluates to the target.
Return all the expressions that evaluate to the target. Numbers in the
expression cannot have leading zeros (for example "05" is not allowed, but a
single "0" is). (In the example output the expressions are printed in
alphabetical order, one per line.)

Constraints:
1 <= num.length <= 10
num contains only digits.
-2147483648 <= target <= 2147483647

Example 1:

Input:
num = "123"
target = 6

Output:
1*2*3
1+2+3

Example 2:

Input:
num = "105"
target = 5

Output:
1*0+5
10-5
*/

/*
APPROACH:-

-> We try every way to cut the digits into numbers and to put an operator between the numbers. Backtracking builds the expression from left to right.
-> The function search(index, value, lastOperand, expression) knows how many digits are used, the value of the expression so far, the last number that was added or subtracted (with its sign), and the expression text.
-> At each step choose the next number as the digits from index to end (for every possible end). Skip numbers with a leading zero, except the single digit "0" (stop extending once the first digit is '0').
-> For the first number there is no operator. For the next numbers try '+': value + number, '-': value - number, and '*': because multiplication binds tighter, undo the last operand and multiply it instead: value - lastOperand + lastOperand * number.
-> The last operand for '+' is +number, for '-' it is -number, and for '*' it is lastOperand * number.
-> When all the digits are used and value equals the target, save the expression. Use long long, because the values can be big.
-> Sort the answers to print them in a fixed order.
-> Let N be the number of digits. Between every two digits there are 4 choices (nothing, +, -, *), so the time is N * 4^N.
-> The recursion goes N deep and the expression strings have N characters, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void search(string &num, long long target, int index, long long value, long long lastOperand, string expression, vector<string> &answers)
{
    int n = num.size();

    if (index == n)
    {
        if (value == target)
        {
            answers.push_back(expression);
        }
        return;
    }

    for (int end = index; end < n; end++)
    {
        if (end > index && num[index] == '0')
        {
            break;
        }

        string part = num.substr(index, end - index + 1);
        long long number = stoll(part);

        if (index == 0)
        {
            search(num, target, end + 1, number, number, part, answers);
        }
        else
        {
            search(num, target, end + 1, value + number, number, expression + "+" + part, answers);
            search(num, target, end + 1, value - number, -number, expression + "-" + part, answers);
            search(num, target, end + 1, value - lastOperand + lastOperand * number, lastOperand * number, expression + "*" + part, answers);
        }
    }
}

vector<string> addOperators(string num, int target)
{
    vector<string> answers;

    search(num, target, 0, 0, 0, "", answers);

    sort(answers.begin(), answers.end());

    return answers;
}

int main()
{
    string num = "123";
    int target = 6;

    vector<string> answer = addOperators(num, target);

    for (string &expression : answer)
    {
        cout << expression << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N * 4^N)
SPACE COMPLEXITY = O(N)
*/
