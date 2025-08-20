#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define MX 100

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define VI vector<int>
#define VVI vector<VI>
#define VVVI vector<VVI>
#define VVVVI vector<VVVI>
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define ADD(a,b) ((a)+(b)>=MOD?((a)+(b)-MOD):((a)+(b)))
#define MUL(a,b) ((1LL*(a)*(b))%MOD)
#define READ(x) cin>>x
#define READV(v,n) FOR(i,1,n) cin>>v[i]
#define PRINT(x) cout<<x<<"\n"
#define COMB(i,j) C[i][j]
#define COMBS() FOR(i,0,MX){C[i][0]=C[i][i]=1;FOR(j,1,i-1){C[i][j]=ADD(C[i-1][j-1],C[i-1][j]);}}

int C[MX+1][MX+1];

#define SOLVE_BLOCK { \
    int n; \
    READ(n); \
    VI s(n+1); \
    READV(s,n); \
    long long fixedSum=0; \
    bool bad=false; \
    FOR(i,1,n) { \
        if(s[i]>=0){ \
            fixedSum+=s[i]; \
            if(s[i]>n-1) bad=true; \
        } \
    } \
    if(bad||fixedSum>n-1){ \
        PRINT(0); \
        return; \
    } \
    VVVVI g(n+2,VVVI(n+2)); \
    FOR(L,1,n) { \
        int R=L+1; \
        if(R<=n) g[L][R]=VVI(1,VI(1,1)); \
    } \
    FOR(len,2,n-1) { \
        FOR(L,1,n-len) { \
            int R=L+len, m=R-L-1; \
            VVI table(m+1,VI(m+1,0)); \
            FOR(x,L+1,R-1) { \
                int m1=x-L-1, m2=R-x-1; \
                int incL=((x-L)<=(R-x)?1:0), incR=1-incL; \
                int combWays=COMB(m1+m2,m1); \
                const VVI &left=g[L][x].empty()?VVI(1,VI(1,1)):g[L][x]; \
                const VVI &right=g[x][R].empty()?VVI(1,VI(1,1)):g[x][R]; \
                int sx=s[x]; \
                if(sx==-1){ \
                    VI sumL(m1+1,0),sumR(m2+1,0); \
                    FOR(tL,0,m1){ \
                        int acc=0; \
                        FOR(b,0,left[tL].size()-1) acc=ADD(acc,left[tL][b]); \
                        sumL[tL]=acc; \
                    } \
                    FOR(tR,0,m2){ \
                        int acc=0; \
                        FOR(c,0,right.size()-1) acc=ADD(acc,right[c][tR]); \
                        sumR[tR]=acc; \
                    } \
                    FOR(tL,0,m1) FOR(tR,0,m2) { \
                        int val=MUL(sumL[tL],sumR[tR]); \
                        int &cell=table[incL+tL][incR+tR]; \
                        cell=ADD(cell,MUL(combWays,val)); \
                    } \
                } else { \
                    int S=sx, bmin=max(0,S-m2), bmax=min(m1,S); \
                    if(bmin<=bmax) FOR(k,bmin,bmax) { \
                        FOR(tL,0,m1){ \
                            int vL=left[tL][k]; \
                            if(!vL) continue; \
                            FOR(tR,0,m2){ \
                                int vR=right[S-k][tR]; \
                                if(!vR) continue; \
                                int &cell=table[incL+tL][incR+tR]; \
                                cell=ADD(cell,MUL(combWays,MUL(vL,vR))); \
                            } \
                        } \
                    } \
                } \
            } \
            g[L][R]=move(table); \
        } \
    } \
    VVI hLeft(n+2), hRight(n+2); \
    FOR(a,1,n){ \
        int m=a-1; \
        VI arr(m+1,0); \
        if(m==0){ arr[0]=1; hLeft[a]=move(arr); continue; } \
        FOR(x,1,a-1){ \
            int m1=x-1, m2=a-x-1; \
            int combWays=COMB(m1+m2,m1); \
            const VI &lh=hLeft[x]; \
            const VVI &rg=g[x][a].empty()?VVI(1,VI(1,1)):g[x][a]; \
            int sx=s[x]; \
            if(sx==-1){ \
                int sumU=0; FOR(u,0,m1) sumU=ADD(sumU,lh[u]); \
                FOR(v_a,0,m2){ \
                    int sumVx=0; FOR(vx,0,rg.size()-1) sumVx=ADD(sumVx,rg[vx][v_a]); \
                    int tA=1+v_a; \
                    arr[tA]=ADD(arr[tA],MUL(combWays,MUL(sumU,sumVx))); \
                } \
            } else { \
                int S=sx; \
                FOR(u,max(0,S-m2),min(m1,S)){ \
                    int vx=S-u; \
                    int coef=MUL(combWays,lh[u]); \
                    if(!coef) continue; \
                    FOR(v_a,0,m2){ \
                        int tA=1+v_a; \
                        int ways=rg[vx][v_a]; \
                        if(!ways) continue; \
                        arr[tA]=ADD(arr[tA],MUL(coef,ways)); \
                    } \
                } \
            } \
        } \
        hLeft[a]=move(arr); \
    } \
    FORD(a,n,1){ \
        int m=n-a; \
        VI arr(m+1,0); \
        if(m==0){ arr[0]=1; hRight[a]=move(arr); continue; } \
        FOR(x,a+1,n){ \
            int m1=x-a-1, m2=n-x; \
            int combWays=COMB(m1+m2,m1); \
            const VVI &lg=g[a][x].empty()?VVI(1,VI(1,1)):g[a][x]; \
            const VI &rh=hRight[x]; \
            int sx=s[x]; \
            if(sx==-1){ \
                int sumU=0; FOR(u,0,m2) sumU=ADD(sumU,rh[u]); \
                FOR(v_a,0,m1){ \
                    int sumVx=0; FOR(vx,0,lg[v_a].size()-1) sumVx=ADD(sumVx,lg[v_a][vx]); \
                    int tA=1+v_a; \
                    arr[tA]=ADD(arr[tA],MUL(combWays,MUL(sumVx,sumU))); \
                } \
            } else { \
                int S=sx; \
                FOR(vx,max(0,S-m2),min(m1,S)){ \
                    int u=S-vx; \
                    int coef=MUL(combWays,rh[u]); \
                    if(!coef) continue; \
                    FOR(v_a,0,m1){ \
                        int tA=1+v_a; \
                        int ways=lg[v_a][vx]; \
                        if(!ways) continue; \
                        arr[tA]=ADD(arr[tA],MUL(coef,ways)); \
                    } \
                } \
            } \
        } \
        hRight[a]=move(arr); \
    } \
    int ans=0; \
    FOR(r,1,n){ \
        int combWays=COMB(r-1+n-r,r-1); \
        const VI &L=hLeft[r], &R=hRight[r]; \
        if(s[r]==-1){ \
            int sumL=0,sumR=0; \
            for(int v:L) sumL=ADD(sumL,v); \
            for(int v:R) sumR=ADD(sumR,v); \
            ans=ADD(ans,MUL(combWays,MUL(sumL,sumR))); \
        } else { \
            int S=s[r]; long long tot=0; \
            FOR(tl,0,L.size()-1){ \
                int tr=S-tl; \
                if(tr>=0 && tr<R.size()) \
                    tot+=1LL*L[tl]*R[tr]%MOD; \
            } \
            ans=ADD(ans,MUL(combWays,tot%MOD)); \
        } \
    } \
    PRINT(ans); \
}

#define SOLVE_FUNC void solve()
#define SOLVE_CALL solve()

SOLVE_FUNC {
    SOLVE_BLOCK
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    COMBS();
    int tc=1;
    READ(tc);
    FOR(t,1,tc) SOLVE_CALL;
    return 0;
}
