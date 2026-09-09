class Solution {
public:
    long long countCommas(long long n) {

        long long ans = 0 ; 

        if( n < 1000){ // 10^3
            return 0 ; // no commas before 1000
        }
        
        //10^6
        if(n  < pow(10,6) ){
            ans += ( n - 999 ) ;
            return ans ;
        }
        else {
            ans += (pow(10,6) - pow(10,3)) * 1 ;
        }
        //10^9
         if(n  < pow(10,9) ){
            ans += ( n - pow(10,6) + 1) * 2 ;
            return ans ;
        }
        else {
            ans += (pow(10,9) - pow(10,6)) * 2 ;
        }
        
        //10^12
         if(n  < pow(10,12) ){
            ans += ( n - pow(10,9) + 1) * 3 ;
            return ans ;
        }
        else {
            ans += ( pow(10,12) - pow(10,9)) * 3 ;
        }

        //10^15
        if(n  < pow(10,15) ){
            ans += ( n - pow(10,12) + 1 ) * 4 ;
            return ans ;
        }
        else {
            ans += (pow(10,15) - pow(10,12)) * 4  ;
        }

        // more than 10^15
        
            ans += ( n - pow(10,15) + 1) * 5 ; // 5 commans 
        

        return ans ; 
        
        
    }
};