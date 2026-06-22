class Solution {
public:

    bool hasDuplicate(string s1 ,string s2){

        int freq[26] = {0} ;

        for( char &ch : s1 ){

            if( freq[ch - 'a'] > 0 ){ // Duplicate in s1 string itself
                return true ; // TRUE -> has duplicate 
            }

            freq[ch - 'a' ]++ ;
        }

        for( char &ch : s2 ){

            if( freq[ch - 'a'] > 0 ){ // Duplicate in s1 & s2 string 
              return true ; // TRUE -> has duplicate 
            }

        }

        return false ; // No duplicate found

    }

    // Acts as DP 
    unordered_map<string,int> mp  ; 

    int solve(vector<string>& arr , string temp , int i , int n ){

        // DP : Normal Recursion + Memoisation

        if( i >=  n ){
            return temp.length() ; 
        }

        int take = 0 ; 
        int nottake = 0 ; 

        if( mp.find(temp) != mp.end() ){ // if stored , return it
            return mp[temp] ; 
        }


        if( hasDuplicate( arr[i] , temp) ) { // If has duplicate , go for nottake part only

            nottake = solve( arr , temp , i+1 , n ) ; 

        }
        else { // Two possibilities

            nottake = solve( arr , temp , i+1 , n ) ; 
            take = solve( arr , temp + arr[i] , i+1 , n ) ; 
        }

        return mp[temp] = max( take , nottake ) ; // update it in MAP

    }

    int maxLength(vector<string>& arr) {

        int n = arr.size()  ;

        string temp = "" ; 

        int i = 0 ; 

        return solve( arr , temp , i ,  n ) ; 

    }


        
    
};