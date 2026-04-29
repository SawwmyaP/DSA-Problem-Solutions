#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }
    for (int num : arr) {
        if (freq[num] == 1) {
            return num;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 5, 1, 2, 0, 4};
    int ans = firstNonRepeating(arr);
    if (ans != -1)
        cout << "First non-repeating element: " << ans;
    else
        cout << "No non-repeating element found";
  
    return 0;
}
