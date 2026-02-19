/*Problem:
Design a hit counter which counts the number of hits received in the past 5 minutes (300 seconds).

Approach:
Use a queue to store timestamps of hits, and whenever getHits() is called, remove all timestamps older than 300 seconds from the current time and return the queue size.*/

#include <iostream>
#include <queue>
using namespace std;

class HitCounter {
    queue<int> q;

public:
    void hit(int timestamp) {
        q.push(timestamp);
    }

    int getHits(int timestamp) {
        while (!q.empty() && q.front() <= timestamp - 300) {
            q.pop();
        }
        return q.size();
    }
};

int main() {
    HitCounter counter;

    counter.hit(1);
    counter.hit(2);
    counter.hit(300);
    cout << counter.getHits(300) << endl;  // 3
    cout << counter.getHits(301) << endl;  // 2

    return 0;
}