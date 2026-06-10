/*
Problem: Palindrome Number
Approach: Follow the instructions
Time: O(d) where d is number of digits in x
*/

long long reverse(int x)
{
    long long y = 0;

    while(x)
    {
        y = y * 10 + x % 10;
        x /= 10;
    }

    return y;
}

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        long long y = reverse(x);
        return x == y;
    }
};