class Solution {
public:
    string processStr(string s) {

        string result ;
        int n = s.length();

        for( int i = 0 ; i < n ; i++){

            if(s[i] == '*'){
                if(result != "")
                result.pop_back(); //A '*' removes the last character from result, if it exists.
            }
            else if(s[i] == '#'){ //A '#' duplicates the current result and appends it to itself.
                result += result ;
            }
            else if(s[i] == '%'){ //A '%' reverses the current result.
                reverse(result.begin(), result.end());
            }
            else {   //GIVEN ITS LOWERCASE : If the letter is a lowercase English letter append it to result.
                result += s[i] ;
            }
        }

    return result;
    }
};