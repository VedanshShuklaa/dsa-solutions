/*
Problem: Destroying Asteroids
Approach: Greedy
Time: O(nlogn)
*/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long massll = mass;
        for(int m : asteroids)
        {
            if(m <= massll) massll += m;
            else return false;
        }
        return true;
    }
};