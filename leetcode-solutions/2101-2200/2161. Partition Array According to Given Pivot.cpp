/*
Problem: Partition Array According to Given Pivot
Approach: Follow instructions
Time: O(n)
*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < pivot) result.push_back(nums[i]);
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == pivot) result.push_back(nums[i]);
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > pivot) result.push_back(nums[i]);
        }

        return result;
    }
};