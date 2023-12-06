#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string shortestPalindrome(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());

    string new_s = s + "#" + rev_s;
    int n = new_s.length();

    // Build the KMP table
    vector<int> kmp_table(n, 0);
    for (int i = 1, j = 0; i < n; ) {
        if (new_s[i] == new_s[j]) {
            kmp_table[i++] = ++j;
        } else {
            if (j != 0) {
                j = kmp_table[j - 1];
            } else {
                kmp_table[i++] = 0;
            }
        }
    }

    return rev_s.substr(0, s.length() - kmp_table[n - 1]) + s;
}

int main() {
    string input;

    cout << "Enter a string: ";
    cin >> input;

    string output = shortestPalindrome(input);
    cout << "Shortest Palindrome: " << output << "\n";

    return 0;
}
