#include <iostream>
#include <vector>
using namespace std;

/*
============================================================
                     N-QUEENS PROBLEM
============================================================

PROBLEM:
--------
Place N queens on an N×N chessboard such that no two queens
attack each other. A queen can attack any piece that lies in
the same row, column, or diagonal. The goal is to find ALL
possible valid arrangements and return them.

Each solution is represented as a vector of strings, where:
  - 'Q' represents a queen
  - '.' represents an empty cell

Example (N = 4), two solutions exist:

  Solution 1:       Solution 2:
  . Q . .           . . Q .
  . . . Q           Q . . .
  Q . . .           . . . Q
  . . Q .           . Q . .

============================================================

APPROACH / SOLUTION:
--------------------
We use BACKTRACKING to explore all possible queen placements.

Key Insight:
  Since no two queens can share the same row, we place
  exactly ONE queen per row. We go row by row, trying every
  column in that row, and only proceed if the placement is
  safe. If we hit a dead end, we backtrack (undo the last
  placement) and try the next option.

============================================================

STEP-BY-STEP WALKTHROUGH:
--------------------------

1. ENTRY POINT — solveNQueens(n):
   - Creates an N×N board filled with '.' (empty cells).
   - Calls the recursive helper nQueen() starting at row 0
     with N queens left to place.
   - Returns all valid board configurations stored in 'out'.

2. SAFETY CHECK — isSafe(arr, row, col):
   Before placing a queen at (row, col), we check 3 directions
   going UPWARD (since rows below haven't been filled yet):

   a) Straight Up (same column):
      - Traverse from (row-1) up to row 0 in the same column.
      - If any cell has a 'Q', it's not safe.

   b) Upper-Left Diagonal:
      - Traverse diagonally up-left: (row-1, col-1),
        (row-2, col-2), ... until out of bounds.
      - If any cell has a 'Q', it's not safe.

   c) Upper-Right Diagonal:
      - Traverse diagonally up-right: (row-1, col+1),
        (row-2, col+2), ... until out of bounds.
      - If any cell has a 'Q', it's not safe.

   If none of the above directions have a queen → return true.

   NOTE: We don't check the current row (left/right) because
   we only place one queen per row, so no conflict is possible
   in the same row.

3. RECURSIVE FUNCTION — nQueen(arr, row, queensLeft, out):

   Base Cases:
   - If queensLeft == 0: All N queens have been successfully
     placed. Save the current board to 'out' and return.
   - If row >= N: We've gone past the last row without placing
     all queens. Dead end — return without saving.

   Recursive Case:
   - For each column i in the current row:
       a) Check if placing a queen at (row, i) is safe
          using isSafe().
       b) If safe:
          - Place the queen: arr[row][i] = 'Q'
          - Recurse to the next row with one fewer queen
            left to place: nQueen(arr, row+1, queensLeft-1, out)
          - BACKTRACK: Remove the queen: arr[row][i] = '.'
            (This undoes the placement so we can try the
             next column in the same row.)

4. MAIN:
   - Sets N = 4 and calls solveNQueens(4).
   - Prints all valid board configurations.

============================================================

EXAMPLE TRACE (N = 4):
-----------------------

 Row 0: Try col 0 → Safe → Place Q
 Row 1: Try col 0 → Unsafe (same col)
         Try col 1 → Unsafe (diagonal)
         Try col 2 → Safe → Place Q
 Row 2: All columns unsafe → BACKTRACK to Row 1
 Row 1: Try col 3 → Safe → Place Q
 Row 2: Try col 1 → Safe → Place Q
 Row 3: Try col 3 → Safe → Place Q → queensLeft = 0 → SAVE
 ... and so on until all possibilities are exhausted.

============================================================

TIME COMPLEXITY:
----------------
- Worst Case: O(N!)
============================================================
*/

void nQueen(vector<string> & arr, int row, int queensLeft, vector<vector<string>> & out);

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> out;
    vector<string> arr(n, string(n, '.'));

    nQueen(arr, 0, n, out);

    return out;
}

bool isSafe(vector<string> & arr, int row, int col)
{
    for(int i = row-1; i >= 0; i--) // top
        if(arr[i][col] == 'Q')
            return false;

    for(int i = row-1, j = col - 1; i >= 0 && j >= 0; i--, j--) // top left
        if(arr[i][j] == 'Q')
            return false;

    for(int i = row-1, j = col + 1; i >= 0 && j < arr.size(); i--, j++) // top right
        if(arr[i][j] == 'Q')
            return false;

    return true;
}

void nQueen(vector<string> & arr, int row, int queensLeft, vector<vector<string>> & out)
{
    if(queensLeft == 0)
    {
        out.emplace_back(arr);
        return;
    }

    if(row >= arr.size())
        return;

    for(int i = 0 ; i < arr.size(); i++)
    {
        if(isSafe(arr, row, i))
        {
            arr[row][i] = 'Q';
            nQueen(arr, row+1, queensLeft-1, out);
            arr[row][i] = '.';
        }
    }
}

int main()
{    int n = 4;
    vector<vector<string>> res = solveNQueens(n);   

    for(auto & v : res)
    {
        for(auto & s : v)
            cout << s << endl;
        cout << endl;
    }
    return 0;
}