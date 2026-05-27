/*
Problem: Simplify Path
Approach: Stack
Time: O(n)
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack = {};

        if(path.size() == 1) return "/";

        for(int i = 1; i < path.size(); i++)
        {
            if(path[i] == '/') continue;

            string dirName = "";

            while(i < path.size() && path[i] != '/')
            {
                dirName.push_back(path[i]);
                i++;
            }

            if(dirName == ".")
            {
                continue;
            }
            else if(dirName == "..")
            {
                if(!stack.empty())
                {
                    stack.pop_back();
                }
            }
            else
            {
                stack.push_back(dirName);
            }
        }

        string newPath = "";

        for(string dir : stack)
        {
            newPath += "/";
            newPath += dir;
        }

        if(stack.empty()) return "/";

        return newPath;
    }
};