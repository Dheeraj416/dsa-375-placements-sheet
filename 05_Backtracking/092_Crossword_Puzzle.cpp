/*
QUESTION:-

You are given a crossword grid and a list of words. Every cell of the grid is
either '+' (a blocked cell) or '-' (an empty cell). A slot is a maximal
horizontal or vertical run of at least two empty cells. Each word must be
placed in exactly one slot, and it must fill the whole slot. Words are placed
letter by letter, and a cell shared by a horizontal and a vertical slot must
get the same letter from both words. Fill the grid with all the words and print
it. It is guaranteed that exactly one solution exists.

Constraints:
2 <= rows, columns <= 10
1 <= number of words <= 10
Every word has at least 2 uppercase letters, and all the words are different.

Example 1:

Input:
grid =
+-++++++++
+-++++++++
+-++++++++
+-----++++
+-+++-++++
+-+++-++++
+++++-++++
++------++
+++++-++++
+++++-++++
words = LONDON, DELHI, ICELAND, ANKARA

Output:
+L++++++++
+O++++++++
+N++++++++
+DELHI++++
+O+++C++++
+N+++E++++
+++++L++++
++ANKARA++
+++++N++++
+++++D++++

Example 2:

Input:
grid =
+-++
+-++
+-++
++++
words = CAT

Output:
+C++
+A++
+T++
++++
*/

/*
APPROACH:-

-> We place the words one after another with backtracking: try to put the current word somewhere, then try to place the next words, and if we get stuck, remove the word and try another position.
-> For the current word, try every starting cell and both directions (horizontal and vertical).
-> A word can be placed at a position only if it fits inside the grid, the cell before its first letter and the cell after its last letter are blocked or outside the grid (so it fills the whole slot), and every cell it covers is either empty ('-') or already holds the same letter.
-> When we place a word, remember which cells were empty before and are now filled, so we can restore exactly those cells when we backtrack.
-> If all the words are placed, we have the solution. If the current word cannot be placed anywhere, return false so that the previous word tries another position.
-> Let W be the number of words, R and C the grid size. Each word has about 2 * R * C possible placements, so the time is (R * C)^W in the worst case, but the letter checks cut the search heavily.
-> The recursion is W deep and the grid has R * C cells, so the space is W + R * C.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<string> &grid, string &word, int row, int col, bool horizontal)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int length = word.size();

    int endRow = horizontal ? row : row + length - 1;
    int endCol = horizontal ? col + length - 1 : col;

    if (endRow >= rows || endCol >= cols)
    {
        return false;
    }

    int beforeRow = horizontal ? row : row - 1;
    int beforeCol = horizontal ? col - 1 : col;

    if (beforeRow >= 0 && beforeCol >= 0 && grid[beforeRow][beforeCol] != '+')
    {
        return false;
    }

    int afterRow = horizontal ? row : endRow + 1;
    int afterCol = horizontal ? endCol + 1 : col;

    if (afterRow < rows && afterCol < cols && grid[afterRow][afterCol] != '+')
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        int r = horizontal ? row : row + i;
        int c = horizontal ? col + i : col;

        if (grid[r][c] != '-' && grid[r][c] != word[i])
        {
            return false;
        }
    }

    return true;
}

bool fillWords(int wordIndex, vector<string> &grid, vector<string> &words)
{
    if (wordIndex == (int)words.size())
    {
        return true;
    }

    int rows = grid.size();
    int cols = grid[0].size();
    string word = words[wordIndex];

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            for (int direction = 0; direction < 2; direction++)
            {
                bool horizontal = (direction == 0);

                if (!canPlace(grid, word, row, col, horizontal))
                {
                    continue;
                }

                vector<pair<int, int>> changed;

                for (int i = 0; i < (int)word.size(); i++)
                {
                    int r = horizontal ? row : row + i;
                    int c = horizontal ? col + i : col;

                    if (grid[r][c] == '-')
                    {
                        grid[r][c] = word[i];
                        changed.push_back({r, c});
                    }
                }

                if (fillWords(wordIndex + 1, grid, words))
                {
                    return true;
                }

                for (pair<int, int> cell : changed)
                {
                    grid[cell.first][cell.second] = '-';
                }
            }
        }
    }

    return false;
}

int main()
{
    vector<string> grid = {
        "+-++++++++",
        "+-++++++++",
        "+-++++++++",
        "+-----++++",
        "+-+++-++++",
        "+-+++-++++",
        "+++++-++++",
        "++------++",
        "+++++-++++",
        "+++++-++++"};
    vector<string> words = {"LONDON", "DELHI", "ICELAND", "ANKARA"};

    fillWords(0, grid, words);

    for (string &line : grid)
    {
        cout << line << "\n";
    }

    return 0;
}

/*
TIME COMPLEXITY = O((R * C)^W)
SPACE COMPLEXITY = O(W + R * C)
*/
