#include<iostream>
#include<vector>
using namespace std;

/*
    Selection sort works on the principle of having 2 parts of array, sorted and unsorted
    If left part is sorted then we find min value of unsoreted part and replace it with i
    In each outer loop 1 element of the array gets sorted
*/

void SelectionSort(vector<int> & arr) // Time complexity : O(n^2)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;

        for (int j = i+1; j < arr.size(); j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;    
        }

        swap(arr[i] , arr[minIndex]);
    }
}

void OptimisedSelectionSort(vector<int> & arr) // Still O(n^2) - just the search space reduced to half
{
    for (int i = 0, j = arr.size() - 1 ; i < j ; i++, j--)
    {
        int minIndex = i;
        int maxIndex = j;

        for(int temp = i ; temp <= j ; temp++)
        {
            if(arr[minIndex] > arr[temp])
                minIndex = temp;
            if(arr[maxIndex] < arr[temp])
                maxIndex = temp;
        }

        swap(arr[i] , arr[minIndex]);
        if(i == maxIndex)
        {
            maxIndex = minIndex;
        }
        swap(arr[j] , arr[maxIndex]);
    }
}

void PrintVector(vector<int> & arr)
{
    for (int  i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "    ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {7,3,1};
    
    cout << "Before : " << endl;
    PrintVector(arr);

    OptimisedSelectionSort(arr);
    
    cout << "After : " << endl;
    PrintVector(arr);

    return 0;
}