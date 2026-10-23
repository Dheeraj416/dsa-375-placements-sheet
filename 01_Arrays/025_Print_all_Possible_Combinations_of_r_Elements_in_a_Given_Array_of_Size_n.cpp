/*
QUESTION:-

Given an array of n distinct elements and a number r, print all the possible
combinations of r elements of the array. The elements of a combination keep the
same order as in the array, and the combinations are printed in lexicographic
order of the positions.

Constraints:
1 <= r <= n <= 20
-1000 <= arr[i] <= 1000

Example 1:

Input:
arr = [1,2,3,4]
r = 2

Output:
1 2
1 3
1 4
2 3
2 4
3 4

Example 2:

Input:
arr = [1,2,3]
r = 3

Output:
1 2 3
*/

/*
APPROACH:-

-> We build every combination one element at a time with recursion (backtracking). The recursive function knows the position to start from and the combination built so far.
-> If the combination already has r elements, print it and return.
-> Otherwise, try every element from the start position to the end: add it to the combination, call the function for the next position, then remove it again (backtrack) to try the next element.
-> Starting the next call from position i + 1 makes sure that elements keep their array order and that no element is used twice, so no combination repeats.
-> Pruning: if the elements left are fewer than the elements still needed, we stop early.
-> Let N be the array size and R the combination size. There are about C(N, R) combinations and printing one costs R, so the time is C(N, R) * R.
-> The current combination holds R elements and the recursion is R levels deep, so the space is R.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void generate(int start, int r, vector<int> &arr, vector<int> &current)
{
    if ((int)current.size() == r)
    {
        for (int x : current)
        {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }

    int n = arr.size();
    int stillNeeded = r - current.size();

    for (int i = start; i + stillNeeded <= n; i++)
    {
        current.push_back(arr[i]);
        generate(i + 1, r, arr, current);
        current.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int r = 2;

    vector<int> current;
    generate(0, r, arr, current);

    return 0;
}

/*
TIME COMPLEXITY = O(C(N, R) * R)
SPACE COMPLEXITY = O(R)
*/
