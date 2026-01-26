/*Problem:
Given a string containing brackets (), {}, and [], check whether the brackets are balanced.

Approach:
Use a stack to store opening brackets and pop them when a matching closing bracket is encountered; if the stack is empty at the end, the string is balanced.*/

#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;

    for(char c : s) {
        if(c == '(' || c == '{' || c == '[')
            st.push(c);
        else {
            if(st.empty()) return false;
            char top = st.top();
            st.pop();
            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '['))
                return false;
        }
    }
    return st.empty();
}

int main() {
    string s = "{[()]}";
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced");
    return 0;
}