class Solution {
public:
    string reverseParentheses(string s) {
    
        // USEINGSTACK BRUTE FORCE

        int n = s.length() ;
        string ans = "" ; 
        stack<int> lastskip ; // stores length of elements before the closing bracket

        for( char &ch : s ){

            if( ch == '('){ // Opening bracket
                lastskip.push( ans.length()) ; 
            }
            else if( ch == ')' ){ // Closing bracket
                int l = lastskip.top() ;
                lastskip.pop() ; 
                reverse( ans.begin() + l , ans.end() ) ; // reverse all elements between two valid brackets 
            }
            else {
                ans.push_back( ch ) ; 
            }
        }

        return ans ; 
    }
};