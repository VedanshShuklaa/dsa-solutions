/*
Problem: Subsets II
Approach: Backtracking
Time: O(n * 2^n) (really bad solution, could be better, will post another in future)
*/

void generateSubsets(vector<int> nums, vector<vector<int>>& subsets, vector<int>& subset, int i)
{
    if(i == nums.size())
    {
        for(auto& v : subsets)
        {
            if(v == subset) return;
        }
        subsets.push_back(subset);
        return;
    }

    subset.push_back(nums[i]);
    generateSubsets(nums, subsets, subset, i+1);

    subset.pop_back();
    generateSubsets(nums, subsets, subset, i+1);
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;

        generateSubsets(nums, subsets, subset, 0);

        return subsets;
    }
};