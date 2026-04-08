#include<iostream>
#include<vector>
using namespace std;

// Constraints : time comp = O(n) and space comp = O(1)

// This algo basically calculates the product of all the elements, except itself in the array
// We can see that to get the product of index i : we need product of all elements before and after i
// Thats why we have 2 vars : prefix and suffix that keeps track of prefixes and suffixes

vector<int> ProductOfArrayExceptSelf(int * arr, size_t size)
{
    vector<int> ans (size, 1);

    int prefix = 1;
    int suffix = 1;

    for (int i = 0, j = size - 1; i < size; i++, j--)
    {
        ans[i] *= prefix;
        ans[j] *= suffix;

        prefix *= arr[i];
        suffix *= arr[j];
    }

    return ans;
}

int main()
{
    int arr[] = {1,2,3,4};

    vector<int> ans = ProductOfArrayExceptSelf(arr, sizeof(arr)/sizeof(int));

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "    ";
    }
    cout << endl;

    return 0;
}