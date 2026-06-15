class Solution {
public:
    void reverseString(vector<char>& s) {

        // TWO POINTER
        int l = 0 ; //leftmost pointer 
        int r = s.size() - 1 ; //rightmost pointed

        while ( l < r ){

            char temp = s[l];

            s[l] = s[r];
            s[r] = temp ;
            
            l++;
            r--;

        }

        
    }
};