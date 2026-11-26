class Solution {
public:
    bool canAliceWin(int n) {

        if (n < 10) return false; // base case 

        n -= 10; // first Alice removes 

        int stones = 9; // stones Bob will need to remove

        while (n >= stones) {

            n -= stones;

            stones--;
        }

        return stones % 2 == 1 ;
    }
};