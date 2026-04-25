#include<iostream>
#include<vector>
using namespace std;

// PROBLEM
/*
    You have a array of 0's, 1's and 2's
    You need to sort them but in just 1 loop pass and O(n) time comp
*/

// SOLUTION
/*
    We use 2 pointers, and the concept is if we sort 0 and 2, 1 will auto be sorted
    Each time we encounter a 0, we thow it at the 0's pointer
    Each time we encounter a 2, we thow it at the 2's pointer
    Each time we encounter a 1, we skip to next element

    The only time we dont increase value of i is when we encounter 2, bc if we swap 1 at p0 this will cause issue as p0 is for 0's 
*/

void Swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void DutchNationalFlagAlgo(vector<int> & arr) // O(n)
{
    int p0 = 0, i = 0;
    int p2 = arr.size() - 1;

    while(i <= p2)
    {
        if(arr[i] == 0)
        {
            Swap(arr[i], arr[p0]);
            p0++;
            i++;
        }
        else if(arr[i] == 2)
        {
            Swap(arr[i], arr[p2]);
            p2--;
        }
        else
        {
            i++;
        }
    }
}

void Print(vector<int> & arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {2,0,2,1,1,0,1,2,0,0};
    // vector<int> arr = {0,0,2,2};
    // vector<int> arr = {2,1,0};
    // vector<int> arr = {1,2,0};

    cout << "Before" << endl;
    Print(arr);

    DutchNationalFlagAlgo(arr);

    cout << "After" << endl;
    Print(arr);

    return 0;
}