#include<iostream>
#include<vector>
using namespace std;

/*
===========================================================
                 Knight's Tour Validation
===========================================================

Problem:
--------
Given a chess board containing numbers from 1 to N*N, determine
whether the board represents a valid Knight's Tour.

A valid Knight's Tour means:
- The knight starts from the square containing number 1.
- Each consecutive number (1 -> 2 -> 3 -> ... -> N*N) must be
  reachable using a legal knight move.
- Every square is visited exactly once.

Approach:
---------
This algorithm validates an already completed Knight's Tour.
It does not generate a tour.

Starting from the position containing 1, we recursively check
the 8 possible moves a knight can make. If any move leads to
the next required number (current value + 1), we continue
recursively from that position.

The recursion ends when:
1. The knight reaches N*N, meaning all squares have been visited
   correctly -> return true.
2. No valid knight move can reach the next number -> return false.

Since the board already contains the path, no backtracking is
required. We only verify whether the given sequence follows
valid knight movements.

Dry Run:
--------
Example:

1 -> 2 -> 3 -> ... -> N*N

At each step:
- Check all possible knight moves.
- Find the square containing current number + 1.
- Move to that square and repeat.

If the final number is reached, the board is a valid Knight's Tour.

Time Complexity:
----------------
For every square, we check at most 8 knight moves.

O(8 * N * N) = O(N * N)

Space Complexity:
-----------------
The recursion depth can go through every square in the worst case.

O(N * N)

===========================================================
*/

bool isCorrect(vector<vector<int>> & board, int row, int col, int prevNum)
{
    if(row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == prevNum + 1)
    {
        return true;
    }
    return false;
}

bool knightsTour(vector<vector<int>> & board, vector<vector<int>> & moves, int row, int col)
{
    if(board[row][col] == board.size() * board[0].size())
    {
        return true;
    }

    for (int i = 0; i < moves.size(); i++)
    {
        if(isCorrect(board, row + moves[i][0], col + moves[i][1], board[row][col]))
        {
            return knightsTour(board, moves, row + moves[i][0], col + moves[i][1]);
        }
    }
    return false;
}

bool KnightsTour(vector<vector<int>> & board, int row, int col)
{
    vector<vector<int>> moves;
    moves.push_back({-2, -1});
    moves.push_back({-2, 1});
    moves.push_back({-1, -2});
    moves.push_back({-1, 2});
    moves.push_back({1, -2});
    moves.push_back({1, 2});
    moves.push_back({2, -1});
    moves.push_back({2, 1});

    return(knightsTour(board, moves, row, col));
}

int main()
{
    vector<vector<int>> board = {
        {1,20,17,12,3},
        {16,11,2,7,18},
        {21,24,19,4,13},
        {10,15,6,23,8},
        {25,22,9,14,5}
    };

    if(KnightsTour(board, 0, 0))
    {
        cout << "The given board is a valid Knight's Tour." << endl;
    }
    else
    {
        cout << "The given board is not a valid Knight's Tour." << endl;
    }

    return 0;
}