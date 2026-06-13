/*
Problem: Weighted Word Mapping
Approach: Instructions
Time: O(N)
*/

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for(string s : words)
        {
            int weight = 0;
            for(char c : s)
            {
                weight += weights[c - 'a'];
            }

            result += 'z' - (weight % 26);
        }
        return result;
    }
};