#include<unordered_map>
#include<algorithm>
#include<cstring>
#include<string>
#include <iostream>
using namespace std;

/*
    The problem asks us to check whether any permutation of string s1 exists as a substring in string s2. 
    Since a permutation is just a rearrangement of characters, we don't really need to generate all permutations and check them one by one, that would be way too slow. 
    Instead, the key insight here is that any permutation of s1 will always have the exact same character frequencies as s1 itself. 
    So the real question becomes, is there any window of length equal to s1's length in s2 that has the exact same character frequency distribution as s1?

    To solve this, I used a sliding window approach. 
    I first built a frequency map of all characters in s1. 
    Then I slid a window of the same size across s2, maintaining a frequency map of the current window. 
    As the window moves forward, I add the new right character and remove the leftmost character to keep the window size fixed. 
    At each step, I simply compare the two frequency maps, and if they match, it means the current window is a permutation of s1 and I return true. 
    If no such window is found throughout the entire traversal, I return false.
*/

bool checkInclusion(string s1, string s2)  // Time Comp : O(n)
{
    if(s2.size() < s1.size()) 
        return false;

    unordered_map<char,int> freqMapSlider;
    unordered_map<char,int> freqMapS1;

    for(int i = 0 ; i < s1.size(); i++)
    {
        freqMapS1[s1[i]] ++;
    }

    int l = 0;
    for(int r = 0; r < s2.size(); r++)
    {
        freqMapSlider[s2[r]]++;

        if(r-l >= s1.size())
        {
            freqMapSlider[s2[l]]--;
            if(freqMapSlider[s2[l]] == 0)
                freqMapSlider.erase(s2[l]);
            l++;
        }

        if(r-l+1 == s1.size() && freqMapSlider==freqMapS1)
            return true;
    }
    return false;        
}

int main()
{
    cout << checkInclusion("ab", "eidbaooo");
    return 0;
}