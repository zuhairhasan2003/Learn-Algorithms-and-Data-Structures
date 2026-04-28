#include<iostream>
#include<vector>
#include<utility>
using namespace std;

/*
    Diff bw push_back() and emplace_back():
        push_back expects the object to be created already, it will only insert it
        emplace_back will create a object (if not already created) for you as well as push it

        vec.push_back("Alice", 20);   => will give error as obj is not created!
*/

int main()
{
    vector<pair<string, int>> vec;  // a vector that stores pair of human info

    pair<string, int> humanInfo = {"Bob", 19};  // a pair storing name and age of a human
    vec.push_back(humanInfo);

    vec.emplace_back("Alice", 20);

    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        cout << "Name : " << (*i).first << "  Age : " << (*i).second  << endl;
    }

    return 0;
}