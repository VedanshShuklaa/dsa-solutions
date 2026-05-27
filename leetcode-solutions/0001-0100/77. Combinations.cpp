/*
Problem: Combinations
Approach: Backtracking
Time: O(C(n, k) * k)
*/

void generateCombinations(int n, int k, vector<vector<int>>& combinations, vector<int>& combination, vector<int>& taken, int j)
{
    if(combination.size() == k)
    {
        combinations.push_back(combination);
        return;
    }

    for(int i = j; i < n; i++)
    {
        if(taken[i] == 0)
        {
            combination.push_back(i+1);
            taken[i] = 1;

            generateCombinations(n, k, combinations, combination, taken, i+1);
        } else
        {
            continue;
        }

        combination.pop_back();
        taken[i] = 0;
    }
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations = {};
        vector<int> combination = {};
        vector<int> taken(n, 0);

        generateCombinations(n, k, combinations, combination, taken, 0);

        return combinations;
    }
};