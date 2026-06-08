class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size() ; 

        if( n % groupSize != 0 ){ // If not divisible by groupsize
            return false ; 
        } 

        map<int,int> mp ; // ordered MAP -> Stored in sorted manner 

        for( int i = 0 ; i < n ; i++ ){
            mp[hand[i]] ++ ; 
        }

        while ( !mp.empty() ){

            int curr = mp.begin()-> first ; // first -> element , second -> freq

            for( int i = 0 ; i < groupSize ; i++ ){
                
                if( mp[curr + i ] == 0 ){ // consequtive number not present , then return false 
                    return false ; 

                }

                mp[ curr + i ] -- ; // ipdate the frequency 

                if( mp[curr + i ] < 1 ){
                    mp.erase( curr+i) ; 
                }
            }
        }

        return true ;
        
    }
};