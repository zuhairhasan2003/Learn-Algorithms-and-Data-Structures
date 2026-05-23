#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum_1(vector<int>& nums) {
    set<vector<int>> uniqueTrip;

    for(int i = 0; i < nums.size(); i++)
    {
        int tar = -nums[i];
        set<int> temp ;


        for(int j = i+1; j < nums.size(); j++)
        {
            int third = tar - nums[j];

            if(temp.find(third) != temp.end())
            {
                vector<int> trip = {nums[i], nums[j], third};
                sort(trip.begin(), trip.end());
                uniqueTrip.insert(trip);
            }

            temp.insert(nums[j]);
        }
    }

    vector<vector<int>> out(uniqueTrip.begin(), uniqueTrip.end());

    return out;
}

vector<vector<int>> threeSum_2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> out;

    for (int i = 0; i < nums.size(); i++)
    {
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        int j = i + 1;
        int k = nums.size()-1;

        while(j < k)
        {
            if(nums[i]+nums[j]+nums[k] == 0)
            {
                out.push_back({nums[i], nums[j], nums[k]});
                j++;
                while(j < k && nums[j] == nums[j-1]) 
                    j++;
                k--;
            }
            else if(nums[i]+nums[j]+nums[k] < 0)
            {
                j++;
                while(j < k && nums[j] == nums[j-1]) 
                    j++;
            }
            else
            {
                k--;
            }
        }
    }
    
    return out;
}

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> out = threeSum_2(nums);

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