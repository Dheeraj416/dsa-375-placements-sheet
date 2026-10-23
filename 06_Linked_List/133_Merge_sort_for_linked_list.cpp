/*
QUESTION:-

Given the head of a singly linked list, sort it in increasing order using merge
sort and return the head of the sorted list.

Constraints:
0 <= number of nodes <= 50000
-100000 <= Node.val <= 100000

Example 1:

Input:
head = [4,2,1,3]

Output:
[1,2,3,4]

Example 2:

Input:
head = [-1,5,3,4,0]

Output:
[-1,0,3,4,5]
*/

/*
APPROACH:-

-> Merge sort is a good choice for linked lists, because merging two sorted lists needs no extra array and the list can be split easily.
-> If the list is empty or has one node, it is already sorted. Return it.
-> Find the middle with a slow and a fast pointer (fast starts one step ahead, so for two nodes the first node is the middle).
-> Cut the list after the middle. Now we have a left half and a right half.
-> Sort both halves recursively, then merge the two sorted halves with a dummy node and a tail pointer, always taking the smaller front value.
-> Let N be the number of nodes. The list is halved log N times and every level of recursion does N work for merging, so the time is N * log N.
-> The recursion goes log N levels deep, so the space is log N.
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

ListNode *mergeTwo(ListNode *first, ListNode *second)
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

    ListNode *result = dummy->next;
    delete dummy;
    return result;
}

ListNode *mergeSort(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *second = slow->next;
    slow->next = nullptr;

    ListNode *left = mergeSort(head);
    ListNode *right = mergeSort(second);

    return mergeTwo(left, right);
}

int main()
{
    vector<int> values = {4, 2, 1, 3};
    ListNode *head = buildList(values);

    head = mergeSort(head);

    printList(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N * log N)
SPACE COMPLEXITY = O(log N)
*/
