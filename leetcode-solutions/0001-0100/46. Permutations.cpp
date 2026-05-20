/*
Problem: Permutations
Approach: Backtracking
Time: O(2^n)
*/

void generatePermutations(vector<int>& set, vector<int>& permutation, vector<vector<int>>& permutations, int i, vector<int>& taken)
{
	if(i == set.size())
	{
		permutations.push_back(permutation);
		return;
	}

	for(int j = 0; j < taken.size(); j++)
	{
		if(taken[j] == 1) continue;
		taken[j] = 1;
		permutation.push_back(set[j]);
		generatePermutations(set, permutation, permutations, i+1, taken);
		permutation.pop_back();
		taken[j] = 0;
	}
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations = {};
        vector<int> permutation = {};
        vector<int> taken = {};
        for(int i = 0; i < nums.size(); i++) taken.push_back(0);

        generatePermutations(nums, permutation, permutations, 0, taken);

        return permutations;
    }
};