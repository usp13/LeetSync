class Solution {
public:
    int maximumLengthSubstring(string s) {

        // SLIDING WINDOW

        int answer = 0 ; // length
        int left = 0 ; 
        int freq[26] ; 

        for (int right = 0; right < s.length(); right++) {
            
            // Count the current character
            freq[s[right] - 'a']++;

            // If any character appears more than 2 times,
            // move left until it becomes valid

            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            // Calculate length of current valid substring
            int length = right - left + 1;

            answer = max(answer, length);
        }

        return answer;

        
    }
};