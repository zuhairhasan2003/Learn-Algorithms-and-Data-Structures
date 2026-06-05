#include<iostream>
#include<vector>
using namespace std;

/*
    PROBLEM:
    Generate and print all subsets (power set) of a given array.

    APPROACH:
    We use a recursive backtracking approach where at each index we have two choices:
    1. Do NOT include the current element in the subset.
    2. Include the current element in the subset.

    This forms a decision tree of size 2^n, covering all possible subsets.

    WHY THIS WORKS:
    - At every index i, we decide whether arr[i] belongs to the current subset or not.
    - By the time we reach index == arr.size(), we have constructed one complete subset.

    - This is NOT generating subarrays (which must be contiguous).
    - This generates subsets, where elements can be skipped.

    TIME COMPLEXITY:
    - O(2^n * n), because there are 2^n subsets and each takes O(n) time to print.

    SPACE COMPLEXITY:
    - O(n) recursion depth (excluding output storage).
*/


void PrintArr(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void PrintAllSubSets(vector<int>& arr, int i, vector<int>& currArr)
{
    if(arr.size() == i)
    {
        PrintArr(currArr);
        return;
    }

    PrintAllSubSets(arr, i + 1, currArr);

    currArr.push_back(arr[i]);
    PrintAllSubSets(arr, i + 1, currArr);
    currArr.pop_back();
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> currArr = {};
    PrintAllSubSets(arr, 0, currArr);
    return 0;
}