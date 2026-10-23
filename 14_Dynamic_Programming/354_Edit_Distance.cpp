/*
QUESTION:-

Given two strings word1 and word2, return the minimum number of operations
needed to convert word1 into word2. You can use three operations on a word:
insert a character, delete a character, or replace a character.

Constraints:
0 <= word1.length, word2.length <= 500
Both words contain only lowercase English letters.

Example 1:

Input:
word1 = "horse"
word2 = "ros"

Output:
3
(horse -> rorse (replace h with r) -> rose (delete r) -> ros (delete e))

Example 2:

Input:
word1 = "intention"
word2 = "execution"

Output:
5
*/

/*
APPROACH:-

-> Let edit[i][j] be the minimum operations to turn the first i characters of word1 into the first j characters of word2.
-> Base cases: turning i characters into an empty string needs i deletions, and turning an empty string into j characters needs j insertions.
-> If the last characters word1[i - 1] and word2[j - 1] are equal, no operation is needed for them: edit[i][j] = edit[i - 1][j - 1].
-> Otherwise take 1 operation plus the best of three choices: replace (edit[i - 1][j - 1]), delete from word1 (edit[i - 1][j]) or insert into word1 (edit[i][j - 1]).
-> Each row only needs the previous row, so we keep two rows.
-> The answer is the last cell of the last row.
-> Let N and M be the lengths of the two words. We fill N * M cells, so the time is N * M.
-> Two rows of M + 1 cells are stored, so the space is M.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int editDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    vector<int> previousRow(m + 1, 0);
    vector<int> currentRow(m + 1, 0);

    for (int j = 0; j <= m; j++)
    {
        previousRow[j] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        currentRow[0] = i;

        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                currentRow[j] = previousRow[j - 1];
            }
            else
            {
                int replaceCost = previousRow[j - 1];
                int deleteCost = previousRow[j];
                int insertCost = currentRow[j - 1];

                currentRow[j] = 1 + min(replaceCost, min(deleteCost, insertCost));
            }
        }

        previousRow = currentRow;
    }

    return previousRow[m];
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";

    int answer = editDistance(word1, word2);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * M)
SPACE COMPLEXITY = O(M)
*/
