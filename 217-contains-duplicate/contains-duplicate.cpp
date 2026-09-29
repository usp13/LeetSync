class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> st ; 

        for( int i : nums ){

            if( st.count(i) ){  // yes duplicate is there
                return true ;
            }

            st.insert(i) ; // Insert in the set 
        }

        return false ; 
        
    }
};