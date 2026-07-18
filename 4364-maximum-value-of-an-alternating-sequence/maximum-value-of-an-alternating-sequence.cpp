class Solution {
public:
    long long maximumValue(int n, int s, int m) {
      
      
        if (n == 1)  return s;

        long long peaks = (n - 2) / 2;

        return (long long)s + m + peaks * (m - 1LL);
        
    }
};