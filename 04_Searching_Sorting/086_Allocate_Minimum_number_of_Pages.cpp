/*
QUESTION:-

You are given N books where the i-th book has pages[i] pages, and M students.
Allocate all the books to the students so that: every student gets at least one
book, every book goes to exactly one student, and every student gets a
contiguous block of books. Minimize the maximum number of pages given to any
single student and return that value. If it is not possible to allocate the
books (M is greater than N), return -1.

Constraints:
1 <= N <= 100000
1 <= pages[i] <= 10000
1 <= M <= 100000

Example 1:

Input:
pages = [12,34,67,90], M = 2

Output:
113
Explanation: Give [12,34,67] to the first student (113 pages) and [90] to the second.

Example 2:

Input:
pages = [25,46,28,49,24], M = 4

Output:
71
*/

/*
APPROACH:-

-> Binary search on the answer, which is the maximum pages one student can read.
-> The answer is at least the largest single book (low) and at most the total number of pages (high).
-> For a candidate value mid, count how many students are needed if no student may get more than mid pages. Give books to a student greedily until the next book would exceed mid.
-> If the students needed are more than M, mid is too small, so search the right half.
-> Otherwise mid is possible, so try a smaller value by searching the left half.
-> The loop ends with low as the smallest possible maximum.
-> If M is greater than N, there are not enough books to give everyone one, so return -1.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &pages, int maxPages)
{
    int students = 1;
    long long currentPages = 0;

    for (int i = 0; i < (int)pages.size(); i++)
    {
        if (currentPages + pages[i] <= maxPages)
        {
            currentPages += pages[i];
        }
        else
        {
            students++;
            currentPages = pages[i];
        }
    }

    return students;
}

int allocatePages(vector<int> &pages, int students)
{
    if (students > (int)pages.size())
    {
        return -1;
    }

    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (countStudents(pages, mid) > students)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
    vector<int> pages = {12, 34, 67, 90};
    int students = 2;

    int answer = allocatePages(pages, students);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * log(SUM))
SPACE COMPLEXITY = O(1)
*/
