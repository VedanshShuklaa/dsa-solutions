/*
Problem: Left and Right Sum Differences
Approach: Array
Time: O(n)
*/

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        vector<int> leftSum;
        vector<int> answer;

        for(int num : nums)
        {
            leftSum.push_back(sum);
            sum += num;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            answer.push_back(abs((leftSum[i]) - (sum - nums[i])));
            sum -= nums[i];
        }

        return answer;
    }
};