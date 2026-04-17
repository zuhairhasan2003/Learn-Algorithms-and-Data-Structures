#include<iostream>
using namespace std;

// A mountain array is : [0,3,9,8,1]
// It has a peak, in this case its 9 (also the max element)
// Before peak everything is in ascending order
// After peak everything is in descending order

// We need to find the peak in O(log n) - So we will use a binary search approach

int FindPeakIndex(int * arr, size_t size) // O(log n)
{
    int start = 0;
    int end = size-1;

    while (start <= end)
    {    
        int mid = start + (end-start)/2;

        if(mid == 0 || mid == size - 1)
            return mid;

        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1])
        {
            return mid;
        }
        else if(arr[mid] > arr[mid-1]) // search right
        {
            start = mid+1;
        }
        else // search left
        {
            end = mid-1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {5,3};
    size_t size = sizeof(arr) / sizeof(int);

    int ind = FindPeakIndex(arr, size);

    ind == -1 ? cout << "No peak element" << endl : cout << "Peak element : " << arr[FindPeakIndex(arr, size)] << endl;

    return 0;
}