/*
QUESTION:-

You are given the heads of two sorted linked lists. Merge the two lists into
one sorted list by splicing together the nodes of the two lists. Return the
head of the merged list.

Constraints:
0 <= length of each list <= 50
-100 <= Node.val <= 100
Both lists are sorted in non-decreasing order.

Example 1:

Input:
list1 = [1,2,4], list2 = [1,3,4]

Output:
[1,1,2,3,4,4]

Example 2:

Input:
list1 = [], list2 = [0]

Output:
[0]
*/

/*
APPROACH:-

-> Create a dummy node and keep a tail pointer that always points to the last node of the merged list.
-> Compare the current nodes of both lists and attach the smaller one to the tail.
-> Move forward in the list from which the node was taken, and move the tail forward.
-> When one list becomes empty, attach the remaining part of the other list directly, since it is already sorted.
-> The dummy node removes the special case of an empty merged list at the start.
-> The existing nodes are reused, so no new nodes are created except the dummy.
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

ListNode *mergeTwoLists(ListNode *first, ListNode *second)
{
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

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

    ListNode *mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
}

int main()
{
    vector<int> firstValues = {1, 2, 4};
    vector<int> secondValues = {1, 3, 4};
    ListNode *first = buildList(firstValues);
    ListNode *second = buildList(secondValues);

    ListNode *merged = mergeTwoLists(first, second);

    printList(merged);

    return 0;
}

/*
TIME COMPLEXITY = O(N + M)
SPACE COMPLEXITY = O(1)
*/
