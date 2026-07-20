class Solution {
public:
    bool wordPattern(string pattern, string s) {

        int p1 = pattern.length() ;
        int s1 = s.length() ;

       
        vector<string> words ;
        string token ; 
        stringstream ss(s) ;
        
        int count = 0 ; // word count 

        // count no. of words in string s 
        while( getline(ss , token, ' ')){
            words.push_back(token) ;
            count++ ;
        }


        if( p1 !=  count) return false ;

        unordered_map<string, char> mp ; 
        set<char> used ; //used char for a string 

        for( int i = 0 ; i < p1 ; i++){

            string word = words[i] ; 
            char ch = pattern[i] ;

           if (mp.find(word) == mp.end() && used.find(ch) == used.end()){
                used.insert( ch ) ;
                mp[word] = ch ; 
            }
            else if( mp[word] != pattern[i]) {
               return false ;

            }
        }

        return true ;
        
    }
};