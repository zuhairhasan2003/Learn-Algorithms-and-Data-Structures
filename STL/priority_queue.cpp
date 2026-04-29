#include<iostream>
#include<queue>
using namespace std;

/*
    Although priority queue is implement as a binary search "tree" in the STL library, but we usually visualise it as a stack
    Priority queue has a special property that it has max element at the top and min at the bottom (so we can think of this as a sorted stack)

    Time complexities:
    push() : O(log n) ------------------------> Time complexity to insert in a BST is log n
    pop() : O(log n)
    top() : O(1)
*/

void PrintPriorityQueue(priority_queue<int> & pq)
{
    cout << "Priority Queue :" << endl;
    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}

int main()
{
    priority_queue<int> pq;

    // If you want to use a pq that is in desc order then use this syntax :
    //      priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(3);
    pq.push(1);
    pq.push(5);
    pq.push(7);
    pq.push(2);

    PrintPriorityQueue(pq);

    /*
    The output we get :
        7
        5
        3
        2
        1
    */

    return 0;
}