/*
QUESTION:-

Given an array of digits (values from 0 to 9), build two numbers using all the
digits of the array, so that the sum of the two numbers is as small as
possible. Every digit must be used exactly once. Return the minimum sum.

Constraints:
2 <= n <= 18
0 <= arr[i] <= 9

Example 1:

Input:
arr = [6,8,4,5,2,3]

Output:
604
(the numbers 246 and 358 give 246 + 358 = 604)

Example 2:

Input:
arr = [5,3,0,7,4]

Output:
82
(the numbers 047 and 35 give 47 + 35 = 82)
*/

/*
APPROACH:-

-> To keep the sum small, the numbers should be as short as possible, so the digits are shared equally (the two numbers differ in length by at most one digit).
-> Also the small digits should be at the most significant places. So sort the digits in increasing order.
-> Give the digits to the two numbers one by one in sorted order: the digits at even positions go to the first number and the digits at odd positions go to the second number.
-> Build each number by multiplying by 10 and adding the next digit. A leading 0 simply does not change the value.
-> Return the sum of the two numbers, using long long because the sum can be up to 18 digits.
-> Let N be the number of digits. Sorting costs N * log N, so the time is N * log N.
-> Only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

long long minimumSum(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    long long first = 0;
    long long second = 0;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (i % 2 == 0)
        {
            first = first * 10 + arr[i];
        }
        else
        {
            second = second * 10 + arr[i];
        }
    }

    return first + second;
}

int main()
{
    vector<int> arr = {6, 8, 4, 5, 2, 3};

    cout << minimumSum(arr) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(1)
*/
