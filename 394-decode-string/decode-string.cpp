class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string currentString = "";
        int currentNumber = 0;

        for (char ch : s) {
            
            if (isdigit(ch)) {
                currentNumber = currentNumber * 10 + (ch - '0');
            }
            else if (ch == '[') {
                countStack.push(currentNumber);
                stringStack.push(currentString);

                currentNumber = 0;
                currentString = "";
            }
            else if (ch == ']') {
                int repeat = countStack.top();
                countStack.pop();

                string prevString = stringStack.top();
                stringStack.pop();

                string temp = prevString;
                for (int i = 0; i < repeat; i++) {
                    temp += currentString;
                }

                currentString = temp;
            }
            else {
                currentString += ch;
            }
        }

        return currentString;
    }
};