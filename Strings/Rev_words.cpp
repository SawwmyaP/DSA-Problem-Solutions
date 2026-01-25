/*Problem:
Given a sentence, reverse the order of words without reversing the characters within each word.

Approach:
Split the sentence into individual words and then print the words in reverse order to obtain the reversed sentence.*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string s = "I love coding";
    stringstream ss(s);
    vector<string> words;
    string word;

    while(ss >> word)
        words.push_back(word);

    for(int i = words.size() - 1; i >= 0; i--)
        cout << words[i] << " ";

    return 0;
}