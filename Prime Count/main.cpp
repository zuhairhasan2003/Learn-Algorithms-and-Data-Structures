#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
    Problem:
    I need to count how many prime numbers are smaller than n.

    Approach:
    I used the Sieve of Eratosthenes approach.
    First I assumed all numbers are prime by storing true in the array.
    Then I started from 2 and marked all of its multiples as non-prime.

    I only run the outer loop till i*i < n because if a number
    is not prime, then it must have a factor smaller than or equal
    to its square root. A factor means a number that can divide another
    number completely without leaving a remainder.

    That means smaller numbers would have already marked
    the non-prime numbers before reaching larger values of i.

    I also check if arr[i] is true before marking multiples
    so I only process prime numbers.

    Time Complexity:
    O(n log log n)

    Space Complexity:
    O(n)
*/

int countPrimes(int n) {

    if (n <= 1)
        return 0;

    vector<bool> arr (n, true);

    int primeCount = n - 2;

    for (int i = 2; i*i < n; i++)
    {
        if(arr[i])
        {
            for (int j = i * 2; j < n; j += i)
            {
                if(arr[j])
                {
                    arr[j] = false;
                    primeCount --;
                }
            }
        }
    }
    

    return primeCount;
}

int main()
{
    // int n = 2;
    // int n = 5000000;
    int n = 10;

    cout << countPrimes(n) << endl;


    return 0;
}