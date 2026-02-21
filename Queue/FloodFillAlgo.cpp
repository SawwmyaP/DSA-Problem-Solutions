/*Problem: 
Given a 2D image, a starting pixel (sr, sc) and a new color,
Change the color of the starting pixel and all connected same-color pixels to new color.

Approach:
Use BFS or DFS starting from (sr, sc) and change the color of all 4-directionally connected pixels that have the same initial color.*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor == newColor) return image;

    int rows = image.size();
    int cols = image[0].size();

    queue<pair<int,int>> q;
    q.push({sr, sc});
    image[sr][sc] = newColor;

    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (auto& d : dirs) {
            int r = curr.first + d[0];
            int c = curr.second + d[1];

            if (r >= 0 && r < rows && c >= 0 && c < cols && image[r][c] == oldColor) {
                image[r][c] = newColor;
                q.push({r,c});
            }
        }
    }
    return image;
}

int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    for (auto row : result) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}