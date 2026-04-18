#include<iostream>
using namespace std;

// So this problem requires us to find the single element in the array
// 1 element is single only
// All other elements appear twice
// All elements are in asc order
// sizeof ar >= 3

// Time Comp = O(log n)

// We do a binary search approach
// If the mid is even then we know left and right number of elemets are also even
// If the mid is odd then we know left and right number of elemets are also odd

int SingleElement(int * arr, size_t size) // Time Complexity - O(log n)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = start + (end - start)/2;

        if((mid == 0 || arr[mid] != arr[mid - 1]) && (mid == size-1 || arr[mid] != arr[mid + 1]))
            return mid;

        if(mid % 2 == 0) // mid is even - this means even num of elements on left and right
        {
            if(arr[mid] == arr[mid-1]) // if curr element makes pair with left element the left side becomes odd (which also means that single element is in left)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else // mid is odd - meaning odd number of elements on left and right
        {
            if(arr[mid] == arr[mid-1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,2,3,3};
    size_t size = sizeof(arr) / sizeof(int);

    cout << arr[SingleElement(arr, size)] << endl;

    return 0;
}