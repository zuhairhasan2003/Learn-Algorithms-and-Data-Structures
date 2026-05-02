#include<unordered_map>
#include<iostream>
using namespace std;

/*
    Unlike normal map, unordered maps store data in random manner (not sorted)

    unordered maps are internally implemented via hashing

    It is alot faster then a normal map

    FUNC    |   Maps    |   Unordered Maps
    ------------------------------------------
    insert()|  O(log n) |   O(1)
    erase() |  O(log n) |   O(1)
*/

int main()
{
    unordered_map<string, int> umap;

    umap.insert({"zuhair",0});
    umap["hasan"] = 1;
    umap["raza"] = 2;

    for (auto i = umap.begin(); i != umap.end(); i++)
    {
        cout << "KEY : " << (*i).first << "\tVALUE : " << (*i).second << endl;
    }

    return 0;
}