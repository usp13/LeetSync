class Solution {
public:

    string solve( string s , int&k ){
       
        int sum = 0 ; 

        string ans = "" ; 

        for( int i = 0 ; i < s.size() ; i++ ){
            
            if( i != 0 && i % k == 0 ){

                ans += to_string( sum ) ; 

                sum = 0 ; 

            }

            sum += ( s[i] - '0') ; 

        }

        ans += to_string( sum ) ; 

        return ans ; 

    } 
    string digitSum(string s, int k) {

        while( s.size() > k ){ // While the string is greater than k size
            s = solve( s, k ) ; 
        }

        return s ; 
        
    }
};