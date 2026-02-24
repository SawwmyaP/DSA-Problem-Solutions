/* Problem:
Given a 2D grid of '1' (land) and '0' (water), count the number of distinct islands, where an island is formed by adjacent lands connected horizontally or vertically.

Approach:
Traverse the grid and use BFS/DFS to mark all connected land cells as visited whenever a new '1' is found, and count how many times this process starts.*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                count++;
                queue<pair<int,int>> q;
                q.push({i,j});
                grid[i][j] = '0';

                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();

                    for (auto& d : dirs) {
                        int r = curr.first + d[0];
                        int c = curr.second + d[1];

                        if (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == '1') {
                            grid[r][c] = '0';
                            q.push({r,c});
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands: " << numIslands(grid);
    return 0;
}