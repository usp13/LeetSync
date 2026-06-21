class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int K) {

        int INF = 1e9 + 7 ;

        vector<vector<pair<int, int>>> g(n);

        for (auto& e: edges) {

            g[e[0]].push_back({e[1], e[2]});

        }

        vector<vector<int>> dp(n, vector<int>(K+1, INF));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        pq.push({0, 0, 1});
        dp[0][K-1] = 0;

        while (!pq.empty()) {

            auto [d, u, k] = pq.top();
            pq.pop();

            if (d > dp[u][k]) continue;

            if (u == n-1) return d;

            for (auto& [v, w]: g[u]) {

                int newK = (labels[u] == labels[v] ? k+1 : 1);

                if (newK <= K) {

                    if (d + w < dp[v][newK]) {
                        dp[v][newK] = d + w;
                        pq.push({d+w, v, newK});
                    }

                }
            }
        }
        return -1;
    }
};