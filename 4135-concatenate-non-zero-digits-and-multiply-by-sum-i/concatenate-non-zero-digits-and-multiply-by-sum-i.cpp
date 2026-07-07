class Solution {
public:
    long long sumAndMultiply(int n) {

        string s = to_string(n) ;
        string t = "";

        int sum = 0 ; 

        for( auto &num : s ){

            if( num == '0') continue ;

            t.push_back(num) ;

            sum += ( num - '0' )  ;
            
        }

        long long ans = ( ( t == "") ? 0 : stoll(t) ) ;
        //string to LONG LONG

        ans *= sum ;

        return ans ;
        
    }
};