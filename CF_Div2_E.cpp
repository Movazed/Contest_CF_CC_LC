//  Interactive RBS (easy version) – offline / hack solution
//  ---------------------------------------------------------
//  In hacking mode the whole sequence is given on input.
//  So we simply read it and print it.
//
//  Author: your_name

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;                          // number of test cases
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;                      // length of the sequence (unused afterwards)
        string s;                   // the bracket sequence itself
        cin >> n >> s;
        cout << s << '\n';          // output the sequence
    }
    return 0;
}