class Solution {
public:

    struct TrieNode {

        int idx;
        int children[26];

        TrieNode() {
            idx = 0;

            for (int i = 0; i < 26; i++) {
                children[i] = -1;
            }
        }
    };

    vector<TrieNode> trie;

    void insertTrie(int root, int i, vector<string>& wordsContainer) {

        string& word = wordsContainer[i];
        int n = word.length();

        for (int j = n - 1; j >= 0; j--) {

            int chidx = word[j] - 'a';

            if (trie[root].children[chidx] == -1) {

                trie[root].children[chidx] = trie.size();
                trie.push_back(TrieNode());

                trie.back().idx = i;
            }

            root = trie[root].children[chidx];

            if (wordsContainer[trie[root].idx].length() > n) {
                trie[root].idx = i;
            }
        }
    }

    int searchTrie(int root, string& word) {

        int ansidx = trie[root].idx;
        int n = word.length();

        for (int i = n - 1; i >= 0; i--) {

            int chidx = word[i] - 'a';

            if (trie[root].children[chidx] == -1) {
                return ansidx;
            }

            root = trie[root].children[chidx];
            ansidx = trie[root].idx;
        }

        return ansidx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(TrieNode());

        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector<int> ans(n);

        for (int i = 0; i < m; i++) {

            int idx = trie[0].idx;

            if (wordsContainer[idx].length() >
                wordsContainer[i].length()) {

                trie[0].idx = i;
            }

            insertTrie(0, i, wordsContainer);
        }

        for (int i = 0; i < n; i++) {
            ans[i] = searchTrie(0, wordsQuery[i]);
        }

        return ans;
    }
};