class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        

        int maxi = *max_element( nums.begin() , nums.end()) ; 

        vector<long long> freq( maxi + 1 , 0) ;
        for( int i : nums ){
            freq[i]++ ; 
        }

        vector<long long> dcount( maxi + 1 , 0 ) ; 
        for( int i = 1 ; i <= maxi ; i++ ){
            for( int j = i ; j <= maxi ; j +=i ){
                dcount[i] += freq[j] ; 
            }
        }

        vector<long long> exact( maxi+1 , 0 ) ; 

        for( int i = maxi ; i >= 1 ; i-- ){
            exact[i] = dcount[i]*(dcount[i] - 1 )/2 ; 

            for( int m = 2*i ; m <= maxi ; m += i ){
                exact[i] -= exact[m] ; 
            }
        }

        vector<long long> prefix( maxi+1 , 0 ) ; 
        for( int i = 1 ; i <= maxi ; i++ ){
            prefix[i] = prefix[i-1] + exact[i] ; 
        }

        vector<int> ans ; 

        for( auto q : queries ){

            int g = lower_bound( prefix.begin() + 1 , prefix.end() , q + 1 ) - prefix.begin() ; 

            ans.push_back(g) ; 

        }

        return ans ; 




    }
};