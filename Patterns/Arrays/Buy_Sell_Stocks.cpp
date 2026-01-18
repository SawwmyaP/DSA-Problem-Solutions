/*Problem:
Given daily stock prices, find the maximum profit from one buy and one sell.

Approach:
Track the minimum price so far and calculate the maximum profit at each step.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int minPrice = INT_MAX, profit = 0;

    for(int p : prices) {
        minPrice = min(minPrice, p);
        profit = max(profit, p - minPrice);
    }

    cout << profit;
    return 0;
}