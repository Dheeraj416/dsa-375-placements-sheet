/*
QUESTION:-

Given a boolean matrix (every cell is 0 or 1), print its unique rows. If a row
appears more than once, print it only the first time it appears, and keep the
rows in their original order.

Constraints:
1 <= rows, columns <= 100
matrix[i][j] is 0 or 1

Example 1:

Input:
matrix =
1 1 0 1
1 0 0 1
1 1 0 1

Output:
1 1 0 1
1 0 0 1

Example 2:

Input:
matrix =
0 0
0 0
1 1

Output:
0 0
1 1
*/

/*
APPROACH:-

-> Treat every row as a word made of the letters 0 and 1, and store the rows in a trie where every node has two children (for 0 and for 1).
-> For each row, walk down the trie from the root, one cell at a time. If the child for the current bit does not exist, create it and remember that this row created something new.
-> All rows have the same length, so two rows are equal only if the whole path already existed. Therefore a row is new if and only if at least one new node was created while inserting it.
-> If the row is new, add it to the answer. If not, skip it.
-> Let R be the number of rows and C the number of columns. Every row is walked once, one step for every cell, so the time is R * C.
-> In the worst case all rows are different and the trie has R * C nodes, so the space is R * C.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[2];

    TrieNode()
    {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

vector<vector<int>> uniqueRows(vector<vector<int>> &matrix)
{
    TrieNode *root = new TrieNode();
    vector<vector<int>> answer;

    for (int r = 0; r < (int)matrix.size(); r++)
    {
        TrieNode *node = root;
        bool isNewRow = false;

        for (int c = 0; c < (int)matrix[r].size(); c++)
        {
            int bit = matrix[r][c];

            if (node->child[bit] == nullptr)
            {
                node->child[bit] = new TrieNode();
                isNewRow = true;
            }

            node = node->child[bit];
        }

        if (isNewRow)
        {
            answer.push_back(matrix[r]);
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 0, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}};

    vector<vector<int>> answer = uniqueRows(matrix);

    for (int r = 0; r < (int)answer.size(); r++)
    {
        for (int c = 0; c < (int)answer[r].size(); c++)
        {
            cout << answer[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O(R * C)
SPACE COMPLEXITY = O(R * C)
*/
