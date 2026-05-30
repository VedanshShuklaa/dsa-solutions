/*
Problem: Roman to Integer
Approach: Follow the instructions
Time: O(n) where n is length of string
*/

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int i = 0;
        int L = s.size();

        while(i < L)
        {
            if(i + 1 < L && mp[s[i+1]] > mp[s[i]])
            {
                num += mp[s[i+1]] - mp[s[i]];
                i += 2;
            }
            else
            {
                num += mp[s[i]];
                i++;
            }
        }

        return num;
    }
};