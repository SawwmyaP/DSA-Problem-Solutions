/*Problem:
Given a grid where:
0 = empty cell
1 = fresh orange
2 = rotten orange
Every minute, rotten oranges infect adjacent fresh oranges (up, down, left, right).
Return minimum time required to rot all oranges. If impossible, return -1.

Approach:
Push all initially rotten oranges into queue (multi-source BFS).
For each minute, rot adjacent fresh oranges and push them into queue. Count time levels; if fresh oranges remain at end → return -1.*/

#include <iostream>
#include <queue>
using namespace std;

int orangesRotting(int grid[100][100], int m, int n) {
    queue<pair<int,int>> q;
    int fresh = 0, time = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 2)
                q.push({i,j});
            if(grid[i][j] == 1)
                fresh++;
        }
    }

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while(!q.empty() && fresh>0){
        int size = q.size();
        time++;

        for(int i=0;i<size;i++){
            auto p = q.front(); q.pop();

            for(int d=0; d<4; d++){
                int x = p.first + dir[d][0];
                int y = p.second + dir[d][1];

                if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1){
                    grid[x][y] = 2;
                    fresh--;
                    q.push({x,y});
                }
            }
        }
    }

    return fresh==0 ? time : -1;
}

int main(){
    int grid[100][100] = {{2,1,1},
                          {1,1,0},
                          {0,1,1}};
    cout << orangesRotting(grid,3,3);
    return 0;
}