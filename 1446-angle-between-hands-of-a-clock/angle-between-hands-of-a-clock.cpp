class Solution {
public:
    double angleClock(int hour, int minutes) {

        double minuteangle = ( 6.0 * minutes ) ;
        
        double hourangle = 30.0 * ( hour % 12 ) + ( 0.5 * minutes ) ;

        double anglediff = abs( hourangle - minuteangle ) ; 

        return min( anglediff , 360.0 - anglediff ) ;
        
    }
};