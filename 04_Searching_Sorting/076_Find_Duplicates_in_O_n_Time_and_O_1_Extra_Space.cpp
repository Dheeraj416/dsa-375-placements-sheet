/*
QUESTION:-

You are given an array of n integers where every value is in the range 0 to
n - 1. Find all the elements that appear more than once, using O(n) time and
O(1) extra space (not counting the answer). Print each duplicate once, in
increasing order. If there is no duplicate, print -1.

Constraints:
1 <= n <= 40000
0 <= arr[i] <= n - 1

Example 1:

Input:
arr = [1,6,3,1,3,6,6]

Output:
1 3 6

Example 2:

Input:
arr = [2,3,1,2,3]

Output:
2 3
*/

/*
APPROACH:-

-> Because every value is between 0 and n - 1, a value can be used as an index into the same array. We use the array itself to count how often each value appears.
-> For each element, find its original value with arr[i] % n (the numbers we add later are multiples of n, so the remainder is not changed). Then add n to arr[value]. So arr[v] / n tells how many times v has appeared.
-> After the pass, an index v with arr[v] / n >= 2 means that the value v appeared at least twice, so it is a duplicate.
-> Collect such indexes by going from 0 to n - 1, which gives increasing order and prints each duplicate only once.
-> The input array is changed, but no extra array is created. The largest stored number is (n - 1) + n * n, which fits in an int for n up to 40000.
-> Let N be the size of the array. We make two passes, so the time is N.
-> Apart from the answer list, only a few variables are used, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int value = arr[i] % n;
        arr[value] = arr[value] + n;
    }

    vector<int> duplicates;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] / n >= 2)
        {
            duplicates.push_back(i);
        }
    }

    return duplicates;
}

int main()
{
    vector<int> arr = {1, 6, 3, 1, 3, 6, 6};

    vector<int> answer = findDuplicates(arr);

    if (answer.empty())
    {
        cout << -1 << "\n";
    }
    else
    {
        for (int x : answer)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
