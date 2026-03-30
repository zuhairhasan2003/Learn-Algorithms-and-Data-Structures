#include<iostream>
using namespace std;

int FindMaxSumSubArr(int * arr, size_t size)
{
    int max = -999;
    for (int i = 0; i < size; i++)
    {
        int runningTotal = 0;
        for (int j = i ; j < size ; j++)
        {
            runningTotal += arr[j];
            if (runningTotal > max) 
            {
                max = runningTotal;
            }
        }
    }
    return max;
}

int KadaneMaxSum(int * arr, size_t size)
{
    int max = INT_MIN;
    int runningTotal = 0;

    for (int i = 0; i < size; i++)
    {
        runningTotal += arr[i];
        max = runningTotal > max ? runningTotal : max;
        runningTotal = runningTotal < 0 ? 0 : runningTotal;
    }

    return max;
}

void PrintAllSubArrays(int * arr, size_t size)
{
    cout << "ALL SUB ARRAYS:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = i ; j < size ; j++)
        {
            for(int k = i; k <= j; k++)
            {
                cout << arr[k];
            }
            cout << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {-2,7,2,-1};

    PrintAllSubArrays(arr, sizeof(arr)/sizeof(int));

    cout << "Max value Via O(n^2) : " << FindMaxSumSubArr(arr, sizeof(arr)/sizeof(int)) << endl;

    cout << "Max value Via O(n) : " << KadaneMaxSum(arr, sizeof(arr)/sizeof(int)) << endl;

    return 0;
}