/*
QUESTION:-

A surpasser of an element of an array is an element on its right side that is
strictly greater than it. Given an array, find the number of surpassers of every
element.

Constraints:
1 <= n <= 100000
1 <= arr[i] <= 1000000000

Example 1:

Input:
arr = [2,7,5,3,0,8,1]

Output:
4 1 1 1 2 0 0

Example 2:

Input:
arr = [4,5,1,2,3]

Output:
1 0 2 1 0
*/

/*
APPROACH:-

-> Go through the array from right to left. When we are at index i, all the elements to its right have already been seen. We need to know how many of them are greater than arr[i].
-> Use a Fenwick tree (binary indexed tree) over the ranks of the values. First sort the distinct values and give each value a rank from 1 upwards, so that large values do not make the tree huge.
-> The tree can tell, in log time, how many of the seen values have a rank less than or equal to a given rank. So the number of seen values that are not greater than arr[i] is query(rank of arr[i]).
-> The number of seen values is n - 1 - i, so the surpasser count of arr[i] = (n - 1 - i) - query(rank). Then add arr[i] to the tree with update(rank).
-> Let N be the size of the array. Sorting costs N * log N and every query and update costs log N, so the time is N * log N.
-> The tree and the sorted values take N space.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &tree, int index)
{
    while (index < (int)tree.size())
    {
        tree[index]++;
        index += index & (-index);
    }
}

int query(vector<int> &tree, int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}

vector<int> surpasserCount(vector<int> &arr)
{
    int n = arr.size();

    vector<int> sortedValues = arr;
    sort(sortedValues.begin(), sortedValues.end());
    sortedValues.erase(unique(sortedValues.begin(), sortedValues.end()), sortedValues.end());

    vector<int> tree(sortedValues.size() + 1, 0);
    vector<int> result(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        int rank = lower_bound(sortedValues.begin(), sortedValues.end(), arr[i]) - sortedValues.begin() + 1;

        result[i] = (n - 1 - i) - query(tree, rank);
        update(tree, rank);
    }

    return result;
}

int main()
{
    vector<int> arr = {2, 7, 5, 3, 0, 8, 1};

    vector<int> answer = surpasserCount(arr);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(N)
*/
