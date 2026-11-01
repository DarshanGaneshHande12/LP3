// TC : O(n2) and SC : O(n2)

#include <iostream>
#include <vector>
using namespace std;

int n;

bool isSafe(vector<vector<int>>& board, int row, int col)
{
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solve(vector<vector<int>>& board, int row)
{
    // All queens placed
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;

            if (solve(board, row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    cout << "Enter N: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Invalid size!";
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solve(board, 0))
    {
        cout << "\nN-Queens Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";

            cout << endl;
        }
    }
    else
    {
        cout << "Solution does not exist!";
    }

    return 0;
}
