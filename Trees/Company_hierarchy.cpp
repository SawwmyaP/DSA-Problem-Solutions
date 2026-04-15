#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>>& adj, vector<int>& informTime) {
    int maxTime = 0;

    for (int child : adj[node]) {
        maxTime = max(maxTime, dfs(child, adj, informTime));
    }
    return informTime[node] + maxTime;
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    vector<int> manager(n);
    vector<int> informTime(n);

    cout << "Enter manager array (-1 for head):\n";
    for (int i = 0; i < n; i++) {
        cin >> manager[i];
    }

    cout << "Enter inform time for each employee:\n";
    for (int i = 0; i < n; i++) {
        cin >> informTime[i];
    }

    int headID = -1;
    for (int i = 0; i < n; i++) {
        if (manager[i] == -1) {
            headID = i;
            break;
        }
    }
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        if (manager[i] != -1) {
            adj[manager[i]].push_back(i);
        }
    }
    int result = dfs(headID, adj, informTime);
    cout << "total time to inform all employees: " << result << endl;
return 0;
}
