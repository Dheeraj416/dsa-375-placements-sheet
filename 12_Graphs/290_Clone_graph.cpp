/*
QUESTION:-

You are given a reference to one node of a connected undirected graph. Return a
deep copy (clone) of the whole graph. Every node has an integer value and a list
of its neighbors. The clone must contain brand new node objects with the same
values and the same neighbor structure.

Constraints:
0 <= number of nodes <= 100
1 <= Node.val <= 100 (every value is unique)
There are no repeated edges and no self loops.

Example 1:

Input:
adjList = [[2,4],[1,3],[2,4],[1,3]]
(node 1 is connected to 2 and 4, node 2 to 1 and 3, node 3 to 2 and 4, node 4 to 1 and 3)

Output:
[[2,4],[1,3],[2,4],[1,3]]
(a new graph with the same structure, made only of new nodes)

Example 2:

Input:
adjList = [[]]
(one node with value 1 and no neighbors)

Output:
[[]]
*/

/*
APPROACH:-

-> A graph can contain cycles, so we must remember which original nodes were already copied. Use a hash map from original node to its copy.
-> Start from the given node: create its copy, store it in the map, then visit every neighbor with DFS (recursion).
-> For every neighbor, if it is not in the map yet, clone it first (recursive call). Then add the neighbor's copy to the neighbor list of the current copy.
-> If a neighbor is already in the map, we simply reuse its copy. This stops infinite loops on cycles and guarantees every node is copied exactly once.
-> Edge case: if the given node is null (empty graph), return null.
-> Let V be the number of nodes and E the number of edges. Every node is copied once and every edge is looked at twice, so the time is V + E.
-> The map holds V nodes and the recursion can go V levels deep, so the extra space is V.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    vector<Node *> neighbors;

    Node(int value)
    {
        val = value;
    }
};

Node *cloneDfs(Node *current, unordered_map<Node *, Node *> &copies)
{
    Node *copy = new Node(current->val);
    copies[current] = copy;

    for (Node *neighbor : current->neighbors)
    {
        if (copies.find(neighbor) == copies.end())
        {
            cloneDfs(neighbor, copies);
        }
        copy->neighbors.push_back(copies[neighbor]);
    }

    return copy;
}

Node *cloneGraph(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    unordered_map<Node *, Node *> copies;
    return cloneDfs(node, copies);
}

void printGraph(Node *start)
{
    if (start == nullptr)
    {
        cout << "[]\n";
        return;
    }

    queue<Node *> toVisit;
    set<Node *> seen;

    toVisit.push(start);
    seen.insert(start);

    while (!toVisit.empty())
    {
        Node *current = toVisit.front();
        toVisit.pop();

        cout << current->val << ":";
        for (Node *neighbor : current->neighbors)
        {
            cout << " " << neighbor->val;
            if (seen.find(neighbor) == seen.end())
            {
                seen.insert(neighbor);
                toVisit.push(neighbor);
            }
        }
        cout << "\n";
    }
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Node *cloned = cloneGraph(node1);

    printGraph(cloned);
    cout << "Clone is a different object: " << (cloned != node1) << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(V + E)
SPACE COMPLEXITY = O(V)
*/
