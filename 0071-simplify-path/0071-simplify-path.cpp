class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string dir;

        // Split the path by '/'
        while (getline(ss, dir, '/')) {
            if (dir == "" || dir == ".") {
                // Ignore empty strings (caused by consecutive slashes) and current directory '.'
                continue;
            } 
            else if (dir == "..") {
                // Go up one level by popping from the stack, if it's not empty
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } 
            else {
                // It's a valid directory name (including "...", "....", etc.), push it
                stack.push_back(dir);
            }
        }
        string result = "";
        for (const string& s : stack) {
            result += "/" + s;
        }

        // If the stack was empty, return root "/", otherwise return the built string
        return result.empty() ? "/" : result;
    }
};