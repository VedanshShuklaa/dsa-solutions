/*
Problem: Evaluate Reverse Polish Notation
Approach: Stack
Time: O(n)
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string s : tokens)
        {
            if(s == "+")
            {
                int num2 = stoi(st.top());
                st.pop();
                int num1 = stoi(st.top());
                st.pop();

                st.push(to_string(num1 + num2));
            } else if (s == "-")
            {
                int num2 = stoi(st.top());
                st.pop();
                int num1 = stoi(st.top());
                st.pop();

                st.push(to_string(num1 - num2));
            } else if (s == "*")
            {
                int num2 = stoi(st.top());
                st.pop();
                int num1 = stoi(st.top());
                st.pop();

                st.push(to_string(num1 * num2));
            } else if (s == "/")
            {
                int num2 = stoi(st.top());
                st.pop();
                int num1 = stoi(st.top());
                st.pop();

                st.push(to_string(num1 / num2));
            } else
            {
                st.push(s);
            }
        }

        return stoi(st.top());
    }
};