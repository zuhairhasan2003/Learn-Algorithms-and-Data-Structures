#include<iostream>
#include<vector>
using namespace std;

/*
    Insertion sort also haves 2 parts of array : sorted and unsorted
    Insertion sort says : 1st element of an array is always sorted
    For each unsorted element it finds its place (pushing each element forward)
    In the end it places the element in its correct place
*/

void InsertionSort(vector<int> & arr) // O(n^2)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int curr = arr[i];

        int j = i - 1;
        while(j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}

void PrintArr(vector<int> & arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "     " ;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {8,9,4,5,3,1,2};

    cout << "Before : " << endl;
    PrintArr(arr);

    InsertionSort(arr);

    cout << "After : " << endl;
    PrintArr(arr);

    return 0;
}