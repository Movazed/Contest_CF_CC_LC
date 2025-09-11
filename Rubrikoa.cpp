#include <bits/stdc++.h>
using namespace std;

class RobustCircularChain {
private:
    int N;
    vector<long long> A;
    vector<bool> tight;
    vector<long long> ans;

    long long gcd(long long a, long long b) {
        a = abs(a);
        b = abs(b);
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void computeTightEdges() {
        tight.clear();
        tight.resize(N, false);
        
        for (int i = 0; i < N; ++i) {
            int j = (i + 1) % N;
            tight[i] = (gcd(A[i], A[j]) > 1);
        }
    }

    void solveForAllK() {
        ans.clear();
        ans.resize(N - 1, 0);

        // Count tight edges
        int tightCount = count(tight.begin(), tight.end(), true);

        // No tight edges
        if (tightCount == 0) {
            fill(ans.begin(), ans.end(), 0);
            return;
        }

        // All edges tight
        if (tightCount == N) {
            for (int s = 1; s < N; ++s) {
                ans[s-1] = (N + s - 1) / s;
            }
            return;
        }

        // Extract runs of tight edges
        vector<int> runs;
        int currentRun = 0;
        
        // Find first non-tight edge to start circular traversal
        int start = 0;
        while (start < N && tight[start]) start++;
        
        for (int step = 0; step < N; ++step) {
            int j = (start + step) % N;
            if (tight[j]) {
                currentRun++;
            } else {
                if (currentRun > 0) {
                    runs.push_back(currentRun);
                    currentRun = 0;
                }
            }
        }
        
        // Add last run if exists
        if (currentRun > 0) {
            runs.push_back(currentRun);
        }

        // Find max run length
        int maxRun = runs.empty() ? 0 : *max_element(runs.begin(), runs.end());
        
        // Frequency of run lengths
        vector<long long> freq(maxRun + 1, 0);
        for (int run : runs) {
            freq[run]++;
        }

        // Prefix sum for efficient range counting
        vector<long long> pref(maxRun + 1, 0);
        for (int i = 1; i <= maxRun; ++i) {
            pref[i] = pref[i-1] + freq[i];
        }

        // Compute cuts for each possible k
        for (int s = 1; s < N; ++s) {
            long long totalCuts = 0;
            
            // For each possible run length quotient
            for (long long q = 1; q * s <= maxRun; ++q) {
                long long low = q * s;
                long long high = min((long long)maxRun, (q + 1) * s - 1);
                
                // Count runs in this length range
                long long runCount = 
                    (high <= maxRun ? pref[high] : pref[maxRun]) - 
                    (low > 1 ? pref[low-1] : 0);
                
                if (runCount > 0) {
                    totalCuts += q * runCount;
                }
            }
            
            ans[s-1] = totalCuts;
        }
    }

public:
    void solve() {
        // Input
        if (!(cin >> N)) return;
        
        // Resize and input
        A.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Compute solution
        computeTightEdges();
        solveForAllK();

        // Output
        for (int i = 0; i < N - 1; ++i) {
            cout << (i ? " " : "") << ans[i];
        }
        cout << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        RobustCircularChain solver;
        solver.solve();
    }

    return 0;
}