/*
Problem: Letter Combinations of a Phone Number
Approach: Backtracking
Time: O(2^n)
*/

void generateCombinations(string digits, string combination, vector<string>& combinations, int i, vector<string>& mapping)
{
    if(i == digits.size())
    {
        combinations.push_back(combination);
        return;
    }

    int digit = digits[i] - '0';

    string letters = mapping[digit];

    for(int j = 0; j < letters.size(); j++)
    {
        combination.push_back(letters[j]);  // pick one of the letters from all possible combinations (i.e for 2 it's either 'a', 'b', or 'c')

        generateCombinations(digits, combination, combinations, i+1, mapping);  // generate further combinations

        combination.pop_back(); // backtrack, and go onto the next letter (i.e if we picked 'a', now we pick 'b')
    }
}


class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if(digits.empty()) return {};

        vector<string> mapping = {
            "",     
            "",     
            "abc",  
            "def",  
            "ghi",  
            "jkl",  
            "mno",  
            "pqrs", 
            "tuv",  
            "wxyz"  
        };

        vector<string> combinations = {};
        string combination = "";

        generateCombinations(digits, combination, combinations, 0, mapping);

        return combinations;
    }
};