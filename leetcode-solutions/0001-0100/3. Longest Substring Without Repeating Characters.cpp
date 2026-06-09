/*
Problem: Longest Substring Without Repeating Characters
Approach: Sliding Window + Hashmap
Time: O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	if(s.size() == 0) return 0;

        int l = 0;
        int r = 0;

        unordered_map<char, int> mp;

        int length = 0;
        int maxLength = 0;
        const int n = s.size();

        while(r < n)
        {
        	if(mp.find(s[r]) == mp.end() || mp[s[r]] == 0)
        	{
        		mp[s[r]]++;
        		r++;
        		length++;
        		if(length > maxLength) maxLength = length;
        	} else
        	{
        		while(mp[s[r]] > 0)
        		{
                    mp[s[l]]--;
        			l++;
        			length--;
        		}
        	}
        }

        return maxLength;
    }
};