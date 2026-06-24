class Solution {
public:
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();

        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {

                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {

                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {

        int n = base.size();

        Matrix result(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }

        while (exp) {

            if (exp & 1) {
                result = multiply(result, base);
            }

            base = multiply(base, base);

            exp >>= 1;
        }

        return result;
    }

    vector<long long> multiplyMatrixVector(
        const Matrix& A,
        const vector<long long>& v
    ) {
        int n = A.size();

        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {

            long long cur = 0;

            for (int j = 0; j < n; j++) {

                cur = (cur + A[i][j] * v[j]) % MOD;
            }

            res[i] = cur;
        }

        return res;
    }

    int zigZagArrays(long long n, int l, int r) {

        int m = r - l + 1;

        if (n == 1) return m;

        int SZ = 2 * m;

        Matrix T(SZ, vector<long long>(SZ, 0));

        // up[y] = sum down[x] for x < y
        for (int y = 0; y < m; y++) {

            for (int x = 0; x < y; x++) {

                T[y][m + x] = 1;
            }
        }

        // down[y] = sum up[x] for x > y
        for (int y = 0; y < m; y++) {

            for (int x = y + 1; x < m; x++) {

                T[m + y][x] = 1;
            }
        }

        // Build S(2)
        vector<long long> base(SZ, 0);

        for (int y = 0; y < m; y++) {

            base[y] = y;               // up[2][y]

            base[m + y] = m - 1 - y;  // down[2][y]
        }

        if (n == 2) {

            long long ans = 0;

            for (long long x : base) {
                ans = (ans + x) % MOD;
            }

            return ans;
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState =
            multiplyMatrixVector(P, base);

        long long ans = 0;

        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};