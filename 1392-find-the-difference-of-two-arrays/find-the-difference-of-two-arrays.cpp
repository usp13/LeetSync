class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> ans ; 

        //HASHMAP 
        map<int,int> mp1 ;
        map<int,int> mp2 ;

        for( auto i : nums1 ){
            mp1[i]++ ;
        }
        for( auto i : nums2 ){
            mp2[i]++ ;
        }

        // SET
        set<int> s1 ; 
      
        for( auto i : nums1 ){
            if( mp1[i] > 0 && mp2.count(i) == 0 ){
                s1.insert(i) ; 
            }
        }

        
        set<int> s2 ; 
       
        for( auto i : nums2 ){
            if( mp2[i] > 0 && mp1.count(i) == 0 ){
                s2.insert(i) ; 
            }
        }

        // VECTOR
        vector<int> temp1 ; 
        vector<int> temp2 ; 

        for( auto i : s1 ){
            temp1.push_back(i) ;
        }
        for( auto i : s2 ){
            temp2.push_back(i) ;
        }


        ans.push_back( temp1 ) ; 
        ans.push_back( temp2 ) ; 


        return ans ; 


        
    }
};