
static const long long MOD = 998244353LL;

static inline long long modReduce(__int128 x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return (long long)x;
}

static inline __int128 sum1_range(long long a, long long b) {
    if (a > b) return 0;
    __int128 n = (__int128)b - a + 1;
    return (__int128)(a + b) * n / 2;
}

static inline __int128 sum2_prefix(long long x) {
    if (x <= 0) return 0;
    return (__int128)x * (x + 1) * (2 * x + 1) / 6;
}

static inline __int128 sum2_range(long long a, long long b) {
    if (a > b) return 0;
    return sum2_prefix(b) - sum2_prefix(a - 1);
}

static long long compute_S_L(long long N, long long L) {
    if (L <= 1) return 0;
    long long u = L - 1;
    long long Kmax = (N - 1) / u;
    __int128 triN = (__int128)N * (N + 1) / 2;
    __int128 res = 0;

    for (long long k = 0; k <= Kmax; ++k) {
        long long s = k * u + 1;
        long long e0 = min((k + 1) * u, N);
        if (s > e0) continue;

        long long a1 = s;
        long long b1 = min(e0, N - k);
        if (a1 <= b1) {
            long long n1 = b1 - a1 + 1;
            __int128 sumA  = sum1_range(a1, b1);
            __int128 sumA2 = sum2_range(a1, b1);

            __int128 sum_llp1 = sumA2 + (__int128)(2 * k + 1) * sumA + (__int128)n1 * ((__int128)k * k + k);
            __int128 part1 = (__int128)u * (sum_llp1 / 2);
            __int128 part2 = (__int128)L * ( (__int128)N * sumA - sumA2 - (__int128)k * sumA );
            res += part1 + part2;
        }

        long long a2 = max(s, N - k + 1);
        long long b2 = e0;
        if (a2 <= b2) {
            long long n2 = b2 - a2 + 1;
            res += (__int128)n2 * u * triN;
        }
    }
    return modReduce(res);
}

void solve() {
    int N;
    cin >> N;
    vector<int> P(N + 1);
    for (int i = 1; i <= N; ++i) cin >> P[i];

    vector<char> vis(N + 1, 0);
    vector<long long> cnt(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        if (!vis[i]) {
            int v = i, len = 0;
            while (!vis[v]) {
                vis[v] = 1;
                v = P[v];
                ++len;
            }
            cnt[len]++;
        }
    }

    long long ans = 0;
    for (int L = 2; L <= N; ++L) {
        if (cnt[L] == 0) continue;
        long long SL = compute_S_L(N, L);
        __int128 add = (__int128)(cnt[L] % MOD) * SL % MOD;
        ans += (long long)add;
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans % MOD << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}