/*
QUESTION:-

A bitonic doubly linked list first increases and then decreases (either part
may be empty). Given the head of such a list, sort it in increasing order and
return the new head.

Constraints:
1 <= number of nodes <= 100000
-100000 <= Node.val <= 100000

Example 1:

Input:
head = [2,5,7,12,10,6,4,1]

Output:
[1,2,4,5,6,7,10,12]

Example 2:

Input:
head = [1,3,5]

Output:
[1,3,5]
*/

/*
APPROACH:-

-> A bitonic list is really two sorted lists: an increasing part followed by a decreasing part.
-> Find the peak: move forward while the current value is smaller than the next value. The peak is the last node of the increasing part.
-> Cut the list after the peak. The rest is a decreasing list, so reverse it (using the next pointers only) and it becomes increasing.
-> Merge the two increasing lists using the next pointers, in the same way as merging two sorted linked lists.
-> The merge does not maintain the prev pointers, so walk through the merged list once at the end and set every prev pointer correctly.
-> Let N be the number of nodes. Finding the peak, reversing, merging and fixing the prev pointers each cost at most N, so the time is N.
-> Only links are changed, so the space is constant.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct DNode
{
    int val;
    DNode *prev;
    DNode *next;

    DNode(int x)
    {
        val = x;
        prev = nullptr;
        next = nullptr;
    }
};

DNode *buildDoubly(vector<int> &values)
{
    DNode *head = nullptr;
    DNode *tail = nullptr;

    for (int i = 0; i < (int)values.size(); i++)
    {
        DNode *node = new DNode(values[i]);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    return head;
}

void printDoubly(DNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

DNode *reverseByNext(DNode *head)
{
    DNode *previous = nullptr;
    DNode *current = head;

    while (current != nullptr)
    {
        DNode *nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    return previous;
}

DNode *mergeSorted(DNode *first, DNode *second)
{
    DNode *dummy = new DNode(0);
    DNode *tail = dummy;

    while (first != nullptr && second != nullptr)
    {
        if (first->val <= second->val)
        {
            tail->next = first;
            first = first->next;
        }
        else
        {
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }

    if (first != nullptr)
    {
        tail->next = first;
    }
    else
    {
        tail->next = second;
    }

    DNode *result = dummy->next;
    delete dummy;
    return result;
}

DNode *sortBitonic(DNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    DNode *peak = head;
    while (peak->next != nullptr && peak->val < peak->next->val)
    {
        peak = peak->next;
    }

    DNode *second = peak->next;
    peak->next = nullptr;
    second = reverseByNext(second);

    DNode *merged = mergeSorted(head, second);

    DNode *previous = nullptr;
    DNode *current = merged;
    while (current != nullptr)
    {
        current->prev = previous;
        previous = current;
        current = current->next;
    }

    return merged;
}

int main()
{
    vector<int> values = {2, 5, 7, 12, 10, 6, 4, 1};
    DNode *head = buildDoubly(values);

    head = sortBitonic(head);

    printDoubly(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
