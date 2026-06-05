class Solution {
public:
    int minimumPushes(string word) {
        

        int n = word.size() ; 
        // STARTING FROM 2 , UPTIL 9 , we will assign 1-1 letters of the word to all the KEYS, and then add extra letters to the already occupied ones.

        unordered_map<int,int> mp ;
        int ans = 0 ; 

        int key = 2 ; // Default starting value

        for( char &ch : word ){

            if( key > 9 ){ // when all keys are given 
                key = 2 ; 
            }

            mp[key]++  ;

            ans += mp[key] ; 

            key++ ; 
        } 

        return ans ; 


    }
};