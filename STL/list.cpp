#include<iostream>
#include<list>
using namespace std;

/*
    List in cpp STL lib is implemented as a doubly linkedlist
    Which means you can insert an element from back or front
    Which also means you can remove an element from back or front

    BUT there is no random access i.e. you cant do l[1], you will need to traverse the whole list
*/

void PrintList(list<int> & l)
{
    cout << "List : " ;
    for(auto i = l.begin(); i != l.end(); i++)  // "auto" replaces "list<int>::iterator"
    {
        cout << *(i) << "    ";
    }
    cout << endl;
}

int main()
{
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    l.push_front(4);

    PrintList(l);

    return 0;
}