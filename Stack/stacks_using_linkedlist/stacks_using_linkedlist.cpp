#include <iostream>
#include "stacks_using_linkedlist.h"
using namespace std;

void Stacks_Using_Linkedlist::push(int val) {
    l.push_front(val);
}

int Stacks_Using_Linkedlist::pop() {
    int val = l.front();
    l.pop_front();
    return val;
}

int Stacks_Using_Linkedlist::top() {
    return l.front();
}

bool Stacks_Using_Linkedlist::is_empty() {
    return (l.size() == 0);
}