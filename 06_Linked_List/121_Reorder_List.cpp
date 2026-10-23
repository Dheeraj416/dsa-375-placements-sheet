/*
QUESTION:-

You are given the head of a singly linked list L0 -> L1 -> ... -> Ln-1 -> Ln.
Reorder it in place to the form L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
You may not change the values inside the nodes, only the links between them.

Constraints:
1 <= number of nodes <= 50000
1 <= Node.val <= 1000

Example 1:

Input:
head = [1,2,3,4,5]

Output:
[1,5,2,4,3]

Example 2:

Input:
head = [1,2,3,4]

Output:
[1,4,2,3]
*/

/*
APPROACH:-

-> Step 1: find the middle of the list with a slow pointer and a fast pointer. When fast cannot move two steps further, slow is at the end of the first half.
-> Step 2: cut the list after slow, and reverse the second half. Now the second half starts from the last node.
-> Step 3: merge the two halves by taking one node from the first half and then one node from the reversed second half, again and again.
-> The first half is never shorter than the second half, so after the second half ends the remaining node of the first half is already in the right place.
-> Let N be the number of nodes. Finding the middle, reversing and merging each cost at most N, so the time is N.
-> Only the links are changed, so the space is constant.
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

void reorderList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *second = reverseList(slow->next);
    slow->next = nullptr;
    ListNode *first = head;

    while (second != nullptr)
    {
        ListNode *firstNext = first->next;
        ListNode *secondNext = second->next;
        first->next = second;
        second->next = firstNext;
        first = firstNext;
        second = secondNext;
    }
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = buildList(values);

    reorderList(head);

    printList(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
