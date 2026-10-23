/*
QUESTION:-

Given two sorted arrays first (size n) and second (size m), merge them without
using any extra array. After merging, first must contain the smallest n
elements and second must contain the remaining m elements, and both arrays must
be in sorted order.

Constraints:
1 <= n, m <= 100000

Example 1:

Input:
first = [1,4,8,10], second = [2,3,9]

Output:
first = [1,2,3,4], second = [8,9,10]

Example 2:

Input:
first = [1,3,5,7], second = [0,2,6,8,9]

Output:
first = [0,1,2,3], second = [5,6,7,8,9]
*/

/*
APPROACH:-

-> Use the gap method (the idea behind Shell sort). Treat both arrays as one array of length n + m.
-> Start with gap = ceil((n + m) / 2).
-> Compare the elements that are gap positions apart and swap them if they are out of order.
-> Because the two arrays are separate, each comparison has three cases: both in first, one in each, or both in second.
-> After each pass, reduce the gap to ceil(gap / 2). Stop after a pass with gap = 1.
-> When the gap becomes 1 the whole combined array is sorted, so first holds the smallest values and second the largest.
-> No new array is created, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap)
{
    if (gap <= 1)
    {
        return 0;
    }

    return (gap / 2) + (gap % 2);
}

void mergeWithoutExtraSpace(vector<int> &first, vector<int> &second)
{
    int n = (int)first.size();
    int m = (int)second.size();
    int gap = nextGap(n + m);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while (right < n + m)
        {
            if (left < n && right < n)
            {
                if (first[left] > first[right])
                {
                    swap(first[left], first[right]);
                }
            }
            else if (left < n && right >= n)
            {
                if (first[left] > second[right - n])
                {
                    swap(first[left], second[right - n]);
                }
            }
            else
            {
                if (second[left - n] > second[right - n])
                {
                    swap(second[left - n], second[right - n]);
                }
            }

            left++;
            right++;
        }

        gap = nextGap(gap);
    }
}

int main()
{
    vector<int> first = {1, 4, 8, 10};
    vector<int> second = {2, 3, 9};

    mergeWithoutExtraSpace(first, second);

    for (int x : first)
    {
        cout << x << " ";
    }
    cout << "\n";

    for (int x : second)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O((N + M) * log(N + M))
SPACE COMPLEXITY = O(1)
*/
