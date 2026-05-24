#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
    Problem:
    Given an integer array and an integer target k, find the total number
    of continuous subarrays whose sum is exactly equal to k.

    A subarray means a continuous portion of the array.
    Example:
    Array = [1, 2, 3]
    Subarrays:
    [1], [2], [3], [1,2], [2,3], [1,2,3]

    If k = 3:
    Valid subarrays are:
    [1,2]
    [3]

    Answer = 2


    ======================================================================
    CORE IDEA OF THE PROBLEM
    ======================================================================

    The biggest challenge in this problem is efficiently checking the sum
    of every possible subarray.

    Brute force approach:
    - Start from every index
    - Generate every subarray
    - Calculate sum every time

    This takes O(n²) or even O(n³) depending on implementation.

    Instead, we use:
    1. Prefix Sum
    2. Hash Map (unordered_map)

    Together, they allow us to solve the problem in O(n).


    ======================================================================
    WHAT IS A PREFIX SUM?
    ======================================================================

    A prefix sum is the cumulative sum from index 0 up to the current index.

    Example:
    arr = [9, 4, 20, 3, 10, 5]

    Prefix sums become:

    Index:      0   1   2   3   4   5
    Value:      9   4  20   3  10   5

    PrefixSum:
            9
            13
            33
            36
            46
            51

    Meaning:
    - 9  = 9
    - 13 = 9 + 4
    - 33 = 9 + 4 + 20
    - 36 = 9 + 4 + 20 + 3
    etc.


    ======================================================================
    MOST IMPORTANT OBSERVATION
    ======================================================================

    Suppose:
    Current Prefix Sum = runningTotal

    If we previously had a prefix sum equal to:
    runningTotal - target

    Then:
    (currentPrefixSum - oldPrefixSum) = target

    Which means:
    The subarray between those two positions has sum = target.


    ======================================================================
    VERY IMPORTANT MATHEMATICAL RELATION
    ======================================================================

    Suppose:

    PrefixSum[j] = sum from index 0 to j
    PrefixSum[i] = sum from index 0 to i

    Then:

    SubarraySum(i+1 to j) = PrefixSum[j] - PrefixSum[i]

    We want:
    SubarraySum = target

    So:

    PrefixSum[j] - PrefixSum[i] = target

    Rearranging:

    PrefixSum[i] = PrefixSum[j] - target

    This is the ENTIRE foundation of the solution.

    So while traversing:
    - Current prefix sum = PrefixSum[j]
    - We search for:
        PrefixSum[j] - target

    If it existed before,
    then a valid subarray exists.


    ======================================================================
    WHY DO WE USE A HASH MAP?
    ======================================================================

    We need fast lookup of previous prefix sums.

    unordered_map<int,int> prefixSum;

    Key:
    - prefix sum value

    Value:
    - how many times that prefix sum appeared

    Why frequency instead of boolean?

    Because the SAME prefix sum can appear multiple times.

    Example:
    arr = [1, -1, 1, -1]

    Prefix sums:
    1
    0
    1
    0

    Notice:
    - prefix sum 0 appears twice
    - prefix sum 1 appears twice

    Each occurrence can form different valid subarrays.

    So we store count/frequency.


    ======================================================================
    WHY prefixSum[0] = 1 IS EXTREMELY IMPORTANT
    ======================================================================

    This line is one of the most technical parts:

    prefixSum[0] = 1;

    Why do we do this?

    Because sometimes the subarray itself starts from index 0.

    Example:
    arr = [1,2,3]
    target = 3

    At index 1:
    runningTotal = 3

    We compute:
    toFind = runningTotal - target
            = 3 - 3
            = 0

    Now we ask:
    "Did we previously have prefix sum = 0?"

    YES.
    Because we inserted:
    prefixSum[0] = 1

    This represents:
    "Before the array started, cumulative sum was 0."

    Without this line:
    subarrays starting from index 0 would NEVER be counted.


    ======================================================================
    DETAILED DRY RUN
    ======================================================================

    Example:
    arr = [9,4,20,3,10,5]
    target = 33

    Initial State:
    runningTotal = 0
    count = 0

    Map:
    {0 : 1}


    ----------------------------------------------------------------------
    Iteration 1
    ----------------------------------------------------------------------
    Element = 9

    runningTotal += 9
    runningTotal = 9

    toFind = runningTotal - target
        = 9 - 33
        = -24

    Is -24 in map?
    NO

    Insert current prefix sum:
    map[9]++

    Map:
    {
    0 : 1,
    9 : 1
    }


    ----------------------------------------------------------------------
    Iteration 2
    ----------------------------------------------------------------------
    Element = 4

    runningTotal = 13

    toFind = 13 - 33
        = -20

    Not found.

    Insert:
    map[13]++

    Map:
    {
    0 : 1,
    9 : 1,
    13 : 1
    }


    ----------------------------------------------------------------------
    Iteration 3
    ----------------------------------------------------------------------
    Element = 20

    runningTotal = 33

    toFind = 33 - 33
        = 0

    Is 0 present?
    YES -> frequency = 1

    This means:
    There exists one previous prefix sum such that:
    33 - 0 = 33

    So:
    Subarray from index 0 to 2 has sum 33.

    count += 1

    count = 1

    Insert:
    map[33]++

    Map:
    {
    0 : 1,
    9 : 1,
    13 : 1,
    33 : 1
    }


    ----------------------------------------------------------------------
    Iteration 4
    ----------------------------------------------------------------------
    Element = 3

    runningTotal = 36

    toFind = 36 - 33
        = 3

    Is 3 present?
    NO

    Insert:
    map[36]++


    ----------------------------------------------------------------------
    Iteration 5
    ----------------------------------------------------------------------
    Element = 10

    runningTotal = 46

    toFind = 46 - 33
        = 13

    Is 13 present?
    YES

    Meaning:
    46 - 13 = 33

    So:
    Subarray after prefix sum 13 till current index
    has sum 33.

    Prefix sum 13 occurred after index 1.

    So subarray:
    [20,3,10]

    count++

    count = 2


    ----------------------------------------------------------------------
    Iteration 6
    ----------------------------------------------------------------------
    Element = 5

    runningTotal = 51

    toFind = 51 - 33
        = 18

    18 not found.

    End.


    Final Answer:
    2


    ======================================================================
    WHY THIS WORKS SO EFFICIENTLY
    ======================================================================

    Normally:
    To calculate subarray sums,
    we repeatedly sum elements again and again.

    Prefix sums avoid recomputation.

    Hash map avoids searching linearly for old sums.

    Together:
    - each element processed once
    - each lookup O(1)

    Total:
    O(n)


    ======================================================================
    TIME COMPLEXITY
    ======================================================================

    Traversal:
    O(n)

    Hash map insertion and lookup:
    Average O(1)

    Overall:
    O(n)
*/

int subarraySum(vector<int>& arr, int tar) {
    int runningTotal = 0;

    unordered_map<int,int> prefixSum;
    prefixSum[0] = 1;

    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        runningTotal += arr[i];

        int toFind = runningTotal - tar;
        if(prefixSum.find(toFind) != prefixSum.end())
        {
            count += prefixSum[toFind];
        }

        if(prefixSum.find(runningTotal) != prefixSum.end())
            prefixSum[runningTotal]++;
        else
            prefixSum[runningTotal] = 1;
    }
    
    return count;
}

int main()
{
    // vector<int> arr = {1,2,3};
    // int tar = 3;

    // vector<int> arr = {1};
    // int tar = 0;

    // vector<int> arr = {1,-1,0};
    // int tar = 0;

    vector<int> arr = {9,4,20,3,10,5};
    int tar = 33;

    cout << subarraySum(arr, tar) << endl;

    return 0;
}