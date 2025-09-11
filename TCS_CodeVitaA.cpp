#include <bits/stdc++.h>
using namespace std;


//#pragma GCC target("avx,avx2,avx512,fma") 

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define lli long long int
#define ull unsigned long long
#define vii vector<pair<int, int>>
#define vll vector<long long>
#define vi vector<int>
#define vl vector<long>
#define ar array
#define ull unsigned long long
#define vii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vi vector<int>
#define vl vector<long>
#define ar array
#define mp make_pair
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define PRINT std::cout
#define INPUT std::cin
#define nl endl
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int MAX_FACT = 1e5 + 5;  // Maximum size for factorials
int fact[MAX_FACT], ifact[MAX_FACT];
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define UPDATE_COUNT_DIV(factor_count) (count_div = (count_div * ((ll)(factor_count) + 1)) % MOD)
#define COMPARE_FACTORS(p1, p2) (m_fact[p1].first == a_fact[p2].first)
#define IF_LESS_THAN(p1, p2) (m_fact[p1].first < a_fact[p2].first)
#define FORR(i, a, b) for(int i = a; i >= b; i--)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#pragma GCC optimize("Ofast,unroll-loops") 
// -------------------------<RNG>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
// ----------------------</BITWISE>-------------------------- 
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define MAX 100005
// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))
// ----------------------</BITWISE END>-------------------------- 

// ----------------------<MATH>--------------------------- 

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);} 

template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));} 

int add(int a, int b, int c = MOD){int res=a+b;
                         return(res>=c?res-c:res);} 
int mod_neg(int a, int b, int c = MOD){int res;
                         if(abs(a-b)<c)res=a-b;else res=(a-b)%c;
                         return(res<0?res+c:res);} 
int mul(int a, int b, int c = MOD){ll res=(ll)a*b;
                         return(res>=c?res%c:res);} 
int muln(int a, int b, int c = MOD){ll res=(ll)a*b;
                         return ((res%c)+c)%c;} 
ll mulmod(ll a,ll b, ll m = MOD){ll q = (ll)(((ld)a*(ld)b)/(ld)m);
                         ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;} 
template<typename T>T expo(T e, T n){T x=1,p=e;while(n)
                         {if(n&1)x=x*p;p=p*p;n>>=1;}return x;} 
template<typename T>T power(T e, T n, T m = MOD){T x=1,p=e;while(n)
                      {if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;} 
template<typename T>T extended_euclid(T a, T b, T &x, T &y)
                    {T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n = MOD){T x,y,z=0;
               T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));} 



// Permutation and Combination
int ncr(int n,int r,int c = MOD){ 
    return mul(mul(ifact[r],ifact[n-r],c),fact[n],c); 
}  


void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX_FACT; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    ifact[MAX_FACT - 1] = mod_inverse(fact[MAX_FACT - 1]);
    for (int i = MAX_FACT - 2; i >= 0; i--) {
        ifact[i] = mul(ifact[i + 1], i + 1);
    }
}
// ----------------------</MATH>-------------------------- 
#define INIT_PART \
    vector<string> g(M, string(N, '0')); \
    vector<pair<int,int>> start, goal; \
    rep(i,0,M) rep(j,0,N) { \
        string t; cin >> t; \
        char ch = t[0]; \
        g[i][j] = ch; \
        if (ch == 's') start.push_back({i,j}); \
        if (ch == 'S') goal.push_back({i,j}); \
    } \
    auto inb = [&](int r, int c){ return r>=0 && r<M && c>=0 && c<N; }; \
    auto freeCell = [&](int r, int c){ return inb(r,c) && g[r][c] != 'H'; }; \
    auto id = [&](int r, int c){ return r*N + c; }; \
    if (start.size()!=2 || goal.size()!=2) { cout << "Impossible\n"; return 0; } \
    int sa = id(start[0].first, start[0].second); \
    int sb = id(start[1].first, start[1].second); \
    if (sa > sb) swap(sa, sb); \
    int ga = id(goal[0].first, goal[0].second); \
    int gb = id(goal[1].first, goal[1].second); \
    if (ga > gb) swap(ga, gb); \
    auto adj = [&](int A, int B){ \
        int r1=A/N, c1=A%N, r2=B/N, c2=B%N; \
        return (abs(r1-r2)+abs(c1-c2))==1; \
    }; \
    if (!adj(sa,sb) || !adj(ga,gb)) { cout << "Impossible\n"; return 0; } \
    int TOT = M*N; \
    vector<char> vis((size_t)TOT * (size_t)TOT, 0); \
    auto mark = [&](int a, int b){ vis[a*TOT + b] = 1; }; \
    auto seen = [&](int a, int b){ return vis[a*TOT + b]; }; \
    auto push = [&](queue<Node>&q, int a, int b, int d){ \
        if (a>b) swap(a,b); \
        if (!adj(a,b)) return; \
        if (!seen(a,b)) { mark(a,b); q.push({a,b,d}); } \
    };
/****************** Prime Generator **********************/ 
const int N=1e7+10; int prime[20000010]; 
bool isprime[N]; int nprime; 
template <typename T> void Sieve(T a) 
{nprime = 0;memset(isprime,true,sizeof(isprime));
isprime[1]=false;for(int i=2;i<N;i++){
if(isprime[i]){prime[nprime++]=i;for(int j=2;i*j<N;j++)
isprime[i*j]=false;}}}

template <typename T> bool miller_rabin(T p, T itt) 
{if(p<2) return 0 ;if(p==2) return 1;if(p%2==0) 
return 0 ;unsigned long long s = p-1 ;while(s%2==0) s/=2;
for(ll i=1;i<=itt;i++) {unsigned long long a = rand() % (p-1)+1 , temp = s ;
unsigned long long mod = mulmod(a,temp,(unsigned long long)p);while(mod!=1 and mod!=p-1 
and temp!=p-1){mod = mulmod(mod,mod,(unsigned long long)p);temp*=2;}
if(temp%2==0 and mod!=p-1) return false ;}return true;} 

