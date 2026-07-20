class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (int i = 0; i < s.length(); i++) {

            char ch = s[i];

            // Opening bracket
            if (ch == '(' || ch == '[' || ch == '{') {

                st.push(ch);
            }
            else {

                // No matching opening bracket
                if (st.empty()) {
                    return false;
                }

                char top = st.top();

                // Valid matching pair
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // All brackets should be matched
        return st.empty();
    }
};