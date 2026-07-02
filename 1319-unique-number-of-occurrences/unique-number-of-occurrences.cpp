class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

    unordered_map<int,int> mp  ;

    for( auto &i : arr ){
        mp[i] ++ ;
    }

    unordered_set<int> st  ;

     for( auto &it : mp ){
        
        int freq = it.second ; // it.first is number
        
        if( st.find(freq) != st.end()){
            return false ;
        }

        st.insert(freq) ;
    }

    return true ;

        
    }
};