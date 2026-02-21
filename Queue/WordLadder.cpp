/*Problem:
Given: beginWord, endWord, wordList
Change only one letter at a time, and each transformed word must exist in wordList.
Return minimum transformations needed.

Approach:
Treat each word as a node in a graph and use BFS, where from each word you generate all possible one-letter transformations, and return the level when endWord is reached.*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int wordLadder(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return 0;

    queue<pair<string,int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        string word = curr.first;
        int steps = curr.second;

        if (word == endWord) return steps;

        for (int i = 0; i < word.length(); i++) {
            string temp = word;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                temp[i] = ch;
                if (dict.count(temp)) {
                    q.push({temp, steps + 1});
                    dict.erase(temp);  // mark visited
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << wordLadder("hit", "cog", wordList);
}