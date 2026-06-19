/*
Problem: Find the Highest Altitude
Approach: Traversal
Time: O(N)
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int alt = 0;
        for (int g : gain)
        {
            alt += g;
            if (alt > highest) highest = alt;
        }

        return highest;
    }
};