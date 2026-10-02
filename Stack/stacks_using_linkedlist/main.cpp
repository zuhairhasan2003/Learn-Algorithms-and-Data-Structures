#include <iostream>
#include "stacks_using_linkedlist.h"

int main() {
    Stacks_Using_Linkedlist stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    while (!stack.is_empty())
    {
        int value = stack.top();
        stack.pop();

        cout << value << "  ";
    }
    cout << endl;

    return 0;
}