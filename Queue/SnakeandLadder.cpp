/*Problem:
Given a board with cells numbered from 1 to N, where some cells contain snakes or ladders, find the minimum number of dice throws (1–6 per move) required to reach cell N starting from cell 1.
If it is not possible to reach the last cell, return -1.

Approach:
Treat each board cell as a node and use BFS, where from each position you try all dice moves (1–6), applying snake/ladder jumps immediately, to find the minimum number of throws to reach the last cell.*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minDiceThrows(vector<int>& board, int N) {
    vector<bool> visited(N, false);
    queue<pair<int,int>> q; // {cell, diceThrows}

    visited[0] = true;
    q.push({0, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int cell = curr.first;
        int throws = curr.second;

        if (cell == N - 1)
            return throws;

        for (int dice = 1; dice <= 6 && cell + dice < N; dice++) {
            int next = cell + dice;

            if (!visited[next]) {
                visited[next] = true;

                if (board[next] != -1)
                    next = board[next];  // snake or ladder jump

                q.push({next, throws + 1});
            }
        }
    }
    return -1;
}

int main() {
    int N = 30;
    vector<int> board(N, -1);

    // Ladders
    board[2] = 21;
    board[4] = 7;
    board[10] = 25;
    board[19] = 28;

    // Snakes
    board[26] = 0;
    board[20] = 8;
    board[16] = 3;
    board[18] = 6;

    cout << "Minimum dice throws required: "
         << minDiceThrows(board, N);

    return 0;
}