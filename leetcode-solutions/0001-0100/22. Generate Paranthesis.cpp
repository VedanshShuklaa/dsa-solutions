/*
Problem: Permutations
Approach: Backtracking
Time: O(2^n)
*/

void generate(vector<string>& combinations, string combination, int i, int n, int open, int close)
{
    if(combination.size() == 2*n)
    {
        combinations.push_back(combination);
        return;
    }

    if(open < n)
    {
        combination.push_back('(');
        generate(combinations, combination, i+1, n, open+1, close);
        combination.pop_back();
    }

    if(close < open)
    {
        combination.push_back(')');
        generate(combinations, combination, i+1, n, open, close+1);
        combination.pop_back();
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> combinations = {};
        string combination = "";

        generate(combinations, combination, 0, n, 0, 0);

        return combinations;
    }
};