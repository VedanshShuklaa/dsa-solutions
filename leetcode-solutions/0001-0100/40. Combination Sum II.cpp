/*
Problem: Combination Sum II
Approach: Backtracking
Time: O(2^n)
*/

void generateCombinations(vector<int> candidates, vector<int>& taken, vector<vector<int>>& combinations, vector<int>& combination, int sum, int target, int i)
{
    if(sum > target) return;
    else if (sum == target) {
        combinations.push_back(combination);
        return;
    }

    for(int a = i; a < candidates.size(); a++)
    {
        if(a > i && candidates[a] == candidates[a - 1])
            continue;
        combination.push_back(candidates[a]);
        generateCombinations(candidates, taken, combinations, combination, sum + candidates[a], target, a+1);
        combination.pop_back(); // Undo choice
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combination;
        vector<int> taken(candidates.size(), 0);

        sort(candidates.begin(), candidates.end());

        generateCombinations(candidates, taken, combinations, combination, 0, target, 0);

        return combinations;
    }
};