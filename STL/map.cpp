#include<iostream>
#include<map>
using namespace std;

/*
    maps works on the concept of key value pairs, a key CANNOT be duplicated. 
    If you try to push a key again then simply its value gets over written instead of a duplicate being created.
    Value can be duplicated

    map<keyType, ValueType> mapvar;

    Maps stores data in ascending order of keys

    When you access data from a map you need to use .first and .second

    Time comp:
    insert()        o(log n)
    erase()         O(log n)
*/

int main()
{
    map<string, int> m;

    m["zuhair"] = 1;
    m["hasan"] = 2;
    m["raza"] = 3;
    // m.insert({"demo", 1});           you can use both syntax to insert

    m.erase("zuhair");

    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << "Name : " << (*i).first << "\tNumber : " << (*i).second << endl;
    }

    return 0;
}