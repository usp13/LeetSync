class Solution {
public:
    int minimumPushes(string word) {
        
        // STARTING FROM 2 , UPTIL 9 , we will assign 1-1 letters of the word to all the KEYS, and then add extra letters to the already occupied ones.

        // HASHMAP for storing alphabet frequency 
        
        vector<int> mp(26 , 0 ) ; // frequency of all alphabets

        int ans = 0 ; 

        for( char & ch : word ){
            mp[ch - 'a']++ ;
        }

        // SORT based on Frequency

        sort( mp.begin() , mp.end() , greater<int>()) ; // Descending Order

        for( int i = 0 ; i < 26 ; i++ ){

            int freq = mp[i] ; // freq 

            int press = i/8 + 1 ; // Max no. of keys is 8

            ans += ( press * freq ) ; 

        }

        return ans; 


    }
};