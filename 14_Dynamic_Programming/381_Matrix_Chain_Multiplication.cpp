/*
QUESTION:-

You are given an array arr of size N + 1 that describes a chain of N matrices:
the i-th matrix has arr[i - 1] rows and arr[i] columns. Multiplying a matrix of
size a x b with a matrix of size b x c costs a * b * c operations. Matrix
multiplication is associative, so we can choose in which order to multiply the
chain. Return the minimum total number of operations needed to multiply all N
matrices.

Constraints:
2 <= arr.length <= 101 (that is, 1 to 100 matrices)
1 <= arr[i] <= 100

Example 1:

Input:
arr = [10,30,5,60]

Output:
4500
(three matrices 10x30, 30x5 and 5x60: multiply the first two, then the result with the last: 10*30*5 + 10*5*60 = 1500 + 3000)

Example 2:

Input:
arr = [40,20,30,10,30]

Output:
26000
*/

/*
APPROACH:-

-> The last multiplication of any order splits the chain into a left part (matrices i to k) and a right part (matrices k + 1 to j). We try every split point k.
-> Let dp[i][j] be the minimum cost to multiply matrices i to j. A single matrix costs 0, so dp[i][i] = 0.
-> If we split at k, the cost is dp[i][k] + dp[k + 1][j] plus the cost of multiplying the two results: the left result is arr[i - 1] x arr[k] and the right result is arr[k] x arr[j], so this last multiplication costs arr[i - 1] * arr[k] * arr[j].
-> dp[i][j] is the smallest cost over all k from i to j - 1.
-> Fill the table by increasing chain length (2, 3, ... N), so the smaller chains needed on the right side are already known.
-> The answer is dp[1][N].
-> Let N be the number of matrices. There are about N * N chains and each tries up to N splits, so the time is N * N * N.
-> The dp table has (N + 1) * (N + 1) cells, so the space is N * N.
*/

/*
CODE:-
*/

#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int> &arr)
{
    int n = arr.size() - 1;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i + length - 1 <= n; i++)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n];
}

int main()
{
    vector<int> arr = {10, 30, 5, 60};

    int answer = matrixChainMultiplication(arr);

    cout << answer << "\n";

    return 0;
}

/*
TIME COMPLEXITY = O(N * N * N)
SPACE COMPLEXITY = O(N * N)
*/
