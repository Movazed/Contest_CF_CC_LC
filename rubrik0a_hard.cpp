#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;
static inline size_t IDX(int i, int j, int n) {
    return static_cast<size_t>(i) * n + j;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    if (!(std::cin >> s)) return 0;
    int n = static_cast<int>(s.size());

    // 1D flattening to reduce overhead from vector-of-vectors
    std::vector<unsigned char> pal(static_cast<size_t>(n) * n, 0);
    std::vector<int> cnt(static_cast<size_t>(n) * n, 0);

    // Palindrome table
    for (int i = 0; i < n; ++i) pal[IDX(i, i, n)] = 1;
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            if (s[l] == s[r]) {
                if (len == 2 || pal[IDX(l + 1, r - 1, n)])
                    pal[IDX(l, r, n)] = 1;
            }
        }
    }

    // Count DP
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            int a = (l + 1 <= r) ? cnt[IDX(l + 1, r, n)] : 0;
            int b = (l <= r - 1) ? cnt[IDX(l, r - 1, n)] : 0;
            int c = (l + 1 <= r - 1) ? cnt[IDX(l + 1, r - 1, n)] : 0;
            cnt[IDX(l, r, n)] = a + b - c + (pal[IDX(l, r, n)] ? 1 : 0);
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        int l, r; // 1-based in input
        std::cin >> l >> r;
        --l; --r; // to 0-based
        std::cout << cnt[IDX(l, r, n)] << '\n';
    }
    return 0;
}