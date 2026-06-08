#include <iostream>
#include <vector>
using namespace std;

/*
    Problem:
    --------
    Given a partially filled 9x9 Sudoku board, fill all empty cells
    such that every row, every column, and every 3x3 sub-grid contains
    the digits 1 through 9 exactly once.

    Approach (Backtracking):
    ------------------------
    We solve the Sudoku by exploring all possible valid placements
    for empty cells.

    1. Traverse the board cell by cell.
    2. If the current cell already contains a number, move to the next cell.
    3. If the cell is empty ('.'):
       - Try placing digits '1' to '9'.
       - For each digit, check whether it is valid:
            * Not present in the current row.
            * Not present in the current column.
            * Not present in the current 3x3 sub-grid.
       - If valid, place the digit and recursively solve the remaining board.
    4. If the recursive call succeeds, the puzzle is solved.
    5. If no digit leads to a solution, undo the placement
       (backtrack) and try another digit.
    6. Continue until all cells are processed.

    Helper Functions:
    -----------------
    isSafe():
        Checks whether a digit can be placed at a given position
        without violating Sudoku rules.

    SudokuBuilder():
        Recursively fills the board using backtracking and returns
        true when a valid solution is found.

    Time Complexity:
    ----------------
    O(9^E)

    where E is the number of empty cells.
    For each empty cell we may try up to 9 digits, leading to an
    exponential search space in the worst case.
*/

bool SudokuBuilder(vector<vector<char>>& , int , int );

bool isSafe(vector<vector<char>>& board, int row, int col, char num)
{
    for (int i = (row/3)*3; i < ((row/3)*3) + 3; i++)
    {
        for (int j = (col/3)*3; j < ((col/3)*3) + 3; j++)
        {
            if(board[i][j] == num)
            {
                return false;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if(board[i][col] == num || board[row][i] == num)
        {
            return false;
        }
    }
    
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    SudokuBuilder(board, 0, 0);
}

bool SudokuBuilder(vector<vector<char>>& board, int row, int col) {

    if(row > 8 || col > 8)
    {
        return true;
    }

    int nextRow = row, nextCol = col;
    if(nextCol == 8)
    {
        nextCol = 0;
        nextRow++;
    }
    else
    {
        nextCol++;
    }

    if(board[row][col] != '.')
    {
        bool result = SudokuBuilder(board, nextRow, nextCol);

        if(result)
        {
            return true;
        }
    }
    else
    {
        for (char i = '1'; i <= '9'; i++)
        {
            if(isSafe(board, row, col, i))
            {
                board[row][col] = i;
    
                bool result = SudokuBuilder(board, nextRow, nextCol);
    
                if(result)
                {
                    return true;
                }
    
                board[row][col] = '.';
            }
        }
    }


    return false;
}

int main()
{
    vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};

    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}