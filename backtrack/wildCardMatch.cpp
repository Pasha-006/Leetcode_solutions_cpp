#include <iostream>
#include <vector>

class Solution {
public:
    bool wildcardMatch(std::string &s, std::string &p, int i, int j, std::vector<std::vector<int>> &memo) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (i >= s.length() && j >= p.length()) {
            return memo[i][j] = 1;
        }
        
        if (j >= p.length()) {
            return memo[i][j] = 0;
        }
        
        if (i >= s.length()) {
            // Check if the remaining pattern consists solely of '*'
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') {
                    return memo[i][j] = 0;
                }
            }
            return memo[i][j] = 1;
        }

        if (p[j] == '*') {
            // Move to the next character in s or stay at the same character in p
            return memo[i][j] = wildcardMatch(s, p, i + 1, j, memo) || wildcardMatch(s, p, i, j + 1, memo);
        }

        if (p[j] == s[i] || p[j] == '?') {
            return memo[i][j] = wildcardMatch(s, p, i + 1, j + 1, memo);
        }

        return memo[i][j] = 0;
    }

    bool isMatch(std::string s, std::string p) {
        std::vector<std::vector<int>> memo(s.length() + 1, std::vector<int>(p.length() + 1, -1));
        return wildcardMatch(s, p, 0, 0, memo);
    }
};


