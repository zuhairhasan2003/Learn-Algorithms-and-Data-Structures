#include<iostream>
using namespace std;

/*
    This program finds the HCF (Highest Common Factor) or GCD (Greatest Common Divisor)
    of two numbers using the Euclidean Algorithm. The main idea behind this algorithm
    is that the HCF of two numbers does not change if the larger number is replaced
    by the remainder obtained after dividing it by the smaller number.

    Once one number becomes 0, the other number is the HCF.

    Working Example for HCF(20, 28):

    Step 1:
    a = 20, b = 28
    Since b > a:
    b = 28 % 20 = 8

    Step 2:
    a = 20, b = 8
    Since a > b:
    a = 20 % 8 = 4

    Step 3:
    a = 4, b = 8
    Since b > a:
    b = 8 % 4 = 0

    Now one number becomes 0.
    The remaining number is 4, which is the HCF.

    The program contains:
    1. HCF()    -> Iterative approach using loops.
    2. HcfRec() -> Recursive approach using function calls.
*/

int HCF(int a, int b)
{
    while(a != 0 && b != 0)
    {
        if (a > b)
        {
            a = a % (b);
        }
        else
        {
            b = b % (a);
        }
    }

    return a+b;
}

int HcfRec(int a, int b)
{
    if(a == 0 || b == 0)
        return a+b;

    if(a > b)
        return HcfRec(a%b , b);
    else
        return HcfRec(a , b%a);

}

int main()
{
    cout << HCF(20,28) << endl;
    cout << HcfRec(20,28) << endl;
    return 0;
}