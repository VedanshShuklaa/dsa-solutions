/*
Problem: Combination Sum
Approach: Backtracking
Time: O(2^n)
*/

void solve(vector<int>& candidates, int target, vector<vector<int>>& combinations, vector<int>& combination, int combinationSum, int i)
{
    if(combinationSum > target) return;
    else if (combinationSum == target)
    {
        combinations.push_back(combination);
        return;
    } else
    {
        for(int j = i; j < candidates.size(); j++)
        {
            combination.push_back(candidates[j]);
            solve(candidates, target, combinations, combination, combinationSum + candidates[j], j); // Here j is our start index, basically to avoid going back in choices and causing duplicates
            combination.pop_back(); // Undo
        }
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations = {};
        vector<int> combination = {};

        solve(candidates, target, combinations, combination, 0, 0);

        return combinations;
    }
};