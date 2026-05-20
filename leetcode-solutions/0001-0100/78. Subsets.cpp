/*
Problem: Subsets
Approach: Backtracking
Time: O(2^n)
*/

void generateSubsets(vector<int>& set, vector<int> subset, vector<vector<int>>& subsets, int i)
{
	if(i == set.size()) return;
	generateSubsets(set, subset, subsets, i+1);
	subset.push_back(set[i]);
    subsets.push_back(subset);
	generateSubsets(set, subset, subsets, i+1);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};
        generateSubsets(nums, {}, subsets, 0);
        return subsets;
    }
};