/*
Problem: Rotate String
Approach: Brute Force
Time: O(n^2)
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int len = goal.length();

        // Loop through all rotations and check for matches
        for(int i = 0; i < len; i++)
        {
            s = s.substr(1, len) + s.substr(0, 1);
            if (s == goal) return true;
        }

        return false;
    }
};