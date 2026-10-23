/*
QUESTION:-

Given the head of a singly linked list, delete every node that has a node with
a strictly greater value somewhere on its right side. Return the head of the
changed list.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 100000

Example 1:

Input:
head = [12,15,10,11,5,6,2,3]

Output:
[15,11,6,3]

Example 2:

Input:
head = [10,20,30,40,50,60]

Output:
[60]
*/

/*
APPROACH:-

-> A node survives only if no greater value exists on its right. Looking from the right side makes this easy, so first reverse the list.
-> In the reversed list, keep the maximum value seen so far. The first node (the old last node) always stays.
-> For every next node: if its value is smaller than the maximum, it had a greater node on its right in the original list, so delete it. Otherwise keep it and update the maximum.
-> Equal values are kept, because the rule asks for a strictly greater value.
-> Reverse the list again to restore the original order.
-> Let N be the number of nodes. Two reversals and one scan cost 3 * N, so the time is N.
-> No extra memory is used, so the space is constant.
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

ListNode *reverseList(ListNode *head)
{
    ListNode *previous = nullptr;
    ListNode *current = head;

    while (current != nullptr)
    {
        ListNode *nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    return previous;
}

ListNode *deleteSmaller(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }

    head = reverseList(head);

    ListNode *current = head;
    int maxValue = current->val;

    while (current->next != nullptr)
    {
        if (current->next->val < maxValue)
        {
            ListNode *toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
        }
        else
        {
            current = current->next;
            maxValue = current->val;
        }
    }

    return reverseList(head);
}

int main()
{
    vector<int> values = {12, 15, 10, 11, 5, 6, 2, 3};
    ListNode *head = buildList(values);

    head = deleteSmaller(head);

    printList(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
