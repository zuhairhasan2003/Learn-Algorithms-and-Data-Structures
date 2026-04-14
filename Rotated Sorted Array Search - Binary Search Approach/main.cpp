#include<iostream>
using namespace std;

// This is binary search but for sorted array that has been rotated once
// First we check what side (left or right) is sorted size
// Then we see is the target lies within the range of sorted array, if not then we do binary search for non sorted array

int RotatedSortedArray(int * arr, size_t size, int target)
{
    int index = -1;

    
    for (int start = 0, end = size-1; start <= end; )
    {
        int mid = start + (end - start)/2;

        if (arr[mid] == target)
        {
            index = mid;
            break;
        }

        if(arr[mid] < arr[end])   // right array is sorted
        {
            if(target >= arr[mid] && target <= arr[end])  // target within the range of right array
            {
                start = mid + 1;
            }
            else                                            // target not wihtin the right array
            {
                end = mid - 1;
            }
        }
        else   // left array is sorted
        {
            if(target <= arr[mid] && target >= arr[start])  // target within the range of left array
            {
                end = mid - 1;
            }
            else                                            // target not wihtin the left array
            {
                start = mid + 1;
            }
        }
    }

    return index;
}

int main()
{
    int arr[] = {2,1};
    size_t size = sizeof(arr) / sizeof(int);
    int target = 1;

    cout << "The index of element " << target << " is index : " << RotatedSortedArray(arr, size, target) << endl;

    return 0;
}