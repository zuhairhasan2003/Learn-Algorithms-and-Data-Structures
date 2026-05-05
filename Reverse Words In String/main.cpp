#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

/*
    Problem: Given a string, reverse the order of words in it.
    A word is defined as a sequence of non-space characters.
    The string may contain leading, trailing or multiple spaces
    between words. The returned string should have words in 
    reversed order with only single spaces between them and 
    no leading or trailing spaces.

    Approach: 
    The idea is to use a two-pass reversal technique.
    First, reverse the entire string, then reverse each 
    individual word back to its original form. This gives us 
    the words in reversed order. Finally, we clean up the 
    string by removing any extra spaces including leading,
    trailing and multiple spaces between words.

    For example:
    "  hello world  " → "world hello"

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

string reverseWords(string s)  // Time Comp : O(n)
{
    int i = 0, j = s.size() - 1;

    while(i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }

    i = 0;
    while (i < s.size())
    {
        if(s[i] == ' ')
        {
            i++;
            continue;
        }

        j = i;
        while(s[j] != ' ' && j < s.size())
        {
            j++;
        }
        j--;

        int endIndex = j;

        while(i<j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }

        i = endIndex+1;

        i++;
    }

    // removing extra spaces
    i = 0;
    bool lastWasSpace = (s[i] == ' ');
    int numSpaces = (s[i] == ' '? 1 : 0);
    i++;

    while(i < s.size())
    {
        s[i-numSpaces] = s[i];
        if(lastWasSpace && (s[i] == ' '))
        {
            numSpaces++;
        }
        lastWasSpace = (s[i] == ' ');
        i++;
    }

    if(s[s.size() - 1 - numSpaces] == ' ') numSpaces++;

    s.resize(s.size()-numSpaces);

    return s;   
}


int main()
{
    cout << reverseWords("  hello world  ") << endl;
    return 0;
}