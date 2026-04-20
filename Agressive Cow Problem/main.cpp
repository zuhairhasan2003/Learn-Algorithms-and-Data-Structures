#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool IsValid(vector<int> & stalls, int numCows, int minDist)
{
    int currCowIndex = 0;
    numCows --;

    for (int i = 1; i < stalls.size(); i++)
    {
        if(numCows <= 0)
        {
            return true;
        }

        if(stalls[i] - stalls[currCowIndex] >= minDist)
        {
            currCowIndex = i;
            numCows --;
        }
    }
    
    if(numCows <= 0)
    {
        return true;
    }
    return false;
}

int AgressiveCow(vector<int> & stalls, int numCows) // Final time comp : O(N log N)
{
    int ans = INT_MIN;

    sort(stalls.begin(), stalls.end());  // sorts the stalls in asc order - O(N log N)

    // creating a search space. The largest dist would be bw the 2 extemes
    int start = stalls[0];
    int end = stalls[stalls.size() - 1] - start;  

    while (start <= end) // O(log N)
    {
        int mid = start + (end - start)/2;
        
        if(IsValid(stalls, numCows, mid))  // O(log N)
        {
            start = mid + 1;
            ans = ans < mid ? mid : ans;
        }
        else
        {
            end = mid - 1;
        }
        
    }

    return ans;
}

int main()
{
    vector<int> stalls = {1,2,8,4,9};
    int numCows = 3;

    cout << AgressiveCow(stalls, numCows);

    return 0;
}