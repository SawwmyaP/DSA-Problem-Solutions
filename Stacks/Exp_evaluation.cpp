#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char ch : exp) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (ch == '+') st.push(a + b);
            else if (ch == '-') st.push(a - b);
            else if (ch == '*') st.push(a * b);
            else if (ch == '/') st.push(a / b);
        }
    }
    return st.top();
}

int main() {
    string postfix = "352+*"; // (3*(5+2))
    cout << "Result = " << evaluatePostfix(postfix);
}
