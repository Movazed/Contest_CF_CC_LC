#include <bits/stdc++.h>

using namespace std;

// DSU structure to manage merging danger intervals
struct DSU {
    vector<int> parent;
    vector<int> min_b_idx; // Index in B of the leftmost spike in this component
    vector<int> max_b_idx; // Index in B of the rightmost spike in this component
    vector<int> idx_A_L;   // Index in A of the closest alive robot to the left
    vector<int> idx_A_R;   // Index in A of the closest alive robot to the right

    DSU(int m, const vector<int>& A, const vector<int>& B) {
        parent.resize(m);
        min_b_idx.resize(m);
        max_b_idx.resize(m);
        idx_A_L.resize(m);
        idx_A_R.resize(m);
        
        for (int i = 0; i < m; ++i) {
            parent[i] = i;
            min_b_idx[i] = i;
            max_b_idx[i] = i;
            
            // Find initial neighbors in sorted array A
            // idx_A_L: index of largest element < B[i]
            auto it = lower_bound(A.begin(), A.end(), B[i]);
            idx_A_L[i] = (int)(it - A.begin()) - 1;
            
            // idx_A_R: index of smallest element > B[i]
            idx_A_R[i] = (int)(it - A.begin());
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j, long long& total_dead) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            long long dead_i = max(0, idx_A_R[root_i] - idx_A_L[root_i] - 1);
            long long dead_j = max(0, idx_A_R[root_j] - idx_A_L[root_j] - 1);
            parent[root_j] = root_i;
            if (min_b_idx[root_i] < min_b_idx[root_j]) {
                // i is Left, j is Right
                max_b_idx[root_i] = max_b_idx[root_j]; // Extend right spike boundary
                idx_A_R[root_i] = idx_A_R[root_j];     // Use Right's right robot boundary
            } else {
                // j is Left, i is Right
                min_b_idx[root_i] = min_b_idx[root_j]; // Extend left spike boundary
                idx_A_L[root_i] = idx_A_L[root_j];     // Use Left's left robot boundary
                // idx_A_R remains from i
            }

            // Calculate new dead count for the merged component
            long long new_dead = max(0, idx_A_R[root_i] - idx_A_L[root_i] - 1);
            
            // Update global total: remove old counts, add new count
            total_dead += (new_dead - dead_i - dead_j);
            return true;
        }
        return false;
    }
};

struct MergeEvent {
    long long cost;
    int u, v; // Spike indices
    bool operator>(const MergeEvent& other) const {
        return cost > other.cost;
    }
};

struct KillEvent {
    long long cost;
    int spike_idx; // The specific spike index defining this boundary
    int robot_idx; // The specific robot index targeted
    bool operator>(const KillEvent& other) const {
        return cost > other.cost;
    }
};

void solve() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    string s;
    cin >> s;

    // Sorting is crucial for the logic
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    DSU dsu(m, a, b);
    long long total_dead = 0;


    priority_queue<MergeEvent, vector<MergeEvent>, greater<MergeEvent>> pq_merge;
    priority_queue<KillEvent, vector<KillEvent>, greater<KillEvent>> pq_left;
    priority_queue<KillEvent, vector<KillEvent>, greater<KillEvent>> pq_right;

    for (int i = 0; i < m - 1; ++i) {
        pq_merge.push({(long long)b[i+1] - b[i], i, i+1});
    }


    for (int i = 0; i < m; ++i) {
        int l_idx = dsu.idx_A_L[i];
        if (l_idx >= 0) {
            pq_left.push({(long long)b[i] - a[l_idx], i, l_idx});
        }
        int r_idx = dsu.idx_A_R[i];
        if (r_idx < n) {
            pq_right.push({(long long)a[r_idx] - b[i], i, r_idx});
        }
    }

    long long current_disp = 0;
    long long min_disp = 0;
    long long max_disp = 0;
    long long R = 0; 
    long long disp_R = 0; 

    for (char move : s) {
        if (move == 'L') current_disp--;
        else current_disp++;

        min_disp = min(min_disp, current_disp);
        max_disp = max(max_disp, current_disp);

        R = max_disp;
        disp_R = -min_disp;
        long long current_width = R + disp_R;

        while (!pq_merge.empty() && pq_merge.top().cost <= current_width) {
            auto ev = pq_merge.top();
            pq_merge.pop();
            dsu.unite(ev.u, ev.v, total_dead);
        }
        while (!pq_left.empty() && pq_left.top().cost <= R) {
            auto ev = pq_left.top();
            pq_left.pop();
            int root = dsu.find(ev.spike_idx);
            if (dsu.min_b_idx[root] == ev.spike_idx && dsu.idx_A_L[root] == ev.robot_idx) {
                total_dead++; 
                dsu.idx_A_L[root]--; 
                int next_idx = dsu.idx_A_L[root];
                if (next_idx >= 0) {
                    pq_left.push({(long long)b[ev.spike_idx] - a[next_idx], ev.spike_idx, next_idx});
                }
            }
        }

        // 3. Process Right Kills (Danger zone expands Right when disp_R increases)
        // Condition: a - b <= disp_R => a <= b + disp_R
        while (!pq_right.empty() && pq_right.top().cost <= disp_R) {
            auto ev = pq_right.top();
            pq_right.pop();
            
            int root = dsu.find(ev.spike_idx);
            
            // Validation: Event is valid only if this spike is still the Right boundary
            if (dsu.max_b_idx[root] == ev.spike_idx && dsu.idx_A_R[root] == ev.robot_idx) {
                total_dead++;
                dsu.idx_A_R[root]++; // Expand boundary to the right
                
                int next_idx = dsu.idx_A_R[root];
                if (next_idx < n) {
                    pq_right.push({(long long)a[next_idx] - b[ev.spike_idx], ev.spike_idx, next_idx});
                }
            }
        }

        cout << n - total_dead << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}