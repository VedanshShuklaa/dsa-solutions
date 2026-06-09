/*
Problem: Maximum Total Subarray Value I
Approach: Instructions
Time: O(n)
*/

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long max = -1;
        long long min = 1e9;

        for(int x : nums)
        {
            if(x > max) max = x;
            if(x < min) min = x;
        }

        return (max - min) * k;
    }
};