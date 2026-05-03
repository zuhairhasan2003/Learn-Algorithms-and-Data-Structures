#include<iostream>
#include<unordered_set>
using namespace std;

/*
    unordered_set do not store duplicate data, they store unique values. Similar to normal sets
    unordered sets store data in random order (not sorted)

    upper_bound() and lower_bound() are not useful as unordered_set is not sorted

    Time comp of unordered_set are alot better then normal sets:
    Func        |       Sets        |       Unordered Sets
    -------------------------------------------------------
    insert()    |       O(log n)    |       O(1)
    erase()     |       O(log n)    |       O(1)
    count()     |       O(log n)    |       O(1)
*/

int main()
{
    unordered_set<int> unS;

    unS.insert(1);
    unS.insert(2);
    unS.insert(3);
    unS.insert(19);
    unS.insert(17);
    unS.insert(20);
    unS.insert(4);
    unS.insert(4);
    unS.insert(5);
    unS.insert(5);

    cout << "Unordered Set Size : " << unS.size() << endl;

    for(auto val : unS)
    {
        cout << val << endl;
    }

    return 0;
}