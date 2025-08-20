#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define MATH_CONSTANTS const long long MOD=998244353;const int MAXN=200000;long long fct[MAXN+5], invf[MAXN+5];
#define MATH_FUNCTIONS long long modpow(long long a,long long e){long long r=1%MOD;while(e){if(e&1)r=r*a%MOD;a=a*a%MOD;e>>=1;}return r;}long long C(int n,int k){if(k<0||k>n||n<0)return 0;return fct[n]*invf[k]%MOD*invf[n-k]%MOD;}
MATH_CONSTANTS
MATH_FUNCTIONS
int main(){
    #define MAIN_LOGIC \
        ios::sync_with_stdio(false);cin.tie(nullptr);fct[0]=1;for(int i=1;i<=MAXN;i++) fct[i]=fct[i-1]*i%MOD;invf[MAXN]=modpow(fct[MAXN], MOD-2);for(int i=MAXN;i>0;i--) invf[i-1]=invf[i]*i%MOD; \
        int T;if(!(cin>>T)) return 0; \
        while(T--){ \
            long long N,K;cin>>N>>K; \
            long long z = N/3; \
            long long a1 = N/3+(N%3>=1); \
            long long a2 = N/3+(N%3>=2); \
            long long ans=0; \
            for(long long B=z-1;B<=z+1;B++){ \
                if(B<1) continue; \
                long long e=z-(B-1); \
                long long mult=(e==0?1:(e==1?2:(e==2?1:0))); \
                if(!mult) continue; \
                long long s=0; \
                long long mn=max(0LL,B-a2); \
                long long mx=min(B,a1); \
                for(long long b1=mn;b1<=mx;b1++){ \
                    long long b2=B-b1; \
                    long long f1=(b1==0?(a1==0):(b1<=a1?C((int)a1-1,(int)b1-1):0)); \
                    long long f2=(b2==0?(a2==0):(b2<=a2?C((int)a2-1,(int)b2-1):0)); \
                    long long ways=C((int)B,(int)b1)*f1%MOD*f2%MOD; \
                    s=(s+ways)%MOD; \
                } \
                ans=(ans+mult*s)%MOD; \
            } \
            ans=ans*fct[(int)z]%MOD*fct[(int)a1]%MOD*fct[(int)a2]%MOD; \
            cout<<ans%MOD<<"\n"; \
        }
    
    MAIN_LOGIC
    
    #undef MAIN_LOGIC
    return 0;
}