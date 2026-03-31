#include<iostream>
#include<vector>
using namespace std;

vector<int> PairSum(int * arr, size_t size, int target) // Time complexity O(n)
{
    vector<int> ans;
    for (int i = 0, j = size - 1; i < j; )
    {
        if(arr[i] + arr[j] > target)
        {
            j--;
        }
        else if(arr[i] + arr[j] < target)
        {
            i++;
        }
        else
        {
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            cout << "Pairs : " << arr[i] << " + " << arr[j] << endl;
            return ans;
        }
    }
    return ans;
}

int MooreMajorityElement(int * arr, size_t size)
{
    int freq = 0 ;
    int maj = arr[0];

    for (int i = 0; i < size; i++)
    {
        if(freq == 0)
        {
            maj = arr[i];
        }

        if(arr[i] == maj)
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return maj;
}

int main()
{
    int arr[] = {2,7,8,12};

    PairSum(arr, sizeof(arr)/sizeof(int), 19);

    int arr2[] = {1,2,1};

    cout << "Majority Number : " << MooreMajorityElement(arr2, sizeof(arr2)/sizeof(int));

    return 0;
}