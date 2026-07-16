class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // x + y = Target 
        // y = target - x

        int  n = nums.size();

        unordered_map<int , int> map1 ;

        for ( int i = 0 ; i < n ; ++i){

            int x = nums[i];
            int y = target - x ;

            auto it = map1.find(y);
            if ( it != map1.end()){
                return {it -> second , i};

            }
            
            map1[x] = i ;
        } 

        return {};

    }
};