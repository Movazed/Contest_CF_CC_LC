#include <bits/stdc++.h>
using namespace std;

// Macros for loops, containers, pairs, etc.
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int,int>
#define pdi pair<int,double>
#define vec vector
#define vi vec<int>
#define vvi vec<vi>
#define vvd vec<vec<double>>
#define vpii vec<pii>
#define vpd vec<pdi>
#define INF 1e9
#define EPS 1e-9

// Check grid bounds
#define valid(r,c,n) (r>=0 && r<n && c>=0 && c<n)

// Direction arrays
#define DR {-1,1,0,0}
#define DC {0,0,-1,1}
#define DIR {'|','|','-','-'}

int main(){
    FAST
    int n; cin >> n;
    vec<string> g(n); rep(i,n) cin >> g[i];

    map<pii,int> cell2node;
    vpii node2cell;
    int start=-1,end=-1;

    // Nodes
    rep(i,n) rep(j,n){
        if(g[i][j]=='+'||g[i][j]=='.'){
            int id=sz(node2cell);
            cell2node[{i,j}]=id;
            node2cell.pb({i,j});
            if(g[i][j]=='.') start==-1?start=id:end=id;
        }
    }

    map<int,vpd> adj;
    vvi visited(n,vi(n,0));
    int dr[4]=DR, dc[4]=DC;
    char dir_char[4]=DIR;

    // 0-ohm adjacent
    rep(i,n) rep(j,n){
        if(cell2node.count({i,j})){
            int u=cell2node[{i,j}];
            if(j+1<n && cell2node.count({i,j+1})){
                int v=cell2node[{i,j+1}];
                adj[u].pb({v,0}); adj[v].pb({u,0});
            }
            if(i+1<n && cell2node.count({i+1,j})){
                int v=cell2node[{i+1,j}];
                adj[u].pb({v,0}); adj[v].pb({u,0});
            }
        }
    }

    // Trace resistors
    rep(idx,sz(node2cell)){
        int r=node2cell[idx].fi, c=node2cell[idx].se;
        rep(d,4){
            int nr=r+dr[d], nc=c+dc[d];
            if(!valid(nr,nc,n)||visited[nr][nc]||g[nr][nc]!=dir_char[d]) continue;
            vec<pii> path; double res=0;
            int cr=nr, cc=nc;
            while(valid(cr,cc,n)){
                if(cell2node.count({cr,cc})){
                    int u=cell2node[{r,c}], v=cell2node[{cr,cc}];
                    if(u!=v && res>EPS){
                        adj[u].pb({v,res}); adj[v].pb({u,res});
                    }
                    for(auto p:path) visited[p.fi][p.se]=1;
                    break;
                }
                if(g[cr][cc]!=dir_char[d]||visited[cr][cc]) break;
                path.pb({cr,cc}); res+=1;
                cr+=dr[d]; cc+=dc[d];
            }
        }
    }

    // Circuit reduction
    bool changed=1;
    while(changed){
        changed=0;
        vec<int> nodes;
        for(auto &p:adj) nodes.pb(p.fi);
        for(int node:nodes){
            if(adj.find(node)==adj.end()||node==start||node==end) continue;
            if(sz(adj[node])==2){
                pdi p1=adj[node][0], p2=adj[node][1];
                int u=p1.fi,w=p2.fi; double r1=p1.se,r2=p2.se;
                adj.erase(node);
                rep(i,sz(adj[u])) if(adj[u][i].fi==node){ adj[u].erase(adj[u].begin()+i); break; }
                rep(i,sz(adj[w])) if(adj[w][i].fi==node){ adj[w].erase(adj[w].begin()+i); break; }
                adj[u].pb({w,r1+r2}); adj[w].pb({u,r1+r2});
                changed=1; goto next_iter;
            }
        }
        for(auto &[u,nbs]:adj){
            if(sz(nbs)<2) continue;
            map<int,vi> grp;
            rep(i,sz(nbs)) grp[nbs[i].fi].pb(nbs[i].se);
            for(auto &[v,rs]:grp){
                if(sz(rs)>1){
                    double inv=0; bool shortc=0;
                    for(double r:rs){ if(r<EPS){shortc=1;break;} inv+=1/r; }
                    double nr=shortc?0:1/inv;
                    vpd u_new,v_new;
                    for(auto e:adj[u]) if(e.fi!=v) u_new.pb(e);
                    for(auto e:adj[v]) if(e.fi!=u) v_new.pb(e);
                    u_new.pb({v,nr}); v_new.pb({u,nr});
                    adj[u]=u_new; adj[v]=v_new;
                    changed=1; goto next_iter;
                }
            }
        }
        next_iter:;
    }

    double ans=0;
    if(!adj.empty() && adj.count(start) && !adj[start].empty()) ans=adj[start][0].se;
    cout << round(ans);
}
