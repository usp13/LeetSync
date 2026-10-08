class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string ans ; 
        int level = 0 ; 

        for( auto &ch : s ){
            if( ( ch == '(' && level++ ) || ( ch == ')' && --level ) ){
                ans += ch ; 
            }
        }

        return ans ; 
    }
};