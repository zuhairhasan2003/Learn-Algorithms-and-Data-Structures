#include<iostream>
#include<vector>
using namespace std;

/*
    ============================================================
    Problem: Spiral Matrix
    ============================================================

    Given an m x n matrix, return all elements of the matrix
    in spiral order (clockwise, starting from the top-left).

    Example:
    Input:  [[1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]]

    Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]

    ------------------------------------------------------------
    Approach: Four-Boundary Pointers (Layer-by-Layer Peeling)
    ------------------------------------------------------------

    We maintain four boundary pointers that define the current
    unvisited rectangle of the matrix:

    sRow (start row)  — top boundary
    eRow (end row)    — bottom boundary
    sCol (start col)  — left boundary
    eCol (end col)    — right boundary

    In each iteration (one full "ring" of the spiral), we do:

    1. Traverse TOP row    → left to right  (sCol to eCol), then sRow++
    2. Traverse RIGHT col  → top to bottom  (sRow to eRow), then eCol--
    3. Traverse BOTTOM row → right to left  (eCol to sCol), then eRow--
    4. Traverse LEFT col   → bottom to top  (eRow to sRow), then sCol++

    After each traversal step, we check if the boundaries have
    crossed (e.g., sRow > eRow or sCol > eCol). If they have,
    we break early to avoid re-visiting elements. This handles
    edge cases like single-row or single-column matrices.

    The boundaries shrink inward after each full ring until all
    elements have been visited.

    ------------------------------------------------------------
    Complexity:
    Time:  O(m x n) — every element is visited exactly once
    Space: O(m x n) — for the output vector
============================================================
*/


vector<int> spiralOrder(vector<vector<int>>& matrix) { // O(m*n)

    vector<int> output;

    int sCol = 0, sRow = 0, eCol = matrix[0].size()-1, eRow = matrix.size()-1;

    while (sRow <= eRow && sCol <= eCol)
    {
        for (int i = sCol; i <= eCol; i++)
        {
            output.push_back(matrix[sRow][i]);
        }
        if (sCol > eCol)
            break;
        sRow ++;
    
    
        for(int i = sRow; i <= eRow; i++)
        {
            output.push_back(matrix[i][eCol]);
        }
        if(sRow > eRow)
            break;
        eCol --;
    
        
        for(int i = eCol; i >= sCol; i--)
        {
            output.push_back(matrix[eRow][i]);
        }
        if (eCol < sCol)
            break;
        eRow--;
    
        
        for (int i = eRow; i >= sRow; i--)
        {
            output.push_back(matrix[i][sCol]);
        }
        if(eRow < sRow)
            break;
        sCol ++;
    
    }

    return output;
}

int main()
{
    // vector<vector<int>> input = {{1,2,3}, {4,5,6}, {7,8,9}};
    // vector<vector<int>> input = {{1,2,3}};
    vector<vector<int>> input = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}};
    
    vector<int> output = spiralOrder(input);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << "  ";
    }
    cout << endl;
    
    
    return 0;
}