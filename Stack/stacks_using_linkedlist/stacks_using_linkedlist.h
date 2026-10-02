#include <iostream>
#include <list>
using namespace std;

class Stacks_Using_Linkedlist {
private:
    list<int> l;
public:
    void push(int val); // O(1)
    int pop(); // O(1)
    int top(); // O(1)
    bool is_empty(); // O(1)
};