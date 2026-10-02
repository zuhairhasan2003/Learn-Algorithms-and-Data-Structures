#include <iostream>
#include <vector>
#include "stacks_using_vectors.h"
using namespace std;

void Stacks_Using_Vectors::push(int val) {
    v.push_back(val);
}

int Stacks_Using_Vectors::pop() {
    int top = v[v.size()-1];
    v.pop_back();
    return top;
}

int Stacks_Using_Vectors::top() {
    return v[v.size()-1];
}

bool Stacks_Using_Vectors::is_empty() {
    return (v.size() == 0);
}