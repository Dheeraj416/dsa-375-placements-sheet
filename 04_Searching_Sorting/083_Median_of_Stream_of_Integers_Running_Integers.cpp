/*
QUESTION:-

The median is the middle value of an ordered list of numbers. If the list has
an even size, the median is the average of the two middle values. Design a data
structure MedianFinder that supports addNum(num), which adds an integer from
the data stream, and findMedian(), which returns the median of all the numbers
added so far.

Constraints:
-100000 <= num <= 100000
findMedian is called only after at least one number has been added.

Example 1:

Input:
addNum(1), addNum(2), findMedian(), addNum(3), findMedian()

Output:
1.5 2.0

Example 2:

Input:
addNum(5), findMedian()

Output:
5.0
*/

/*
APPROACH:-

-> Split the numbers seen so far into two halves: the smaller half in a max heap (lowerHalf) and the larger half in a min heap (upperHalf).
-> The top of the max heap is the largest of the small numbers and the top of the min heap is the smallest of the large numbers, so the median is always at these two tops.
-> To add a number: push it into lowerHalf, then move the largest element of lowerHalf to upperHalf. This keeps every element of lowerHalf not larger than every element of upperHalf.
-> If upperHalf now has more elements than lowerHalf, move its smallest element back to lowerHalf. This keeps lowerHalf equal in size to upperHalf or larger by one.
-> To find the median: if lowerHalf has more elements, its top is the median. Otherwise the median is the average of the two tops.
-> Adding takes O(log N) and finding the median takes O(1). All the numbers are stored, so the space is O(N).
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
private:
    priority_queue<int> lowerHalf;
    priority_queue<int, vector<int>, greater<int>> upperHalf;

public:
    void addNum(int number)
    {
        lowerHalf.push(number);

        upperHalf.push(lowerHalf.top());
        lowerHalf.pop();

        if (upperHalf.size() > lowerHalf.size())
        {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }

    double findMedian()
    {
        if (lowerHalf.size() > upperHalf.size())
        {
            return lowerHalf.top();
        }

        return (lowerHalf.top() + upperHalf.top()) / 2.0;
    }
};

int main()
{
    MedianFinder finder;

    finder.addNum(1);
    finder.addNum(2);

    cout << fixed << setprecision(1) << finder.findMedian() << "\n";

    finder.addNum(3);

    cout << fixed << setprecision(1) << finder.findMedian() << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(log N)
SPACE COMPLEXITY = O(N)
*/
