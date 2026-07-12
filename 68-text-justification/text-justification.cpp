class Solution {
public:

int maxw ; 

    // string findline( int i , int j , int eachholespace , int extraholes , vector<string>& words ){
        
    // }
    string findline(int i, int j, int eachholespace, int extraholes, vector<string>& words) {

    string line = "";

    // Last line -> left justified
    if (j == words.size()) {

        for (int k = i; k < j; k++) {

            line += words[k];

            if (k != j - 1)
                line += " ";
        }

        while (line.length() < maxw)
            line += " ";

        return line;
    }

    // Only one word
    if (j - i == 1) {

        line += words[i];

        while (line.length() < maxw)
            line += " ";

        return line;
    }

    // Fully justified line
    for (int k = i; k < j; k++) {

        line += words[k];

        if (k != j - 1) {

            int spaces = eachholespace;

            if (extraholes > 0) {
                spaces++;
                extraholes--;
            }

            line += string(spaces, ' ');
        }
    }

    return line;
}

    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans ; 
        int n = words.size() ; 

        maxw = maxWidth ; 

        int i = 0 ; 

        while( i < n ){

            int lettercount = words[i].length() ; 
            int j = i + 1 ; 
            int holes = 0 ; 

            while( j < n && words[j].length() + 1 + holes + lettercount <= maxWidth ){

                lettercount += words[j].length() ; 
                holes += 1 ; 
                j++ ; 

            }

            int remholes = maxWidth - lettercount ; 

            int eachholespace = holes == 0 ? 0 : remholes / holes ; 

            int extraholes = holes == 0 ? 0 : remholes % holes ; 

            if( j == n ){
                eachholespace = 1 ; 
                extraholes = 0 ; 
            }

            ans.push_back( findline( i , j , eachholespace , extraholes , words )) ; 

            i = j ; 

        }

        return ans ; 
        
    }
};