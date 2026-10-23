/*
QUESTION:-

Given the head of a linked list, determine whether the list contains a cycle. A
cycle exists if some node can be reached again by continuously following the
next pointer.

Constraints:
0 <= number of nodes <= 10000
-100000 <= Node.val <= 100000

Example 1:

Input:
head = [3,2,0,-4], the tail connects to the node at index 1

Output:
true

Example 2:

Input:
head = [1,2], the tail does not connect to any node

Output:
false
*/

/*
APPROACH:-

-> Use Floyd's cycle detection algorithm with a slow and a fast pointer.
-> Slow moves one node at a time and fast moves two nodes at a time.
-> If the list has no cycle, fast reaches the end (null), so we return false.
-> If the list has a cycle, both pointers enter it, and since fast gains one step on slow each round, they must meet.
-> If slow and fast ever point to the same node, return true.
-> This needs only two pointers instead of a hash set of visited nodes.
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

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> values = {3, 2, 0, -4};
    ListNode *head = buildList(values);

    ListNode *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = head->next;

    bool answer = hasCycle(head);

    if (answer)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
