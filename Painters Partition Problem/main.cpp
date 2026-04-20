#include<iostream>
#include<vector>
using namespace std;

bool IsValid(vector<int> & boards, int numPainters, int maxPerPainter)
{
    int sum = 0;
    for (int  i = 0; i < boards.size(); i++)
    {
        if(boards[i] > maxPerPainter)
            return false;

        if(boards[i] + sum > maxPerPainter)
        {
            numPainters --;
            if(numPainters <= 0)
                return false;
            
            sum = 0;
            i--;
            continue;
        }
        sum += boards[i];
    }
    
    return true;
}

int PaintersPartition(vector<int> & boards, int numPainters)
{
    int min = INT_MAX;

    int end = 0; // max time
    int start = INT_MIN; // min time
    for (int i = 0; i < boards.size(); i++)
    {
        end += boards[i];
        start = start < boards[i] ? boards[i] : start;
    }

    while (start <= end)
    {
        int mid = start + (end - start)/2;
        
        if(IsValid(boards, numPainters, mid)) // move left
        {
            min = min > mid ? mid : min;
            end = mid - 1;
        }
        else // move right
        {
            start = mid + 1;
        }
    }

    return min;
}

int main()
{
    vector<int> boards = {40,30,10,20};
    int numPainters = 2;

    cout << PaintersPartition(boards, numPainters);

    return 0;
}