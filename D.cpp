#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        ll k;
        cin >> n >> m >> k;
        vector<vector<ll>> grid(n, vector<ll>(m));
        for(auto &row: grid) for(auto &x: row) cin >> x;
        // Initialize DP arrays
        vector<vector<ll>> dp_prev(m, vector<ll>(m, INF));
        vector<vector<ll>> dp_current(m, vector<ll>(m, INF));
        // Process first row
        for(int s=0; s<m; s++){
            dp_prev[0][s] = k * s + grid[0][(0 + s) % m];
        }
        for(int j=1; j<m; j++){
            for(int s=0; s<m; s++){
                if(dp_prev[j-1][s] + grid[0][(j + s) % m] < dp_prev[j][s]){
                    dp_prev[j][s] = dp_prev[j-1][s] + grid[0][(j + s) % m];
                }
            }
        }
        // Process remaining rows
        for(int i=1; i<n; i++){
            // Reset dp_current
            for(int j=0; j<m; j++) fill(dp_current[j].begin(), dp_current[j].end(), INF);
            // Precompute min_prev for each column
            vector<ll> min_prev(m, INF);
            for(int j=0; j<m; j++) {
                for(int s_prev=0; s_prev<m; s_prev++) {
                    if(dp_prev[j][s_prev] < min_prev[j]){
                        min_prev[j] = dp_prev[j][s_prev];
                    }
                }
            }
            for(int s=0; s<m; s++){
                for(int j=0; j<m; j++){
                    ll cell_val = grid[i][(j + s) % m];
                    if(j ==0){
                        // Coming from above
                        ll cost = min_prev[j] + k * s + cell_val;
                        if(cost < dp_current[j][s]){
                            dp_current[j][s] = cost;
                        }
                    }
                    else{
                        // Coming from above
                        ll cost_from_above = min_prev[j] + k * s + cell_val;
                        // Coming from left
                        ll cost_from_left = dp_current[j-1][s] + cell_val;
                        dp_current[j][s] = min(dp_current[j][s], min(cost_from_above, cost_from_left));
                    }
                }
            }
            // Swap dp_prev and dp_current
            dp_prev.swap(dp_current);
        }
        // Find the minimum cost at the bottom-right cell
        ll answer = INF;
        for(int s=0; s<m; s++) answer = min(answer, dp_prev[m-1][s]);
        cout << answer << "\n";
    }
}