/*
Problem: Valid Paranthesis
Approach: Stack
Time: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack = {};
        unordered_map<char, char> bindings = {};
        bindings['}'] = '{';
        bindings[')'] = '(';
        bindings[']'] = '[';

        for(char c : s) {
            if(c == '{' || c == '[' || c == '(')
            {
                stack.push_back(c);
            } else
            {
                if(stack.empty()) return false;
                if(stack.back() == bindings[c])
                {
                    stack.pop_back();
                } else return false;
            }
        } 

        return stack.empty();
    }
};