#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

/*
    Problem: String Compression
    
    So the problem is basically given a vector of characters, I need to compress 
    it in place. The way compression works is if a character repeats multiple 
    times, I replace it with the character followed by the count of how many 
    times it appears. For example, ['a','b','b','b'] becomes ['a','b','3']. 
    If a character only appears once, I just keep the character as it is without 
    any count. The trick here is I have to do this in place meaning I cant use 
    any extra array, and I return the new length of the compressed array.

    My Approach:
    
    I used a two pointer kind of approach. I keep track of a 'back' variable 
    which basically tells me how much I have compressed so far, so I can 
    overwrite the original array in place without losing any data. For each 
    group of same characters, I count how many times they appear using an 
    inner while loop, then I write the character and its count (if greater 
    than 1) back into the array at the correct position using the back offset. 
    At the end I just return the size minus back which gives me the new length.

    Time Complexity: O(n)
*/

int compress(vector<char>& chars) 
{
    int back = 0;

    for(int i = 0 ; i < chars.size() ; )
    {
        chars[i-back] = chars[i];
        
        int j = i;
        while(j < chars.size() && chars[j] == chars[i])
        {
            j++;
        }

        int count = j-i;
        i++;
        string countString = to_string(count);
        if(count > 1)
        {
            for(char c: countString)
            {
                chars[i-back] = c;
                i++;
            }
        }
        
        back += j - i;
        i = j;
    }

    return chars.size()-(back);
}

int main()
{
    // vector<char> chars ={'o','o','o','o','o','o','o','o','o','o'};
    // vector<char> chars ={'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    vector<char> chars ={'a','b','b','b','b','b','b','c','c'};
    
    int size = compress(chars);

    for(int i = 0 ; i < size ; i ++)
    {
        cout << chars[i] << "   ";
    }
    cout << endl;

    return 0;
}