/*Problem:
Given strings s and t, find the smallest substring of s that contains all characters of t with correct frequency.
Return empty string if no such window exists.

Approach:
Use a sliding window with frequency tracking to expand until all required characters are included.
Shrink the window from the left to obtain the smallest valid substring.*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    int freqT[256] = {0};
    int freqW[256] = {0};

    for (char c : t)
        freqT[c]++;

    int start = 0, minLen = INT_MAX, startIdx = -1;
    int count = 0;

    for (int end = 0; end < s.length(); end++) {
        freqW[s[end]]++;

        if (freqT[s[end]] && freqW[s[end]] <= freqT[s[end]])
            count++;

        while (count == t.length()) {
            if (end - start + 1 < minLen) {
                minLen = end - start + 1;
                startIdx = start;
            }

            freqW[s[start]]--;
            if (freqT[s[start]] && freqW[s[start]] < freqT[s[start]])
                count--;

            start++;
        }
    }

    if (startIdx == -1) return "";
    return s.substr(startIdx, minLen);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "Minimum Window Substring: " << minWindow(s, t);
    return 0;
}