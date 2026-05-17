#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
    PROBLEM:
    Given an array of integers and a target value, find two numbers
    in the array that add up to the target and return their indices.
    For example, given arr = {5, 2, 11, 7, 15} and target = 9,
    the output should be indices of 2 and 7 (indices 1 and 3)
    since 2 + 7 = 9.

    APPROACH: Unordered Map
    Instead of using a brute force approach (nested loops) which would
    give us O(n^2) time complexity, we use a Hash Map to store the
    elements we have already visited. For each element in the array,
    we calculate the "complement" (target - current element) and check
    if that complement already exists in our Hash Map. If it does, we
    have found our pair and we return their indices. If it does not,
    we store the current element along with its index in the Hash Map
    and move on to the next element.


    HOW IT WORKS:
    1. We iterate through the array one element at a time.
    2. For each element, we calculate second = target - first.
    3. We check if "second" exists in our Hash Map.
    - If YES, we found our answer. We push both indices into
        the output vector and break out of the loop.
    - If NO, we insert the current element and its index
        into the Hash Map and continue.
    4. We return the output vector containing the two indices.


    TIME COMPLEXITY:  O(n) - We traverse the array only once and Hash Map lookup/insert is O(1) on average.
    SPACE COMPLEXITY: O(n) - In the worst case we store all elements in the Hash Map.
*/

vector<int> TwoSum(vector<int> arr, int target)
{
    vector<int> out;
    unordered_map<int, int> duplicate;

    for (int i = 0 ; i < arr.size() ; i++)
    {
        int first = arr[i];
        int second = target - first;

        unordered_map<int,int>::iterator it = duplicate.find(second);
        if(it != duplicate.end())
        {
            out.push_back(i);
            out.push_back((*it).second);
            break;
        }

        duplicate.insert({arr[i], i}); // value , index
    }

    return out;
}

int main()
{
    vector<int> arr = {5,2,11,7,15};
    int target = 9;

    vector<int> out = TwoSum(arr, target);

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << " ";
    }
    cout << endl;

    return 0;
}