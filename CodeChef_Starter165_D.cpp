#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs_stable_time(vector<int>& A, int N) {
    vector<int> level(N, 0);
    queue<pair<int, int>> q;

    for (int i = 0; i < N - 1; ++i) {
        if (A[i] < A[i + 1]) {
            q.push({i + 1, 0});
        }
    }

    int lvl = 0;
    while (!q.empty()) {
        pair<int, int> front = q.front();
        int idx = front.first;
        int l = front.second;
        q.pop();
        
        if (idx > 0 && A[idx - 1] < A[idx]) {
            A[idx - 1] = A[idx];
            q.push({idx - 1, l + 1});
        }
        lvl = max(lvl, l);
    }

    return lvl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        int result = bfs_stable_time(A, N);
        cout << result << "\n";
    }

    return 0;
}
