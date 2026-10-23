/*
QUESTION:-

Given a singly linked list, rearrange its values so that they follow a zig-zag
pattern: a < b > c < d > e < f ... where a, b, c, ... are the values of the
consecutive nodes. Any valid zig-zag arrangement reached by the usual swaps is
accepted; here we use the single pass swapping method and print its result.

Constraints:
1 <= number of nodes <= 100000
1 <= Node.val <= 100000

Example 1:

Input:
head = [11,15,20,5,10]

Output:
[11,20,5,15,10]

Example 2:

Input:
head = [4,3,7,8,6,2,1]

Output:
[3,7,4,8,2,6,1]
*/

/*
APPROACH:-

-> In a zig-zag list the relation between neighbours alternates: the first pair must be "<", the second pair ">", the third pair "<", and so on.
-> Keep a flag expectSmaller, which is true at the start.
-> Walk through the list. For the pair (current, current->next): if expectSmaller is true and current->val > next->val, swap the two values. If expectSmaller is false and current->val < next->val, swap the two values.
-> After each pair, flip the flag and move to the next node.
-> Swapping never breaks the earlier pair. For example if a < b was already true and we swap b and c because b < c is wrong, then c is smaller than b, so a < c still holds.
-> Let N be the number of nodes. We visit every node once, so the time is N.
-> Only the flag and a pointer are used, so the space is constant.
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

void zigZag(ListNode *head)
{
    bool expectSmaller = true;
    ListNode *current = head;

    while (current != nullptr && current->next != nullptr)
    {
        if (expectSmaller)
        {
            if (current->val > current->next->val)
            {
                swap(current->val, current->next->val);
            }
        }
        else
        {
            if (current->val < current->next->val)
            {
                swap(current->val, current->next->val);
            }
        }

        expectSmaller = !expectSmaller;
        current = current->next;
    }
}

int main()
{
    vector<int> values = {11, 15, 20, 5, 10};
    ListNode *head = buildList(values);

    zigZag(head);

    printList(head);

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
