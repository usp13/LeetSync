class Solution {
public:
    bool checkValidString(string s) {

        int minOpen = 0;
        int maxOpen = 0;

        for (char ch : s) {

            if (ch == '(') {
                minOpen++;
                maxOpen++;
            }
            else if (ch == ')') {
                minOpen--;
                maxOpen--;
            }
            else { // '*'
                minOpen--;  // * acts as ')'
                maxOpen++;  // * acts as '('
            }

            // Minimum cannot be negative
            if (minOpen < 0) {
                minOpen = 0;
            }

            //  maximum possibility is invalid
            if (maxOpen < 0) {
                return false;
            }
        }

        return minOpen == 0;
    }
};