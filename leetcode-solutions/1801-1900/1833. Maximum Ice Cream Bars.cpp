/*
Problem: Maximum Ice Cream Bars
Approach: Counting Sort + Greedy
Time: O(N + len)
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int len = *max_element(costs.begin(), costs.end());
        vector<int> sortedCosts(len + 1, 0);
        int count = 0;

        for(int x : costs)
        {
            sortedCosts[x]++;
        }

        for(int i = 0; i <= len; i++)
        {
            while(sortedCosts[i] > 0 && i <= coins)
            {
                coins -= i;
                count++;
                sortedCosts[i]--;
            }
        }

        return count;

    }
};