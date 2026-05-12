#include<iostream>
#include<vector>
using namespace std;

/*
    Problem: Search a 2D Matrix
    Given a matrix where each row and each column is sorted in ascending order,
    find if a target value exists in the matrix. Note that unlike a regular sorted
    matrix, the elements are not continuous meaning the last element of a row is
    not necessarily smaller than the first element of the next row.

    For example, given the matrix:
    1  4  7  11 15
    2  5  8  12 19
    3  6  9  16 22
    10 13 14 17 24
    18 21 23 26 30

    If we search for target = 5, we should return true as 5 exists in the matrix.
    If we search for target = 20, we should return false as 20 does not exist in the matrix.

    Approach: We start from the bottom-left corner of the matrix (last row, first column).
    If the current element equals the target, we return true. If the current element is
    greater than the target, we move up (row--) because all elements below are even greater.
    If the current element is less than the target, we move right (col++) because all
    elements to the left are even smaller. We repeat this process until we either find
    the target or go out of bounds.

    Time Complexity: O(m + n) where m is the number of rows and n is the number of columns.
    In the worst case, we traverse at most m + n elements, moving up through all rows
    or right through all columns.

    Space Complexity: O(1) as no extra space is used.
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int row = matrix.size()-1;
    int col = 0;

    while(row >= 0 && col <= matrix[0].size()-1)
    {
        if(matrix[row][col] == target)
            return true;
        else if(matrix[row][col] > target)
            row --;
        else
            col ++;
    }

    return false;
}

int main()
{
    vector<vector<int>> vec = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout << searchMatrix(vec, 5) << endl;

    return 0;
}