class RandomizedSet {
public:

    // VECTOR + MAP
    vector<int> v ; 
    unordered_map<int,int> mp ; 

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // if already present in map , false 
        if( mp.find(val) != mp.end()){
            return false ; 
        }

        v.push_back(val) ; // insert 
        mp[val] = v.size() - 1  ;

        return true ;
    }
    
    bool remove(int val) {
        
        // if not present, cannot delete
        if( mp.find(val) == mp.end()){
            return false ; 
        }

        int idx = mp[val] ; 
        int last = v.back() ; // last element
        v.back() = val ; // keep the val at the back

        v[idx] = last ; 
        mp[last] = idx ; 

        v.pop_back() ; // removes the val
        mp.erase(val) ; // erase the val

        return true  ; 
        
    }
    
    int getRandom() {
        
        int n = v.size() ; 

        int random = rand()%n ; // gives random number within the range of array length

        return v[random] ; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */