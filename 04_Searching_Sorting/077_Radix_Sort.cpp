/*
QUESTION:-

Given an array of non-negative integers, sort it in increasing order using radix
sort.

Constraints:
1 <= arr.length <= 100000
0 <= arr[i] <= 1000000

Example 1:

Input:
arr = [170,45,75,90,802,24,2,66]

Output:
[2,24,45,66,75,90,170,802]

Example 2:

Input:
arr = [9,100,5]

Output:
[5,9,100]
*/

/*
APPROACH:-

-> Radix sort sorts the numbers digit by digit, starting from the least significant digit (the ones place), then the tens place, then the hundreds place, and so on.
-> For each digit place we use a stable counting sort on that digit only. The digit of a number x at place p (1, 10, 100, ...) is (x / p) % 10, so there are only 10 possible digit values.
-> Stable means that numbers with the same digit keep their previous order. This is what makes the earlier (less significant) sorting results survive the later passes.
-> To keep it stable, we fill the output array from right to left using prefix counts of the digits.
-> We repeat the pass for each digit of the largest number. After the last pass the whole array is sorted.
-> Let N be the size of the array and D the number of digits of the largest number. Each pass costs N + 10, so the time is D * (N + 10), which we write as D * N.
-> Each pass uses an output array of size N, so the space is N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

void countingSortByDigit(vector<int> &arr, int place)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    for (int digit = 1; digit < 10; digit++)
    {
        count[digit] = count[digit] + count[digit - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    arr = output;
}

void radixSort(vector<int> &arr)
{
    int maxValue = *max_element(arr.begin(), arr.end());

    for (int place = 1; maxValue / place > 0; place = place * 10)
    {
        countingSortByDigit(arr, place);
    }
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(D * N)
SPACE COMPLEXITY = O(N)
*/
