#include<iostream>
using namespace std;

// NOTE : Binary search only works for sorted arrays

int BinarySearch(int * arr, size_t size, int target) // Time comp : O(log n)
{
    int mid = (size-1)/2;
    for (int start = 0, end = size-1; start <= end; mid = (start+end)/2)
    {
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) end = (mid - 1);
        else start = (mid + 1);
    }
    
    return -1;
}

int BinarySearchRecursive(int * arr, int target, int start, int end) // Time comp : O(log n)
{
    if(start > end) return -1; // base case

    int mid = (start + end) / 2;

    if(arr[mid] == target)  return mid;
    else if(arr[mid] < target) return BinarySearchRecursive(arr, target, mid+1, end);
    else return BinarySearchRecursive(arr, target, start, mid-1);
}

int main()
{
    int arr[] = {2,3,4,7,9,18,20};
    size_t size = sizeof(arr) / sizeof(int);
    int target = 3;

    cout << "Index of the element " << target << " is : " << BinarySearch(arr, size, target) << "   (using iter approach)" << endl;
    cout << "Index of the element " << target << " is : " << BinarySearchRecursive(arr, target, 0, size-1) << "   (using recursive approach)" << endl;

    return 0;
}