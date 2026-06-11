#include<iostream>
#include<vector>
using namespace std;

/*
    PROBLEM:
    Given an array of distinct positive integers and a target value,
    find all unique combinations of numbers whose sum is equal to
    the target.

    Rules:
    - Each number may be used an unlimited number of times.
    - The same combination should not appear more than once.
    - Return all valid combinations whose sum equals the target.

    Example:
        arr = {2, 3, 5}
        target = 8

    Output:
        [2, 2, 2, 2]
        [2, 3, 3]
        [3, 5]

    APPROACH (Backtracking):

    We use recursion to build combinations incrementally while
    maintaining:

    - sum         -> current sum of selected elements.
    - runningArr  -> current combination being formed.
    - i           -> current index being considered.

    RECURSIVE DECISIONS:

    Conceptually, each element has three possibilities:

    1. Include the element exactly once and move to the next element.
    2. Include the element multiple times.
    3. Do not include the element at all.

    In this implementation, these possibilities are handled using
    two recursive calls:

    A) Include the current element:

        runningArr.push_back(arr[i]);
        helper(..., i, ..., sum + arr[i], ...);

       Notice that 'i' does NOT change.

       Since we stay at the same index, the same element can be
       chosen again in the next recursive call. Repeatedly choosing
       this branch naturally generates the "include multiple times"
       scenario.

    B) Exclude the current element:

        helper(..., i + 1, ..., sum, ...);

       Here we move to the next index and stop considering the
       current element.

    Therefore:

    - Include multiple times  -> keep i unchanged.
    - Include once and move on -> eventually choose the include
      branch followed by the exclude branch.
    - Exclude completely -> directly choose the exclude branch.

    BASE CASES:

    1. If sum == target:
       - A valid combination has been found.
       - Store the current combination in the answer vector.
       - Return.

    2. If sum > target:
       - Current path can never lead to a valid solution.
       - Return.

    3. If i reaches the end of the array:
       - No more elements are available.
       - Return.

    BACKTRACKING:

    Before exploring the include branch:
        - Add the current element to runningArr.

    After returning:
        - Remove the element from runningArr.

    This restores the previous state so that other combinations
    can be explored without affecting future recursive calls.

    WHY BACKTRACKING?

    We must explore every possible valid combination.
    Backtracking allows us to make a choice, explore all paths
    resulting from that choice, undo the choice, and then try
    alternative possibilities.

    TIME COMPLEXITY:
    Exponential in the worst case because we explore many
    possible combinations.
*/

void helper(vector<int>& arr, int target, int i, vector<vector<int>>& ans, int sum, vector<int>& runningArr)
{
    if(sum == target)
    {
        ans.push_back(runningArr);
        return;
    }

    if(sum > target || i >= arr.size())
    {
        return;
    }

    runningArr.push_back(arr[i]);
    helper(arr, target, i, ans, sum + arr[i], runningArr);
    runningArr.pop_back();

    helper(arr, target, i+1, ans, sum, runningArr);
}

vector<vector<int>> CombinationSum(vector<int>& arr, int target)
{
    vector<vector<int>> ans;
    vector<int> runningArr;
    helper(arr, target, 0, ans, 0, runningArr);
    return ans;
}

int main()
{
    vector<int> arr = {2,3,5};
    vector<vector<int>> ans = CombinationSum(arr, 8);
    
    for(auto i: ans)    {
        for(auto j: i)        {
            cout << j << " ";
        }        cout << endl;
    }

    return 0;
}