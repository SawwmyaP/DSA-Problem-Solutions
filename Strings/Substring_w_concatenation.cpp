/*Problem:
Given a string s and an array of words words, find all starting indices of substrings in s that are a concatenation of each word exactly once and without intervening characters.

Approach:
Use a sliding window that moves in steps of word length while maintaining word frequency.
Reset the window whenever an invalid or excess word is encountered.*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (words.empty()) return result;

    int wordLen = words[0].size();
    int totalLen = wordLen * words.size();
    unordered_map<string, int> freq;

    for (string w : words) freq[w]++;

    for (int i = 0; i < wordLen; i++) {
        unordered_map<string, int> window;
        int left = i, count = 0;

        for (int right = i; right + wordLen <= s.size(); right += wordLen) {
            string w = s.substr(right, wordLen);

            if (freq.count(w)) {
                window[w]++;
                count++;

                while (window[w] > freq[w]) {
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                if (count == words.size())
                    result.push_back(left);
            } else {
                window.clear();
                count = 0;
                left = right + wordLen;
            }
        }
    }
    return result;
}

int main() {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> res = findSubstring(s, words);
    for (int idx : res)
        cout << idx << " ";
    return 0;
}