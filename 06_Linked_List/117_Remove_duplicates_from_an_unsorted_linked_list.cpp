/*
QUESTION:-

Given the head of an unsorted singly linked list, remove all the duplicate
values from it. The first occurrence of every value stays and the later
occurrences are removed. Return the head of the list.

Constraints:
0 <= number of nodes <= 100000
-100000 <= Node.val <= 100000

Example 1:

Input:
head = [1,2,3,2,4,3,5]

Output:
[1,2,3,4,5]

Example 2:

Input:
head = [2,2,2,2]

Output:
[2]
*/

/*
APPROACH:-

-> Keep a hash set called seen that stores all the values we have already met.
-> Walk through the list with two pointers: previous (the last node we kept) and current.
-> If current->val is already in seen, it is a duplicate. Skip it by setting previous->next = current->next.
-> Otherwise, insert current->val into seen and move previous to current.
-> The head is never removed because the first node is always the first occurrence of its value.
-> Let N be the number of nodes. Every node is visited once and the set operations take constant time on average, so the time is N.
-> The set can hold up to N values, so the space is N.
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

ListNode *removeDuplicates(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }

    unordered_set<int> seen;
    seen.insert(head->val);
    ListNode *previous = head;
    ListNode *current = head->next;

    while (current != nullptr)
    {
        if (seen.count(current->val) > 0)
        {
            previous->next = current->next;
            delete current;
        }
        else
        {
            seen.insert(current->val);
            previous = current;
        }
        current = previous->next;
    }

    return head;
}

int main()
{
    vector<int> values = {1, 2, 3, 2, 4, 3, 5};
    ListNode *head = buildList(values);

    head = removeDuplicates(head);

    printList(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(N)
*/
