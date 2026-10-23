/*
QUESTION:-

Given an array of integers and a number sum, count the triplets (three elements
at different indexes i < j < k) whose sum is strictly smaller than sum.

Constraints:
3 <= arr.length <= 3000
-100000 <= arr[i] <= 100000
-300000 <= sum <= 300000

Example 1:

Input:
arr = [5,1,3,4,7]
sum = 12

Output:
4
(the triplets are {1,3,4}, {1,3,5}, {1,3,7} and {1,4,5})

Example 2:

Input:
arr = [-2,0,1,3]
sum = 2

Output:
2
(the triplets are {-2,0,1} and {-2,0,3})
*/

/*
APPROACH:-

-> The order of the elements inside a triplet does not matter for the sum, so we can sort the array first.
-> Fix the first element at index i. For the other two elements use two pointers: j = i + 1 and k = n - 1.
-> If arr[i] + arr[j] + arr[k] is smaller than sum, then arr[j] together with every element between j + 1 and k also gives a sum smaller than sum (those elements are not bigger than arr[k]). So add k - j to the answer and move j forward.
-> Otherwise the sum is too big, so move k backward to try a smaller third element.
-> Continue until j and k meet, then go to the next i.
-> Let N be the size of the array. Sorting costs N * log N, and the two pointers run N times for each i, so the time is N * N.
-> Sorting is done in place, so the extra space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> &arr, int sum)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int count = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] < sum)
            {
                count = count + (k - j);
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    return count;
}

int main()
{
    vector<int> arr = {5, 1, 3, 4, 7};
    int sum = 12;

    int answer = countTriplets(arr, sum);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(1)
*/
