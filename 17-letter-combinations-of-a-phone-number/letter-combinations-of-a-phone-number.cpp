class Solution {
public:
 
    void solver( string digits,  string output , int i , vector<string> &ans , string map[]){

        int n = digits.length();

        // Base case
        if( i >= n ){
            ans.push_back(output);
            return  ;
        }

        int num = digits[i] - '0'; //digit[i] gives char and subtracting '0' gives the actual number 
        string value = map[num]; // coresponding number in map. 

        for( int a = 0 ; a < value.length() ; a++){

            output.push_back(value[a]) ;

            solver(digits, output , i + 1 , ans , map);

            output.pop_back(); // removing the number ( Backtraking )
        }



    }
    vector<string> letterCombinations(string digits) {


        vector<string> ans ;

        if( digits.length() == 0 )
        return ans ; //empty

        string output = "" ;

        int i = 0 ;  //index

        string map[10] = {"" ,"", "abc" , "def", "ghi" , "jkl" , "mno", "pqrs" , "tuv" , "wxyz" } ;

        // index as numpad-keys : 0 ,1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9

        solver( digits, output , i , ans , map) ;

        return ans ;


        
    }
};