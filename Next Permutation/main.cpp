#include<iostream>
#include<vector>
using namespace std;

/*
    This algorithm finds the next permutation of a array in a lexicographical order
    e.g. {1,2,3}

    The possible permutations are:
    {1,2,3}
    {1,3,2}
    {2,1,3}
    {2,3,1}
    {3,1,2}
    {3,2,1}

    Notice that the permutations start at smallest int i.e. 123 and end at largest e.g. 321 (in asc order)
    lexicographical order means just the permutation after a input permutation

    e.g if input = {2,1,3} , output = {2,3,1}
    e.g if input = {1,2,3} , output = {1,3,2}

    Notice to get from input to permutation just after it we need a few things:
        pivot element ({left elements in asc order} {pivot elemnt} {right elements in desc order})
        The right elemts from pivot are arranged in desc order
        If we want to make 1 bigger int from the current one we want to find 1 element that is > the pivot from the right (rightmost greater element)
        we would want to swap the pivot element with greatest right most
        Note the right of new pivot are still in desc order e.g. 7654
        If we want to make the smallest of 7654 we would want to reverse the right arr 

*/

void Swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void NextPermutation(vector<int> & arr) // O(n)
{
    int i = arr.size() - 2;
    while(i >= 0)
    {
        if(arr[i] >= arr[i+1])
            i--;
        else
            break;
    }
       
    int j;

    if(i < 0)
    {
        i = 0;
    }
    else
    {
        j = i + 1;
        while(j < arr.size() && arr[j] > arr[i])
            j++;
    
        Swap(arr[i], arr[j-1]);
    
        i++;
    }

    int midPoint = i + (((arr.size() - 1) - i) / 2);
    j = arr.size() - 1;

    while (i <= j)
    {
        Swap(arr[i] , arr[j]);
        i++;
        j--;
    }   
}

void Print(vector<int> & arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "    ";
    }
    cout << endl;
}

int main()
{
    //vector<int> arr = {1,2,3,8,7,6,5,4};
    //vector<int> arr = {2,3,1};
    vector<int> arr = {3,2,1};
    //vector<int> arr = {2,3,2,1};

    cout << "Before : " << endl;
    Print(arr);

    NextPermutation(arr);
    
    cout << "After : " << endl;
    Print(arr);

    return 0;
}