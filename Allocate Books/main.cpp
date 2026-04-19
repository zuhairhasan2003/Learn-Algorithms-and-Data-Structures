#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// The problem:
/*
    You have n books
    Each book has some pages
    You have m students
    You need to distribute books to students
    Each book goes to 1 and only 1 student
    Each student should have at least 1 book
    Every book should be distributed

    You have to find minimun of maximun pages that each student will get

    e.g.
    students = 2
    books = [2,1,4,3,5]

    possible distrubutions:
    Student 1       Student 2       Max
    2 pages         13 pages        13
    3               12              12
    7               8               8
    10              5               10

    So the minimun of max = 8

    Your function will return 8
*/


// The working
/*
    We use a binary search based approach for this
    
    First we find sum of all pages = 15

    Then we run BS on "0 - SUM", saying that we will find maxPages that each student can have
    And out of those max pages we will find the min

    First we create a (imaginary) array that has values from 0 to sum of pages (15)

    Then we use BS on this array to determine if the maxPage is valid or invalid

    If it is valid then we say that we maybe able to find lower MaxPages
    If it is invalid than we say that prob the maxPages is too small we have to find bigger maxPages

    The function IsValid() only checks if the distribution is possible, as per our way

    e.g. 
    [2,1,4,3,5]
    
    => Mid = MaxPages = 7
    Student 1       Student 2
    7               8               (Invalid as 8 > 7)
    
    => Mid = MaxPages = 11
    Student 1       Student 2
    10              5                (Valid)
*/

bool IsValid(vector<int> & books, int numStudents, int maxPages) // Time comp : O(number of books) = O(n)
{
    int sum = 0;
    for(int i = 0 ; i < books.size() ; i++)
    {
        if(books[i] > maxPages)
            return false;

        if((sum + books[i]) > maxPages)
        {
            numStudents --;
            sum = 0;
            if(numStudents <= 0)
                return false;
        }
        sum += books[i];
    }
    return true;
}

int AllocateBooks(vector<int> & books, int numStudents) // Time complexity : O(number of books * log(sum of pages)) = O(n log s)
{
    int min = INT_MAX;

    int start = 0; 
    int end = accumulate(books.begin(), books.end(), 0);  // calculating the sum of vector

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if(IsValid(books, numStudents, mid)) // O(n)
        {
            min = min < mid ? min : mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    
    return min;
}

int main()
{
    vector<int> books = {11,6};
    int numStudents = 6;

    cout << AllocateBooks(books, numStudents) << endl;
    return 0;
}