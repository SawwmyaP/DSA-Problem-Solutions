/*Problem:
Given a string, reverse it using a stack.

Approach:
Push all characters of the string into a stack.
Pop characters one by one to form the reversed string.*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> st;
    for(char c : s)
        st.push(c);

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}