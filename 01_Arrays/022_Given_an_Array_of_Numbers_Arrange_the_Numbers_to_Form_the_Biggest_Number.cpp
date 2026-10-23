/*
QUESTION:-

Given an array of non-negative integers, arrange them in such an order that
they form the largest possible number when written one after another. Return
the number as a string, because it can be very big.

Constraints:
1 <= nums.length <= 100000
0 <= nums[i] <= 1000000000

Example 1:

Input:
nums = [3,30,34,5,9]

Output:
9534330

Example 2:

Input:
nums = [54,546,548,60]

Output:
6054854654
*/

/*
APPROACH:-

-> Sorting the numbers by their value does not work. For example 30 and 3: "303" is smaller than "330".
-> The correct rule: number a should come before number b if the text a + b is bigger than the text b + a.
-> Convert every number to a string and sort the strings using this rule (a custom compare function).
-> After sorting, join all the strings in order. This gives the biggest possible number.
-> Edge case: if the biggest number starts with 0, all the numbers were 0, so return "0" instead of "000".
-> Let N be the number of elements and D the maximum number of digits. Sorting does N * log N comparisons and each comparison costs D, so the time is N * log N * D.
-> The strings take N * D space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool comesFirst(const string &first, const string &second)
{
    return first + second > second + first;
}

string largestNumber(vector<int> &nums)
{
    vector<string> texts;

    for (int x : nums)
    {
        texts.push_back(to_string(x));
    }

    sort(texts.begin(), texts.end(), comesFirst);

    if (texts[0] == "0")
    {
        return "0";
    }

    string result = "";

    for (string &text : texts)
    {
        result = result + text;
    }

    return result;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};

    string answer = largestNumber(nums);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N * D)
SPACE COMPLEXITY = O(N * D)
*/
