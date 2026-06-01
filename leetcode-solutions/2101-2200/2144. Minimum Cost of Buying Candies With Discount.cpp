/*
Problem: Minimum Cost of Buying Candies With Discount
Approach: Greedy
Time: O(nlogn)
*/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int sum = 0;

        while(!cost.empty())
        {
            int num1 = cost.back();
            cost.pop_back();
            if(cost.empty())
            {
                sum += num1;
                break;
            }
            int num2 = cost.back();
            cost.pop_back();
            if(cost.empty())
            {
                sum += num1 + num2;
                break;
            }
            sum += num1 + num2;
            cost.pop_back();
        }

        return sum;
    }
};