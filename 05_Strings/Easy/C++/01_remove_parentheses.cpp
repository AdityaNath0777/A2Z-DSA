/**
 * Problem Statement:
 *
 * A valid parentheses string is either empty "", "(" + A + ")", or A + B,
 * where A and B are valid parentheses strings,
 * and "+" represents string concatenation.
 *
 * For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
 * A valid parentheses string s is primitive
 *    if it is nonempty,
 *    and there does not exist a way to split it into s = A + B,
 * with A and B nonempty valid parentheses strings.
 *
 * Given a valid parentheses string s,
 * consider its primitive decomposition: s = P1 + P2 + ... + Pk,
 * where Pi are primitive valid parentheses strings.
 *
 * Return s after removing the outermost parentheses
 * of every primitive string
 * in the primitive decomposition of s.
 */

#include <bits/stdc++.h>
using namespace std;

// my approach
string removeOuterParentheses_myApproach(string s) {
    string ans;
    int cnt = 0; // 0 -> outer & gt 0 -> inner parentheses
    for (int i = 0; i < s.size(); ++i) {
        // opening of parent
        if (s[i] == '(') {
            // if cnt > 0 -> we are inside inner parentheses
            if (cnt)
                // push the inner opening parentheses into the ans string
                ans.push_back(s[i]);

            // increase the counter
            cnt++;
        } else {
            // decrease the counter first
            cnt--; // we've found the closing parentheses

            if (cnt) // if this cnt > 0 -> inner closing parentheses
                ans.push_back(s[i]);

            // else it is outer parenthese thus we will not push it
        }
    }

    return ans;
}

// standard appraoch
string removeOuterParentheses(string s) {
    string ans;
    int balance = 0; // to track the balance of the parentheses
    /**
     * cnt == 0: We are the at the 'surface' level, outside any primitive string
     * cnt > 0: We are inside one or more layers of parentheses
     */

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            if (balance) { // balance > 0 -> we are inside existing primitive string
                ans.push_back(s[i]);
            }

            // If balance was 0, this is the outermost '(',
            // which we will discard.

            // If balance was > 0,
            // this is an inner '(', which we will keep.
            ++balance; // a new opening parentheses has been encountered
        } else {
            --balance; // prev parentheses has been closed

            if (balance) {
                // even after closing if the balance > 0
                // means there is still an outer parentheses left
                // and there can be more inner parentheses left to store in the ans

                ans.push_back(s[i]);
            }
        }
    }

    return ans;
}

int main(int argc, char *argv[]) {
    string s;
    cin >> s;

    string ans;

    ans = removeOuterParentheses_myApproach(s);
    cout << ans << "\n";
    return 0;
}