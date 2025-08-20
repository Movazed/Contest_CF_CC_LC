#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

// ----------------------<Aliases & Utilities>----------------------
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RFOR(i,a,b) for(int i=a;i>=b;--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

// ----------------------<Fenwick Tree>-----------------------------
#define DECLARE_FENWICK \
struct Fenwick { \
    int n; vi f; \
    Fenwick(int _n): n(_n), f(n+1,0) {} \
    void add(int i,int v){ while(i<=n) f[i]+=v,i+=i&-i; } \
    int sum(int i){ int s=0; while(i>0) s+=f[i],i-=i&-i; return s; } \
};

DECLARE_FENWICK

// --------------------<Macro Obfuscation Block>---------------------
#define RINP(n,v) int n; cin >> n; vi v(n+1); FOR(i,1,n+1) cin >> v[i];
#define DECL_INV vi invA(n+1), invB(n+1); ll invCount=0;
#define DECL_BITS Fenwick bitR(n), bitL(n);
#define DECL_I int i;
#define PROCESS_INVA i=n; while(i>=1){ invA[i]=bitR.sum(p[i]-1); bitR.add(p[i],1); invCount+=invA[i]; i--; }
#define PROCESS_INVB i=1; while(i<=n){ invB[i]=bitL.sum(n)-bitL.sum(p[i]); bitL.add(p[i],1); i++; }
#define PROCESS_WNEG ll wneg=0; i=1; while(i<=n){ int deg=invA[i]+invB[i]; int w=(n-i)-deg; wneg+=(w<0?w:0); i++; }
#define OUTPUT cout << invCount + wneg << "\n";

#define FULL_BLOCK \
    DECL_I \
    DECL_BITS \
    DECL_INV \
    PROCESS_INVA \
    PROCESS_INVB \
    PROCESS_WNEG \
    OUTPUT

// ------------------------<Solve Function>--------------------------
void solve() {
    RINP(n, p)
    FULL_BLOCK
}

// ---------------------------<Main>---------------------------------
int32_t main() {
    FAST
    int tc; cin >> tc;
    while(tc--) solve();
}
