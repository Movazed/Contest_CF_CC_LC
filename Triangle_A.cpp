#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
        //apply code only the testcase part loop is on the int main function......

        ll a,  b, c, d;

        cin >> a >> b >> c >> d;

        if ((a < b+c && b < a+c && c < a+b) || (a < b+d && b < a+d && d < a+b) || (a < d+c && d < a+c && c < a+d) || (d < b+c && b < d+c && c < d+b))
            cout << "TRIANGLE" << endl;
        else if ((a == b+c || b == a+c || c == a+b) || (a == b+d || b == a+d || d == a+b) || (a == d+c || d == a+c || c == a+d) || (d == b+c || b == d+c || c == d+b))
            cout << "SEGMENT" << endl;
        else
            cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

}