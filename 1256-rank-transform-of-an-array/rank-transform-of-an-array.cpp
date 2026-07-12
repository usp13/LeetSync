class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size() ; 
        vector<int> temp = arr ; 

        map<int,int> mp ; 

        sort( temp.begin() , temp.end() ) ; 

        int rank = 1; // Rank starts from 1 

        for( int i = 0 ; i < n ; i++ ){

            if( !mp.count(temp[i]) ){

                mp[temp[i]] = rank ;
                rank++ ; 

            }
        }

        for( int i = 0 ; i < n ; i++ ){
            arr[i] = mp[arr[i]] ;
        }

        return arr ; 
    }
};