/*
QUESTION:-

A linked list of length n is given where every node has an extra random pointer
that can point to any node in the list or to null. Create a deep copy of the
list. The copy must contain exactly n brand new nodes, and the next and random
pointers of the new nodes must point to new nodes only, never to the original
nodes. Each input node is written as [value, random_index], where random_index
is the index of the node the random pointer points to, or null.

Constraints:
0 <= n <= 1000
-10000 <= Node.val <= 10000

Example 1:

Input:
head = [[7,null],[13,0],[11,4],[10,2],[1,0]]

Output:
[[7,null],[13,0],[11,4],[10,2],[1,0]] (printed below as value:random value)

Example 2:

Input:
head = [[1,1],[2,1]]

Output:
[[1,1],[2,1]]
*/

/*
APPROACH:-

-> Step 1: after every original node insert its copy, so the list becomes A -> A' -> B -> B' -> C -> C'.
-> Step 2: set the random pointers of the copies. For an original node X with a random pointer, the copy's random is X->random->next, which is the copy of that random node.
-> Step 3: separate the two lists. Restore the original next pointers and link the copies together.
-> The interleaving trick gives every original node a direct link to its copy without a hash map.
-> Handle a null random pointer and the last node carefully while separating the lists.
-> The original list is restored to its initial state at the end.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct RandomNode
{
    int val;
    RandomNode *next;
    RandomNode *random;

    RandomNode(int x)
    {
        val = x;
        next = nullptr;
        random = nullptr;
    }
};

RandomNode *copyRandomList(RandomNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    RandomNode *current = head;

    while (current != nullptr)
    {
        RandomNode *copy = new RandomNode(current->val);
        copy->next = current->next;
        current->next = copy;
        current = copy->next;
    }

    current = head;

    while (current != nullptr)
    {
        if (current->random != nullptr)
        {
            current->next->random = current->random->next;
        }

        current = current->next->next;
    }

    RandomNode *copyHead = head->next;
    current = head;

    while (current != nullptr)
    {
        RandomNode *copy = current->next;
        current->next = copy->next;

        if (copy->next != nullptr)
        {
            copy->next = copy->next->next;
        }

        current = current->next;
    }

    return copyHead;
}

int main()
{
    vector<int> values = {7, 13, 11, 10, 1};
    vector<int> randomIndex = {-1, 0, 4, 2, 0};

    vector<RandomNode *> nodes;
    for (int i = 0; i < (int)values.size(); i++)
    {
        nodes.push_back(new RandomNode(values[i]));
    }

    for (int i = 0; i < (int)nodes.size(); i++)
    {
        if (i + 1 < (int)nodes.size())
        {
            nodes[i]->next = nodes[i + 1];
        }

        if (randomIndex[i] != -1)
        {
            nodes[i]->random = nodes[randomIndex[i]];
        }
    }

    RandomNode *copyHead = copyRandomList(nodes[0]);

    RandomNode *current = copyHead;
    while (current != nullptr)
    {
        cout << current->val << ":";

        if (current->random != nullptr)
        {
            cout << current->random->val;
        }
        else
        {
            cout << "null";
        }

        cout << " ";
        current = current->next;
    }
    cout << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N)
SPACE COMPLEXITY = O(1)
*/
