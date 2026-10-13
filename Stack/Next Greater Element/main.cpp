#include <iostream>
#include <stack>
#include <list>
#include <vector>
using namespace std;

list<int> Next_Greater_Element( vector<int> arr ) {
    list<int> out;
    stack<int> s;

    int i = arr.size() - 1;
    while( i >= 0 ) {

        if( i == arr.size() - 1 ) {
            s.push(arr[i]);
            out.push_front(-1);

            i--;
            continue;
        }

        while( !s.empty() && arr[i] >= s.top() )
        {
            s.pop();
        }

        if( !s.empty() )
            out.push_front(s.top());
        else
            out.push_front(-1);

        s.push(arr[i]);

        i--;
    }

    return out;
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};

    list<int> out = Next_Greater_Element(arr);

    for( auto ele : out ) {
        cout << ele << "  ";
    }
    cout << endl;

    return 0;
}