template <typename T> inline T PrimeFactors(T n)
{ll cnt=0,sum=1;for(int i=0; prime[i]*prime[i]<=n 
and i<nprime;i++){cnt=0;while(n%prime[i]==0)
{cnt++;n/=prime[i];}sum*=(cnt+1);}
if(n>1)sum*=2;return sum;} 
/****************** Prime Generator End **********************/ 
#define BFS_LOOP while(!q.empty()){ \
    auto cur = q.front(); q.pop(); \
    int a=cur.a, b=cur.b, d=cur.d; \
    if (a==ga && b==gb) { ans=d; break; } \
    int r1=a/N, c1=a%N, r2=b/N, c2=b%N; \
    if (r1==r2) { \
        int r=r1, c=c1; \
        if (c-1>=0 && freeCell(r,c-1)) \
            push(q, id(r,c-1), id(r,c), d+1); \
        if (c+2<N && freeCell(r,c+2)) \
            push(q, id(r,c+1), id(r,c+2), d+1); \
        if (r-1>=0 && freeCell(r-1,c) && freeCell(r-1,c+1)) \
            push(q, id(r-1,c), id(r-1,c+1), d+1); \
        if (r+1<M && freeCell(r+1,c) && freeCell(r+1,c+1)) \
            push(q, id(r+1,c), id(r+1,c+1), d+1); \
        if (r-1>=0 && freeCell(r-1,c) && freeCell(r-1,c+1)) { \
            push(q, id(r-1,c),   id(r,  c),   d+1); \
            push(q, id(r-1,c+1), id(r,  c+1), d+1); \
        } \
        if (r+1<M && freeCell(r+1,c) && freeCell(r+1,c+1)) { \
            push(q, id(r,  c),   id(r+1,c),   d+1); \
            push(q, id(r,  c+1), id(r+1,c+1), d+1); \
        } \
    } else if (c1==c2) { \
        int r=r1, c=c1; \
        if (r-1>=0 && freeCell(r-1,c)) \
            push(q, id(r-1,c), id(r,  c), d+1); \
        if (r+2<M && freeCell(r+2,c)) \
            push(q, id(r+1,c), id(r+2,c), d+1); \
        if (c-1>=0 && freeCell(r,c-1) && freeCell(r+1,c-1)) \
            push(q, id(r,  c-1), id(r+1,c-1), d+1); \
        if (c+1<N && freeCell(r,c+1) && freeCell(r+1,c+1)) \
            push(q, id(r,  c+1), id(r+1,c+1), d+1); \
        if (c-1>=0 && freeCell(r,c-1) && freeCell(r+1,c-1)) { \
            push(q, id(r,  c-1), id(r,  c), d+1); \
            push(q, id(r+1,c-1), id(r+1,c), d+1); \
        } \
        if (c+1<N && freeCell(r,c+1) && freeCell(r+1,c+1)) { \
            push(q, id(r,  c),   id(r,  c+1), d+1); \
            push(q, id(r+1,c),   id(r+1,c+1), d+1); \
        } \
    } \
}
/****************** Geometry *****************/ 
template <typename T> inline T PointDistanceHorVer(T x1,T y1,T x2, T y2) 
{return abs(x1-x2)+abs(y1-y2);} 
template <typename T> inline T PointDistanceDiagonally(T x1,T y1,T x2, T y2) 
{return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));} 
template <typename T> inline T PointDistanceMinimum(T x1,T y1,T x2, T y2) 
{ T tmp1=abs(x1-x2); T tmp2=abs(y1-y2); T tmp3=abs(tmp1-tmp2); 
T tmp4=min(tmp1, tmp2); return tmp3+tmp4; } 
template <typename T> inline T PointDistance3D(T x1,T y1,T z1,T x2,T y2,T z2)
{return sqrt(square(x2-x1)+square(y2-y1)+square(z2-z1));} 
 
template <typename T> inline T Cube(T a){return a*a*a;} 
template <typename T> inline T RectengularPrism(T a,T b,T c)
{return a*b*c;} 
template <typename T> inline T Pyramid(T base, T height)
{return (1/3)*base*height;} 
template <typename T> inline T Ellipsoid(T r1,T r2,T r3) 
{return (4/3)*PI*r1*r2*r3;} 
template <typename T> inline T IrregualarPrism(T base, T height)
{return base*height;} 
template <typename T> inline T Sphere(T radius)
{ return (4/3)*PI*radius*radius*radius;} 
template <typename T> inline T CylinderB(T base, T height)
{return base*height;} // base and height 
template <typename T> inline T CylinderR(T radius, T height)
{return PI*radius*radius*height;} // radius and height 
template <typename T> inline T Cone (T radius,T base, T height)
{return (1/3)*PI*radius*radius*height;} 
/****************** Geometry end *****************/ 
#define len(x) int((x).size())
#define pb push_back
#define rall(n) n.rbegin(),n.rend()
#define qn queue<Node>
// Constants
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct Node {
    int a, b, d;
};
// Helper Functions
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l,r)(rng); }



int main() {
    fastio;int M, N;if (!(cin >> M >> N)) return 0;

    INIT_PART
    //conditions
    qn q;push(q, sa, sb, 0);if (sa==ga && sb==gb) { cout << 0 << '\n'; return 0; } /*loop checkers*/int ans = -1;

    BFS_LOOP;

    if (ans==-1) cout << "Impossible";
    else cout << ans;
    return 0;
}
