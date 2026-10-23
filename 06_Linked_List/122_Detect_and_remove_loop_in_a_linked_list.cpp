/*
QUESTION:-

Given the head of a singly linked list that may contain a loop, detect the loop
and remove it, so that the list becomes a normal list ending with null. If there
is no loop, leave the list as it is.

Constraints:
1 <= number of nodes <= 10000
0 <= Node.val <= 10000

Example 1:

Input:
head = [1,2,3,4,5], the last node (5) points back to the node with value 3

Output:
[1,2,3,4,5]
(the list after removing the loop)

Example 2:

Input:
head = [1,2,3], the last node (3) points back to the head (1)

Output:
[1,2,3]
*/

/*
APPROACH:-

-> Use Floyd's cycle detection: move slow by one step and fast by two steps. If they ever meet, there is a loop. If fast reaches null, there is no loop and we stop.
-> To find where the loop starts, put slow back at the head and move both slow and fast one step at a time. They meet exactly at the first node of the loop.
-> We need the last node of the loop, because its next pointer must be set to null. So we stop one step before they meet: move while slow->next != fast->next.
-> Special case: if the meeting point is the head itself, the whole list is the loop. Then walk fast until fast->next is the head, and cut there.
-> Finally set fast->next = nullptr, which breaks the loop.
-> Let N be the number of nodes. Each phase takes at most about N steps, so the time is N.
-> Only two pointers are used, so the space is constant.
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

void removeLoop(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }

    if (fast == nullptr || fast->next == nullptr)
    {
        return;
    }

    slow = head;

    if (slow == fast)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = nullptr;
        return;
    }

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = nullptr;
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = buildList(values);

    ListNode *loopStart = head->next->next;
    ListNode *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = loopStart;

    removeLoop(head);

    printList(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
