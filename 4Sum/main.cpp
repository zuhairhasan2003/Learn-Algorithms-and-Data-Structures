#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

/*
    Problem:
    Given an array of integers, find all unique quadruplets (a, b, c, d) such that:
    a + b + c + d = 0. The result must not contain duplicate quadruplets.

    Approach:
    This solution uses a sorted array and the two-pointer technique to efficiently
    reduce the brute-force O(n^4) approach. First, the array is sorted so that
    duplicates can be easily skipped and the two-pointer strategy can be applied.

    We fix the first element (i) and second element (j) using two nested loops.
    For each pair (i, j), we treat the problem as a two-sum problem where we need
    to find two numbers (a, b) such that their sum equals -(arr[i] + arr[j]).

    We then use two pointers:
    - 'a' starts from j + 1
    - 'b' starts from the end of the array

    If arr[a] + arr[b] equals the target, we store the quadruplet and move both
    pointers while skipping duplicates.
    If the sum is smaller than the target, we increase 'a' to get a larger sum.
    If the sum is larger, we decrease 'b' to reduce the sum.

    We also carefully skip duplicate values for i, j, a, and b to ensure only
    unique quadruplets are included in the final result.

    Step-by-step flow:
    1. Sort the array.
    2. Fix first element i.
    3. Fix second element j.
    4. Use two pointers (a, b) to search for remaining two numbers.
    5. Check sum conditions and adjust pointers accordingly.
    6. Skip duplicates at every level.
    7. Store valid quadruplets.

    Time Complexity:
    Sorting takes O(n log n). The nested loops (i and j) combined with the
    two-pointer scan result in O(n^3) time complexity in the worst case.
*/

vector<vector<int>> Sum4(vector<int> arr)
{
    vector<vector<int>> out;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if(i > 0 && arr[i] == arr[i-1])
            continue;

        for (int j = i+1; j < arr.size(); j++)
        {   
            if(j > i+1 && arr[j] == arr[j-1])
                continue;

            int target = -(arr[i] + arr[j]);

            int b = arr.size()-1;
            int a = j + 1;

            while (a < b)
            {
                if(arr[a] + arr[b] == target)
                {
                    out.push_back({arr[i], arr[j], arr[a], arr[b]});

                    b--;
                    a++;
                    while (a < b && arr[a] == arr[a-1]) a++;
                }
                else if(arr[a] + arr[b] < target)
                {
                    a++;
                    while (a < b && arr[a] == arr[a-1]) a++;
                }
                else
                {
                    b--;
                }
            }
        }
    }
    
    return out;
}

int main()
{
    vector<int> arr = {0,0,0,0,0};

    vector<vector<int>> out = Sum4(arr);

    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[0].size(); j++)
        {
            cout << out[i][j] << "  ";
        }
        cout << endl;
    }
    
    return 0;
}