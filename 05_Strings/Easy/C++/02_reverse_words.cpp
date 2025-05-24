#include <bits/stdc++.h>
using namespace std;

// My Approach with some lil' extra feature
string reverseWords_MyApproach(string s) {
    // phase 1: extract the words
    // phase 2: reverse it
    // phase 3: concatenate the strings

    string word;
    vector<string> ansVector;
    string ans = "";

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            word.push_back(s[i]);
        } else if (word.size() > 1) {
            // reverse it
            cout << "word: " << word << "\n\n";
            int right = word.size() - 1;
            int left = 0;
            while (left < right) {
                char temp = word[left];
                word[left] = word[right];
                word[right] = temp;

                left++;
                right--;
            }

            ansVector.push_back(word);
            word = ""; // resetting the word
        }
    }

    if (word.size() > 1) {
        // reverse it
        cout << "word: " << word << "\n\n";
        int right = word.size() - 1;
        int left = 0;
        while (left < right) {
            char temp = word[left];
            word[left] = word[right];
            word[right] = temp;

            left++;
            right--;
        }

        ansVector.push_back(word);
        word = ""; // resetting the word
    }

    for (int i = ansVector.size() - 1; i >= 1; --i) {
        ans.append(ansVector[i]).append(" ");
        cout << i << ": " << ansVector[i] << "\n";
    }
    ans.append(ansVector[0]);

    return ans;
}

// My Approach for exact answer
string reverseWords_MyApproach_Exact(string s) {
    // phase 1: extract the words
    // phase 2: concatenate the strings in reverse order

    string word;
    vector<string> ansVector;
    string ans = "";

    for (int i = 0; i < s.size(); ++i) {
        // cout << s[i];
        if (s[i] != ' ') {
            word.push_back(s[i]);
        } else if (word.size() >= 1) {
            // cout << "word: " << word << "\n\n";

            ansVector.push_back(word);
            word = ""; // resetting the word
        }
    }

    if (word.size() >= 1) {
        // cout << "word: " << word << "\n\n";

        ansVector.push_back(word);
        word = ""; // resetting the word
    }

    // cout << "\n\n";
    for (int i = ansVector.size() - 1; i >= 1; --i) {
        ans.append(ansVector[i]).append(" ");
        // cout << i << ": " << ansVector[i] << "\n";
    }
    ans.append(ansVector[0]);

    return ans;
}

// better version
string reverseWords_Improved(string s) {
    vector<string> words;
    string word;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            word.push_back(s[i]);
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) words.push_back(word);

    string result = "";
    for (int i = words.size() - 1; i >= 0; --i) {
        result += words[i];
        if (i != 0) result += ' ';
    }
    return result;
}

int main(int argc, char* argv[]) {
    string s;
    getline(cin, s);

    cout << "string s: " << s << "\n\n";

    string ans;

    // ans = reverseWords_MyApproach(s);
    ans = reverseWords_MyApproach_Exact(s);
    ans = reverseWords_Improved(s);
    cout << ans;
    return 0;
}