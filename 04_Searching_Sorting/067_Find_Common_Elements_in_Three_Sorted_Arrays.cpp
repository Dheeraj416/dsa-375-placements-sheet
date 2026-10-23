/*
QUESTION:-

Given three arrays sorted in increasing order, find all the elements that are
present in all three arrays. Print each common element once, in increasing
order. If there is no common element, print -1.

Constraints:
1 <= size of each array <= 100000
-1000000000 <= value <= 1000000000

Example 1:

Input:
a = [1,5,10,20,40,80]
b = [6,7,20,80,100]
c = [3,4,15,20,30,70,80,120]

Output:
20 80

Example 2:

Input:
a = [1,2,3]
b = [4,5]
c = [6]

Output:
-1
*/

/*
APPROACH:-

-> All three arrays are sorted, so we can walk through them together with three pointers i, j and k, one per array.
-> If the three current elements are equal, it is a common element. Add it to the answer (only if it is different from the last one added, so duplicates are not printed twice) and move all three pointers forward.
-> Otherwise the smallest of the three current elements cannot be common to all (the other arrays have bigger values at this point and only increase), so move the pointer of the smallest element forward.
-> Stop when any pointer reaches the end of its array, because no more common elements are possible.
-> If the answer is empty, print -1.
-> Let N1, N2 and N3 be the sizes of the arrays. Each step moves at least one pointer forward, so the time is N1 + N2 + N3.
-> Only the answer list and a few pointers are used, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> commonInThreeSortedArrays(vector<int> &a, vector<int> &b, vector<int> &c)
{
    vector<int> common;
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < (int)a.size() && j < (int)b.size() && k < (int)c.size())
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            if (common.empty() || common.back() != a[i])
            {
                common.push_back(a[i]);
            }
            i++;
            j++;
            k++;
        }
        else if (a[i] <= b[j] && a[i] <= c[k])
        {
            i++;
        }
        else if (b[j] <= a[i] && b[j] <= c[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }

    return common;
}

int main()
{
    vector<int> a = {1, 5, 10, 20, 40, 80};
    vector<int> b = {6, 7, 20, 80, 100};
    vector<int> c = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> answer = commonInThreeSortedArrays(a, b, c);

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
TIME COMPLEXITY = O(N1 + N2 + N3)
SPACE COMPLEXITY = O(1)
*/
