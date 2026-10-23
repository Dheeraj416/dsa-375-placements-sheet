/*
QUESTION:-

You are given an array of K linked lists, where every list is sorted in
ascending order. Merge all the linked lists into one sorted linked list and
return its head.

Constraints:
0 <= K <= 10000
0 <= length of each list <= 500
-10000 <= Node.val <= 10000

Example 1:

Input:
lists = [[1,4,5],[1,3,4],[2,6]]

Output:
[1,1,2,3,4,4,5,6]

Example 2:

Input:
lists = []

Output:
[]
*/

/*
APPROACH:-

-> Use a min heap that holds the current head node of every list. The smallest of these heads is always the next node of the merged list.
-> Push the head of every non-empty list into the heap. The heap compares the nodes by their value.
-> Repeat: take the smallest node out of the heap and attach it to the tail of the merged list.
-> If that node has a next node, push the next node into the heap.
-> The heap holds at most one node of every list, so its size is at most K, and each push or pop costs log K.
-> Let N be the total number of nodes. Every node is pushed and popped once, so the time is N * log K.
-> The existing nodes are reused, so the extra space is only the heap with K nodes.
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

struct CompareNodes
{
    bool operator()(ListNode *first, ListNode *second)
    {
        return first->val > second->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, CompareNodes> minHeap;

    for (int i = 0; i < (int)lists.size(); i++)
    {
        if (lists[i] != nullptr)
        {
            minHeap.push(lists[i]);
        }
    }

    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    while (!minHeap.empty())
    {
        ListNode *smallest = minHeap.top();
        minHeap.pop();

        tail->next = smallest;
        tail = smallest;

        if (smallest->next != nullptr)
        {
            minHeap.push(smallest->next);
        }
    }

    ListNode *head = dummy->next;
    delete dummy;
    return head;
}

int main()
{
    vector<int> firstValues = {1, 4, 5};
    vector<int> secondValues = {1, 3, 4};
    vector<int> thirdValues = {2, 6};

    vector<ListNode *> lists;
    lists.push_back(buildList(firstValues));
    lists.push_back(buildList(secondValues));
    lists.push_back(buildList(thirdValues));

    ListNode *merged = mergeKLists(lists);

    printList(merged);

    return 0;
}

/*
TIME COMPLEXITY = O(N * log K)
SPACE COMPLEXITY = O(K)
*/
