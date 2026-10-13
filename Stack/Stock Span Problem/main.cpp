#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> Stock_Span_Problem(vector<int> arr) {
    vector<int> output;
    stack<int> s;

    int i = 0;
    while( i < arr.size() ) {

        if( i == 0 ) {
            output.push_back(1);
            s.push(i);
            i++;
            continue;
        }
        
        while( !s.empty() && arr[i] >= arr[s.top()] ) {
            s.pop();
        }

        if( !s.empty() )
            output.push_back(i-s.top());
        else
            output.push_back(i+1);
        s.push(i);

        i++;
    }

    return output;
}

int main() {
    vector<int> input = {100, 80, 60, 70, 60, 75, 85};

    vector<int> output = Stock_Span_Problem(input);

    for( auto i : output ) {
        cout << i << "  ";
    }
    cout << endl;

    return 0;
}