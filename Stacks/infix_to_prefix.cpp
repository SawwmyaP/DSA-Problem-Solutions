/*Problem:
Convert a given infix expression into a prefix expression using stack.

Approach:
Reverse the infix expression and swap brackets.
Convert reversed infix to postfix, then reverse the result to get prefix*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    reverse(infix.begin(), infix.end());

    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    stack<char> st;
    string prefix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            prefix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) > precedence(ch)) {
                prefix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());
    cout << "Prefix Expression: " << prefix;
    return 0;
}