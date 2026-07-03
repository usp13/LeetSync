class Solution {
public:
    int minFlips(int a, int b, int c) {


        // OR's TIME COMPLEXITY --> O(1)
        int total = 0 ; 
        int x , y , z ;

        for( int i = 0 ; i < 32  ; i++){
            
            x = a&(1<<i);//upermost number's ith bit (A)
            y = b&(1<<i);// lowermost number's ith bit (B)
            z = c&(1<<i); // answer's bit (C)

            if( z == 0  && y == 0 && x!=0)
            total ++;
            else if( z== 0 && x == 0 && y!=0) 
            total ++; 
            else if ( z== 0 && x!= 0 && y!=0)
            total = total + 2 ; //to get a zero , both bit should be zero 
            else if( z!= 0 && x==0 && y==0)
            total ++;
        }
        return total ;
    }
};