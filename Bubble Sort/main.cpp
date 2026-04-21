#include<iostream>
#include<vector>
using namespace std;

/*
    Bubble sort works on concept of adjecent swaps
    It checks if the adj element is >, then it swaps else it continues
*/

void Swap(vector<int> & arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void BubbleSort(vector<int> & arr)  // O(n^2)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        bool swapped = false;

        for (int j = 0 ; j < arr.size() - 1 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swapped = true;
                Swap(arr, j, j+1);
            }
        }

        if(!swapped)  // If it didnt swapped the first time that means the array is already sorted
            return;
    }
}

void PrintVector(vector<int> & arr)
{
    for (int  i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "   ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {7,3,2};

    cout << "Before : " << endl;
    PrintVector(arr);

    BubbleSort(arr);

    cout << "After : " << endl;
    PrintVector(arr);
    
    return 0;
}