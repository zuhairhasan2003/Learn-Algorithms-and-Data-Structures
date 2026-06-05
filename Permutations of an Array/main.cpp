#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    Problem: Print All Permutations of an Array
    --------------------------------------------
    Given an array of distinct integers, print all
    possible permutations of the array elements.
    For example: {1, 2, 3} has 6 permutations:
    1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1

    Approach: Backtracking
    ----------------------
    We use recursion + backtracking to generate all permutations.
    At each index 'ind', we try placing every element from
    index 'ind' to 'n-1' at position 'ind' by swapping.
    After the recursive call, we swap back (backtrack) to
    restore the original array for the next iteration.
    Base case: when 'ind' reaches the end of the array,
    we print the current permutation.

    Example Dry Run for {1, 2, 3}:
    ind=0: swap(0,0)->1,2,3 | swap(0,1)->2,1,3 | swap(0,2)->3,2,1
    ind=1: further swaps generate remaining permutations

    Time Complexity : O(N * N!)
    Space Complexity: O(N! + N)
*/

void PrintAllPermutations(vector<int>& arr, int ind)
{
    if(ind >= arr.size())
    {
        for(int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        swap(arr[ind], arr[i]);
        PrintAllPermutations(arr, ind + 1);
        swap(arr[ind], arr[i]);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    PrintAllPermutations(arr, 0);

    return 0;
}