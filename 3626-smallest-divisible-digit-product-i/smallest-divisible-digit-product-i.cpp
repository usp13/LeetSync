class Solution {
public:

    int digitProduct(long long x) {

        int prod = 1;
        
        while (x > 0) {
            prod *= (x % 10);
            x /= 10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {

        for (int x = n; ; x++) {

            if (digitProduct(x) % t == 0){

                return (int)x;

            }
        }

        return -1;
        
    }
};