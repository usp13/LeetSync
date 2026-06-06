class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size() ; 

        // int p = profits.size() ; 
        // int c = capital.size() ; 

        // Choose that project , ehich gives the maximum profit !!!

        vector<pair<int,int>> arr( n ) ;// Vector storing all the pairs of profits and capital

        for( int i = 0 ; i < n ; i++ ){
            arr[i] = { capital[i] , profits[i] } ; 
        }

        sort( arr.begin() , arr.end() ) ; // By default sort based on the first componenet , i.e Capital[i]


        // MAX HEAP -> PRIORITY QUEUE

        priority_queue<int> pq ; 
       
        int i = 0 ; // Index 

        while( k -- > 0 ){

            while( i < n && arr[i].first <= w ){ // When capital needed is lest that company's capital (W)

                pq.push( arr[i].second ) ; // Push the profit 
                i++ ;

            }

            if( pq.empty() ){
                break ; // WHEN all priority queuw is over
            }


            w += pq.top() ; // Add the profit to the company's fina capital
           
            pq.pop() ; 
        }

        return w ; 

        
    }
};