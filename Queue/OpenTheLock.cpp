/*Problem:
You have a lock with 4 wheels (0000–9999).
Each move → rotate one wheel forward or backward by 1.
Find minimum moves to reach target from "0000".

Approach:
Treat each lock combination as a node in a graph and use BFS starting from "0000", generating all possible next states while avoiding deadends and visited states, to find the minimum number of moves to reach the target.*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    unordered_set<string> visited;
    queue<pair<string,int>> q;

    if (dead.count("0000")) return -1;

    q.push({"0000", 0});
    visited.insert("0000");

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        string state = curr.first;
        int steps = curr.second;

        if (state == target) return steps;

        for (int i = 0; i < 4; i++) {
            string temp = state;

            // Move wheel forward
            temp[i] = (state[i] - '0' + 1) % 10 + '0';
            if (!dead.count(temp) && !visited.count(temp)) {
                visited.insert(temp);
                q.push({temp, steps + 1});
            }

            // Move wheel backward
            temp = state;
            temp[i] = (state[i] - '0' - 1 + 10) % 10 + '0';
            if (!dead.count(temp) && !visited.count(temp)) {
                visited.insert(temp);
                q.push({temp, steps + 1});
            }
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter number of deadends: ";
    cin >> n;

    vector<string> deadends(n);
    cout << "Enter deadends:\n";
    for (int i = 0; i < n; i++) {
        cin >> deadends[i];
    }

    string target;
    cout << "Enter target: ";
    cin >> target;

    int result = openLock(deadends, target);

    if (result == -1)
        cout << "Cannot reach target\n";
    else
        cout << "Minimum moves: " << result << endl;

    return 0;
}