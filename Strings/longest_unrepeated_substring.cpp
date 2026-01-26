/*Problem:
Given a string, find the length of the longest substring that does not contain any repeating characters.

Approach:
Use a sliding window technique with a frequency array to maintain unique characters and update the maximum length of the substring.*/

#include <iostream>
using namespace std;

int main() {
    string s = "abcabcbb";
    int freq[256] = {0};
    int left = 0, maxLen = 0;

    for(int right = 0; right < s.length(); right++) {
        freq[s[right]]++;

        while(freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen;
    return 0;
}