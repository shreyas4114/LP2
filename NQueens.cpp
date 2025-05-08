#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> &board)
{
    for (auto row : board)
    {
        for (auto cell : row)
        {
            cout << (cell == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 1 || board[i][col] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i < n && j < n; i++, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>> &board, int col, int n, vector<vector<vector<int>>> &solutions)
{
    if (col >= n)
    {
        solutions.push_back(board);
        return false;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;

            if (solveNQueens(board, col + 1, n, solutions))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void solveBB(int col, int n, vector<vector<int>> &board,
             vector<bool> &row, vector<bool> &diag1, vector<bool> &diag2,
             vector<vector<vector<int>>> &solutions)
{
    if (col >= n)
    {
        solutions.push_back(board);
        return;
    }

    for (int r = 0; r < n; r++)
    {
        if (!row[r] && !diag1[r + col] && !diag2[n - 1 + col - r])
        {
            board[r][col] = 1;
            row[r] = diag1[r + col] = diag2[n - 1 + col - r] = true;

            solveBB(col + 1, n, board, row, diag1, diag2, solutions);

            board[r][col] = 0;
            row[r] = diag1[r + col] = diag2[n - 1 + col - r] = false;
        }
    }
}

int main()
{
    int n;
    cout << "Enter board size (n): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<vector<int>>> solutions;

    cout << "\n--backtracking--\n";
    if (solveNQueens(board, 0, n, solutions))
    {
        cout << "Solution found!" << endl;
    }
    else
    {
        cout << "No solution!" << endl;
    }

    cout << "\nFound " << solutions.size() << " solution(s) using Backtracking:\n";
    for (auto sol : solutions)
    {
        printSolution(sol); // Correct print call
    }

    cout << "\n--branch and bound--\n";
    vector<vector<int>> bb_board(n, vector<int>(n, 0));
    vector<vector<vector<int>>> bb_solutions;
    vector<bool> row(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);

    solveBB(0, n, bb_board, row, diag1, diag2, bb_solutions); 

    if (bb_solutions.empty())
    {
        cout << "No solution exists\n";
    }
    else
    {
        cout << bb_solutions.size() << " solution(s) found using Branch and Bound:\n\n";
        for (auto sol : bb_solutions)
            printSolution(sol);
    }

    return 0;
}