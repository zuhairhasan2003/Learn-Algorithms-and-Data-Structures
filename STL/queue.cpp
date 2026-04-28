#include<iostream>
#include<queue>
using namespace std;

/*
    Queue operates in the principle of FIFO : first in first out
    You can only remove last(the one that came in first) element, one at a time
*/

void PrintQueue(queue<int> & q)
{
    while (!q.empty())
    {
        cout << q.front() << "    ";
        q.pop();
    }   
    cout << endl;
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Queue size : " << q.size() << endl;

    queue<int> q2;
    q2.push(100);

    q2.swap(q);

    cout << "Queue 1 : " << endl;
    PrintQueue(q);

    cout << "Queue 2 : " << endl;
    PrintQueue(q2);

    return 0;
}