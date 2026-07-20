class Solution {
public:

/*  "+" -> [](int a, int b){ return a+b; },
    "-" -> [](int a, int b){ return a-b; },
    "*" -> [](int a, int b){ return a*b; },
    "/" -> [](int a, int b){ return a/b; }*/


    int evalRPN(vector<string>& tokens) {

        // LAMDA FUNCTION 
        unordered_map<string, function<int(int,int)>> op = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };

        stack<int> st;

        for (string &t : tokens) {

            if (op.count(t)) { // operator

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                st.push(op[t](a, b));
            }
            else { // number
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};