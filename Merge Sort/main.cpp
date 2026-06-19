#include<iostream>
#include<vector>
using namespace std;

void MergeSortWrapper(vector<int>& arr, int start, int end);

void MergeSort(vector<int>& arr) // Time comp : O(n log n)
{
    MergeSortWrapper(arr, 0, arr.size()-1);
}

void MergeSortWrapper(vector<int>& arr, int start, int end)
{
    if(start >= end)
        return;

    int mid = start + ((end-start)/2);
    MergeSortWrapper(arr, start, mid);
    MergeSortWrapper(arr, mid + 1, end);

    int temp[(end - start)+1];

    int temp_pointer = 0;

    int i = start;
    int j = mid+1;

    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
        {
            temp[temp_pointer] = arr[i];
            i++;
        }
        else
        {
            temp[temp_pointer] = arr[j];
            j++;
        }

        temp_pointer ++;
    }

    while (i <= mid)
    {
        temp[temp_pointer] = arr[i];
        i++;
        temp_pointer ++;
    }

    while (j <= end)
    {
        temp[temp_pointer] = arr[j];
        j++;
        temp_pointer ++;
    }

    for (temp_pointer = start; temp_pointer <= end; temp_pointer++)
    {
        arr[temp_pointer] = temp[temp_pointer-start];
    }
}

int main()
{
    vector<int> arr = {12,31,35,8,32,17};

    MergeSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;

    return 0;
}