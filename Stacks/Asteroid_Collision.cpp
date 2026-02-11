/*Problem:
Given an array of integers representing asteroids,
positive values move right and negative values move left.
Return the final state after all possible collisions.

Approach: 
Use a stack to simulate collisions.
If current asteroid is moving left and stack top is moving right, compare sizes and resolve collision.
Continue until no collision possible.*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of asteroids: ";
    cin >> n;

    vector<int> ast(n);
    cout << "Enter asteroid values: ";
    for (int i = 0; i < n; i++)
        cin >> ast[i];

    stack<int> st;

    for (int i = 0; i < n; i++) {
        bool destroyed = false;

        while (!st.empty() && ast[i] < 0 && st.top() > 0) {
            if (abs(ast[i]) > st.top()) {
                st.pop();
            }
            else if (abs(ast[i]) == st.top()) {
                st.pop();
                destroyed = true;
                break;
            }
            else {
                destroyed = true;
                break;
            }
        }

        if (!destroyed)
            st.push(ast[i]);
    }

    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    cout << "Final State: ";
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << " ";

    return 0;
}