/*Problem:
Given stock prices for n days, find the stock span for each day.
The span is the number of consecutive days before and including the current day where the price was less than or equal to today’s price.

Approach:
Use a stack to store indices of days with higher prices.
For each day, pop until a greater price is found, then compute the span using index difference.*/

#include <iostream>
#include <stack>
using namespace std;

void stockSpan(int price[], int n) {
    stack<int> st;
    st.push(0);
    cout << "1 ";

    for (int i = 1; i < n; i++) {
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();

        int span = st.empty() ? (i + 1) : (i - st.top());
        cout << span << " ";
        st.push(i);
    }
}

int main() {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);

    cout << "Stock Spans: ";
    stockSpan(price, n);
    return 0;
}