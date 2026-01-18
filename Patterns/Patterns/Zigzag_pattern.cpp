/*Problem:
Print a zig-zag pattern using stars for a fixed number of rows.

Approach:
Traverse each row and column and print stars only at positions that form a zig-zag shape using conditional checks, printing spaces elsewhere.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 9; j++) {
            if((i == 1 && j % 4 == 1) ||
               (i == 2 && j % 2 == 0) ||
               (i == 3 && j % 4 == 3))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}