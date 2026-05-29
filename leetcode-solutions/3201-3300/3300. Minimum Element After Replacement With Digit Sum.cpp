/*
Problem: Minimum Element After Replacement With Digit Sum
Approach: As instructed
Time: O(n*d)
*/

class Solution {
public:
    int minElement(vector<int>& nums) {
        int min = 1e9;
        for(int num : nums)
        {
            int sum = 0;
            while(num != 0)
            {
                sum += num%10;
                num /= 10;
            }
            if (sum < min) min = sum;
        }

        return min;
    }
};