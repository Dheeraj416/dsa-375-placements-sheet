/*
QUESTION:-

Given the head of a singly linked list, sort it in increasing order using
quicksort and return the head of the sorted list.

Constraints:
0 <= number of nodes <= 10000
-100000 <= Node.val <= 100000

Example 1:

Input:
head = [30,3,4,20,5]

Output:
[3,4,5,20,30]

Example 2:

Input:
head = [5,1,5,2,5]

Output:
[1,2,5,5,5]
*/

/*
APPROACH:-

-> Take the value of the first node as the pivot.
-> Go through the list and move every node into one of three lists: nodes smaller than the pivot, nodes equal to the pivot, and nodes greater than the pivot. Using a separate list for equal values handles duplicates easily.
-> Sort the smaller list and the greater list recursively. The equal list needs no sorting.
-> Join the three lists in this order: sorted smaller list, equal list, sorted greater list.
-> Let N be the number of nodes. On average the pivot splits the list well, which gives log N levels of work N each. In the worst case (for example an already sorted list) the split is very uneven, so the time is N * N in the worst case.
-> The worst recursion depth is N, so the space is N in the worst case (log N on average).
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *buildList(vector<int> &values)
{
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    for (int i = 0; i < (int)values.size(); i++)
    {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }

    ListNode *head = dummy->next;
    delete dummy;
    return head;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

ListNode *quickSort(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    int pivot = head->val;

    ListNode *lessDummy = new ListNode(0);
    ListNode *equalDummy = new ListNode(0);
    ListNode *greaterDummy = new ListNode(0);
    ListNode *lessTail = lessDummy;
    ListNode *equalTail = equalDummy;
    ListNode *greaterTail = greaterDummy;

    ListNode *current = head;
    while (current != nullptr)
    {
        ListNode *nextNode = current->next;
        current->next = nullptr;

        if (current->val < pivot)
        {
            lessTail->next = current;
            lessTail = current;
        }
        else if (current->val == pivot)
        {
            equalTail->next = current;
            equalTail = current;
        }
        else
        {
            greaterTail->next = current;
            greaterTail = current;
        }

        current = nextNode;
    }

    ListNode *left = quickSort(lessDummy->next);
    ListNode *middle = equalDummy->next;
    ListNode *right = quickSort(greaterDummy->next);

    equalTail->next = right;

    delete lessDummy;
    delete equalDummy;
    delete greaterDummy;

    if (left == nullptr)
    {
        return middle;
    }

    ListNode *leftTail = left;
    while (leftTail->next != nullptr)
    {
        leftTail = leftTail->next;
    }
    leftTail->next = middle;

    return left;
}

int main()
{
    vector<int> values = {30, 3, 4, 20, 5};
    ListNode *head = buildList(values);

    head = quickSort(head);

    printList(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N * N)
SPACE COMPLEXITY = O(N)
*/
