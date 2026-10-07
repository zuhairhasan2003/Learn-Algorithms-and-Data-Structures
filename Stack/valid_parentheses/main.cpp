#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string input) {
    stack<char> s;

    int i = 0;
    while (i < input.size()) {

        if( input[i] == '(' || input[i] == '{' || input[i] == '[' ) {
            s.push(input[i]);
        }
        else {
            if ( s.empty() )
                return false;

            char t = s.top();

            if( (input[i] == ')' && t != '(')
                || (input[i] == '}' && t != '{')
                || (input[i] == ']' && t != '[') )
                return false;
            
            s.pop();
        }

        i ++;
    }

    if (s.size() == 0)
        return true;

    return false;
}

int main() {

    string arr[] = {
        "{([()])}", // valid
        "", // valid
        "[({([()])}" // invalid
    };

    for (int i = 0; i < 3; i++) {
        cout << isValid(arr[i]) << endl;
    }

    return 0;
}