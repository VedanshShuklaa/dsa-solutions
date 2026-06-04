/*
Problem: Total Waviness of Numbers in Range I
Approach: Brute Force
Time: O(n*d) where n is num2 - num1 and d is digits in num2
*/

class Solution {
public:
    int calcWaviness(int num)
    {
        if(num < 100) return 0;
        vector<int> digits;

        while(num != 0)
        {
            digits.push_back(num%10);
            num /= 10;
        }

        int waviness = 0;

        for(int i = 1; i < digits.size() - 1; i++)
        {
            if(digits[i] > digits[i-1] && digits[i] > digits[i+1]) waviness++;
            else if (digits[i] < digits[i-1] && digits[i] < digits[i+1]) waviness++;
        }

        return waviness;
    }

    int totalWaviness(int num1, int num2) {
        int sum = 0;

        for(int num = num1; num <= num2; num++)
        {
            sum += calcWaviness(num);
        }

        return sum;
    }
};