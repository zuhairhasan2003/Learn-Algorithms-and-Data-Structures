#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool customComparator(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second < p2.second) return true;
    else if(p1.second > p2.second) return false;
    else if(p1.first < p2.first) return true;
    return false;
}

int main()
{
    vector<pair<int,int>> vec;

    vec.push_back({2,2});
    vec.push_back({1,2});
    vec.push_back({3,5});
    vec.push_back({4,3});
    vec.push_back({5,9});
    vec.push_back({6,8});

    sort(vec.begin(), vec.end(), customComparator);

    for (auto ele : vec)
    {
        cout << ele.second << "     " << ele.first << endl;
    }
    
    return 0;
}