class Solution {
public:
    string simplifyPath(string path) {

        // STACK 
        stack<string> st;
        string token;

        stringstream ss(path);
        //The stringstream class in C++ is a powerful tool that allows you to manipulate strings as if they were streams. It is particularly useful for parsing and formatting strings.

        while (getline(ss, token, '/')) {

            if (token == "" || token == ".") {
                // if empty or in same directory
                continue;
            }

            if (token == "..") {
                if (!st.empty()) {   // check before popping
                    st.pop();
                }
            }
            else {
                st.push(token);
            }
        }

        if (st.empty()) {
            return "/";
        }

        string ans = "";

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            // for keeping in correct order
            st.pop();
        }

        return ans;
    }
};