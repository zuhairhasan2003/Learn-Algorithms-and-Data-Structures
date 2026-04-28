#include<iostream>
#include<stack>
using namespace std;

/*
    Stack operates in the principle of FILO : first in last out
    You can only remove top element, one at a time
*/

void PrintStack(stack<int> & s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }   
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Stack size : " << s.size() << endl;

    stack<int> s2;
    s2.push(100);

    s2.swap(s);

    cout << "Stack 1 : " << endl;
    PrintStack(s);

    cout << "Stack 2 : " << endl;
    PrintStack(s2);

    return 0;
}