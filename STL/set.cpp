#include<iostream>
#include<set>
using namespace std;

/*
    Set only stores unique values
    Set stores data in a sorted order
    If you insert same element more then once, then it gets ignored and only 1 instance of that is stored

    Set is internally implemented using self balancing tree

    Func        |       Time Comp
    --------------------------------
    insert()    |       O(log n)
    erase()     |       O(log n)
    count()     |       O(log n)

    2 functions with sets:
        1) lower_bound(val)
            returns the iter of val if aval in the set
            if val not aval then it returns the iter to value just greater then val
        2) upper_bound(val)
            returns the iter to value just greater then val
            it does not return the iter to val itself, even if its present
*/

int main()
{
    set<int> s;

    s.insert(1);
    s.insert(13);
    s.insert(4);
    s.insert(6);
    s.insert(6);
    s.insert(6);
    s.insert(2);

    cout << "Size of set : " << s.size() << endl;

    cout << "Lower bound of set : " << *(s.lower_bound(4)) << endl;
    cout << "Upper bound of set : " << *(s.upper_bound(4)) << endl;

    for (auto val : s)
    {
        cout << val << endl;
    }

    return 0;
}