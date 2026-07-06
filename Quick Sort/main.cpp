#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    Algorithm: Quick Sort (Recursive)

    Idea:
    - Quick Sort is a Divide and Conquer sorting algorithm.
    - It chooses a pivot element (here, the last element of the current subarray).
    - The partition step rearranges the array so that:
        * All elements smaller than or equal to the pivot are placed on its left.
        * All elements greater than the pivot are placed on its right.
    - After partitioning, the pivot is in its correct sorted position.
    - The same process is then recursively applied to the left and right subarrays until
      each subarray contains zero or one element.

    Approach:
    1. Choose the last element as the pivot.
    2. Traverse the current subarray.
    3. Maintain an index (idx) that marks the boundary of elements <= pivot.
    4. Whenever an element <= pivot is found, swap it with arr[idx] and increment idx.
    5. After traversal, place the pivot at index idx by swapping arr[idx] and arr[end].
    6. Recursively sort:
           - Left subarray  : start to pivotIdx - 1
           - Right subarray : pivotIdx + 1 to end

    Base Case:
    - If start >= end, the subarray has one or zero elements, so it is already sorted.

    Time Complexity: O(n²)

    Space Complexity:
    - Average Case: O(log n) due to recursive call stack.
    - Worst Case  : O(n) when recursion becomes completely unbalanced.

    Notes:
    - Quick Sort is an in-place sorting algorithm (requires no extra array).
    - It is not a stable sorting algorithm (equal elements may change their relative order).
*/

int Partition(vector<int> &arr, int start, int end)
{
    int idx = start;

    for(int i = start; i < end; i++)
    {
        if(arr[i] <= arr[end])
        {
            swap(arr[i], arr[idx]);
            idx++;
        }
    }
    swap(arr[idx], arr[end]);
    return idx;
}

void QuickSort(vector<int> &arr, int start, int end)
{
    if(start >= end)
        return;

    int pivotIdx = Partition(arr, start, end);

    QuickSort(arr, start, pivotIdx-1);
    QuickSort(arr, pivotIdx+1, end);
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    cout << "Unsorted array: ";
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    QuickSort(arr, 0, arr.size()-1);

    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}