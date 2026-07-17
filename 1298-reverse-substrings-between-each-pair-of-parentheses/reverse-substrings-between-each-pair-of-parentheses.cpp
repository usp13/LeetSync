class Solution {
public:
    string reverseParentheses(string s) {
    
        // USING STACK BRUTE FORCE
        
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