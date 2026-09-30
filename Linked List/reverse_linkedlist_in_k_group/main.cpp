#include<iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    List ll;
    ll.pushBack(1);
    ll.pushBack(2);
    ll.pushBack(3);
    ll.pushBack(4);
    ll.pushBack(5);

    ll.reverseKGroup(2);

    ll.print();

    return 0;
}