#include<iostream>
#include<unordered_map>
using namespace std;

/*
    Problem:
    Given a string, find the length of the longest substring that contains
    no repeating characters.

    Approach (Sliding Window + Unordered Map):
    We use two pointers:
    - `back`  -> start of the current window
    - `front` -> end of the current window

    The idea is to maintain a valid window where all characters are unique.

    We also use an unordered_map called `duplicate`
    to store the MOST RECENT index of every character.

    How it works:
    1. Expand the window by moving `front` through the string.
    2. If the current character has already appeared inside the current window,
    move `back` to one position after the previous occurrence.
    3. Calculate the current window length:
        (front - back) + 1
    4. Continuously update the maximum length found.

    Why `max(back, duplicate[ele] + 1)`?
    This prevents `back` from moving backwards.
    For example:
        s = "abba"

    When we see the second 'a',
    the previous 'a' is outside the current valid window,
    so we should NOT move `back` backwards.

    Example walkthrough for "abba":

    Index: 0 -> 'a'
    Window = "a"
    Length = 1

    Index: 1 -> 'b'
    Window = "ab"
    Length = 2

    Index: 2 -> 'b'
    Duplicate found.
    Move `back` to previous 'b' index + 1.
    Window becomes "b"
    Length = 1

    Index: 3 -> 'a'
    'a' exists before, but its old index is outside the current window.
    So `back` stays where it is.
    Window becomes "ba"
    Length = 2

    Final Answer = 2

    Time Complexity:
    O(n)
    Each character is processed once.

    Space Complexity:
    O(k)
    Where k is the number of unique characters stored in the unordered map.
*/

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int back = 0;
    int front = 0;
    int currentCount = 0;
    unordered_map<char, int> duplicate;

    for(int i = 0 ; i < s.size(); i++)
    {
        char ele = s[i];
        front = i;
        
        if(duplicate.find(ele) != duplicate.end())
        {
            // element found 
            back = max(back, duplicate[ele] + 1);
        }

        currentCount = (front - back)+1;
        duplicate[ele] = i;
        maxLength = max(currentCount, maxLength);
    }

    return maxLength;
}

int main()
{
    // string s = "abcabcbb"; // exp out = 3
    // string s = "bbbbb"; // exp out = 1
    // string s = "pwwkew"; // exp out = 3
    // string s = " "; // exp out = 1
    // string s = "dvdf"; // exp out = 3
    string s = "abba"; // exp out = 2

    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}