#include<iostream>
using namespace std;

// This is just a function to find a^x but in O(log n) time complexity instead of O(n)
double BinaryExponentiation(int a, int x)
{
    bool isNeg = false;
    if(x < 0) // to handle -ve powers
    {
        x = -x;
        isNeg = true;
    }

    double ans = 1;
    int prev = a;

    while (x > 0)
    {
        if(x % 2 == 1)
        {
            ans *= prev;
        }
        prev *= prev;
        x >>= 1;
    }

    if(isNeg)
        return (1/ans);
    else
        return ans;
}

int main()
{
    int a = 3;
    int x = -5;
    cout << a << " to the power " << x << " : " << BinaryExponentiation(a,x) << endl;
    return 0;
}