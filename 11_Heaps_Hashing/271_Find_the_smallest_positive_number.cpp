/*
QUESTION:-

Given an unsorted array of integers (which can contain negative numbers, zeros
and duplicates), find the smallest positive integer that is missing from it.

Constraints:
1 <= n <= 100000
-1000000000 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [2,3,7,6,8,-1,-10,15]

Output:
1

Example 2:

Input:
arr = [1,2,0]

Output:
3
*/

/*
APPROACH:-

-> The answer is always between 1 and n + 1, because an array of n numbers can contain at most n different positive integers. If 1 to n are all present, the answer is n + 1.
-> Put all the positive numbers of the array into a hash set.
-> Start from 1 and check whether it is in the set. The first number that is not in the set is the answer.
-> The check loop runs at most n + 1 times, because the set cannot contain more than n values.
-> Let N be the size of the array. Building the set costs N and the check loop costs at most N + 1, so the time is N.
-> The set holds up to N numbers, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int smallestMissingPositive(vector<int> &arr)
{
    unordered_set<int> present;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            present.insert(arr[i]);
        }
    }

    int answer = 1;
    while (present.count(answer) > 0)
    {
        answer++;
    }

    return answer;
}

int main()
{
    vector<int> arr = {2, 3, 7, 6, 8, -1, -10, 15};

    cout << smallestMissingPositive(arr) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
