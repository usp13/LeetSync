class Solution {
public:
    int minimumCost(vector<int>& cost) {


        // USP
        int n = cost.size() ; 

        sort( cost.begin() , cost.end(), greater<int>()) ; 
        // SORTING -> We will take 2 candies of maximum value, and take the third candie for free. We will divide the sorted array into subarray of three, and will take the 3rd one for free.

        int sum = 0  ; // Sum of Prices of candies

        for( int i = 0 ; i < n ; i++ ){
            
            if( i % 3 == 0 || i % 3 == 1 ){ // count the first and second candies into the sum 
            //( i%3 = 0 is first candie , and i%3 = 1 is second candie )
                sum += cost[i] ; 
            }
            else { // Ingore the last candie ( i%3 == 2 -> third candie )
                continue ; 
            }
        }

        return sum ; 
        
    }
};