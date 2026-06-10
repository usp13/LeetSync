class Solution {
public:


string decimalToBinary(int n) {
    if (n == 0) return "0";

    string binary = "";

    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    return binary;
}
    int hammingWeight(int n) {

        //int ans = __builtin_popcount(n);
        int ans = 0 ; 
        string s = decimalToBinary(n) ; 
        
        for( int i = 0 ; i < s.length() ; i++){
            if( s[i] == '1'){
                ans ++ ;
            }
        }
        
        return ans ; 
        
    }
};