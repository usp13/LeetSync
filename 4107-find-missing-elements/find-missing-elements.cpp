class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int n = nums.size();
        int mini =  INT_MAX ;
        int maxi = INT_MIN ;

        unordered_set<int> s;
        vector<int> ans ;
        
        for(auto i : nums){
            mini = min( mini , i);
            maxi = max( maxi , i);
            s.insert(i);
            
        }

        for( int i = mini ; i < maxi ; i++){
            if( s.find(i) == s.end()){
                ans.push_back(i) ;
            }
        }
        return ans ;
    }
};