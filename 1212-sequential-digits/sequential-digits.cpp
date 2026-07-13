class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        //QUEUE
        queue<int> q ; 

        for( int i = 1 ; i <= 8 ; i++ ){
            q.push(i) ; 
        }

        vector<int> ans ; 

        while( !q.empty() ){

            int temp = q.front() ; 
            q.pop() ; 

            if( temp >= low && temp <= high ){
                ans.push_back( temp ) ; 
            }

            int lastdigit = temp%10 ; // last digit of the number 
            
            if( lastdigit + 1 <= 9 ){
                q.push(temp*10 + (lastdigit + 1 ) ) ; 
            }
        }

        return ans ; 


        
    }
};