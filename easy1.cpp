//Easy 1- Given a string s consisting of words and spaces, return the length of the last word in the string. A word is a maximal  substring consisting of non-space characters only.

#include <iostream>

int lengthOfLastWord(const std::string& s) {
    int length = 0;

    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == ' ' && length == 0) {
            continue;
        }
        else if (s[i] != ' ') {
            ++length;
        } 
        else {
            break;
        }
    }

    return length;
}

int main() {
    // Example usage:
    std::string inputString = "Hi I am Sid     ";
    int result = lengthOfLastWord(inputString);
    std::cout << result << std::endl;

    return 0;
}
