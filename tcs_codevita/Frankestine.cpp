#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long
#define sz(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()

map<string, vector<vector<string>>> r;
map<string, int> m;

inline int calc(const string &x){
if(m.count(x)) return m[x];if(!r.count(x)) return m[x]=0;
int mc=LLONG_MAX;
auto &recipes=r[x];
int n=sz(recipes);
for(int i=0;i<n;i++){
int cc=(sz(recipes[i])>1?sz(recipes[i])-1:0);
auto &ing=recipes[i];
int m_=sz(ing);
for(int j=0;j<m_;j++) cc+=calc(ing[j]);
mc=min(mc,cc);
}return m[x]=mc;}

inline void solve(){
r.clear(); m.clear();int n; cin>>n;while(n--){
string line; cin>>line;
size_t p=line.find('=');string pot=line.substr(0,p), ing=line.substr(p+1);
vector<string> v; string x; stringstream ss(ing);while(getline(ss,x,'+')) v.pb(x);r[pot].pb(v);
}
string t; cin>>t;
cout<<calc(t)<<endl;
}

int32_t main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
solve();
}
