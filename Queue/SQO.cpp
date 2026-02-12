/* Problem:
Insert n elements into a queue and print them in FIFO order.

Approach:
Push elements using q.push(). While queue not empty → print q.front() and q.pop().*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    cout << "Queue elements: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}