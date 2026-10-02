#include <iostream>
#include <vector>
using namespace std;

class Stacks_Using_Vectors {
private:
    vector<int> v;
public:
    void push(int val); // O(1)
    int pop(); // O(1)
    int top(); // O(1)
    bool is_empty(); // O(1)
};