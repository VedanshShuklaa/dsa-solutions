/*
Problem: Remove Element
Approach: Idk just iterate over it
Time: O(n)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int k = size;
        for(int i = 0; i < size; i++) if(nums[i] == val) k--;

        for(int i = 0; i < size; i++)
        {
            if(nums[i] == val)
            {
                for(int j = i; j < size; j++)
                {
                    if(nums[j] != val) {
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                    }

                    if(i == size) return k;
                }
            }
        }

        return k;
    }
};