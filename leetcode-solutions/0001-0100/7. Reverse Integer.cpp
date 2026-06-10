/*
Problem: Reverse Integer
Approach: Instructions
Time: O(n)
*/

class Solution {
public:
    int reverse(int x) {
        long long result = 0;

        int num = x;
        while(num != 0)
        {
            result += num % 10;
            result *= 10;
            num /= 10;
        }

        result /= 10;

        if ((int)result != result) return 0;
        else return result; 
    }
};