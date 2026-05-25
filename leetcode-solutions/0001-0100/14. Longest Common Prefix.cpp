/*
Problem: Longest Common Prefix
Approach: Brute Force
Time: O(n * m) where n is number of strings and m is length of shortest string
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lCP = strs[0];

        for(int i = 0; i < strs.size(); i++)
        {
            if(strs[i].size() < lCP.size()) lCP = strs[i];
        }

        for(int i = 0; i < strs.size(); i++)
        {
            int size = min(lCP.size(), strs[i].size());
            for(int j = 0; j < size; j++)
            {
                if(strs[i][j] == lCP[j]) continue;
                lCP = strs[i].substr(0, j);
                break;
            }
        }

        return lCP;
    }
};