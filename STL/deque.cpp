#include<iostream>
#include<deque>
using namespace std;

/*
    Deque is similar to list (doubly linkedlist) in STL library, which means you can push and pop from front and back
    
    BUT unlike list, Deque is internally implemented with dynamic arrays, which means it allows direct access i.e. dq[1]

    https://stackoverflow.com/questions/6292332/what-really-is-a-deque-in-stl
*/

void PrintDeque(deque<int> & dq)
{
    cout << "Deque : " ;
    for(int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << "    ";
    }
    cout << endl;
}

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);

    PrintDeque(dq);

    return 0; 
}