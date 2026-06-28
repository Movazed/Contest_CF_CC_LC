#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops") 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)      
#else
#define dbg(...)
#endif
#define nl "\n"
#define vi vector<int>
#define vll vector<ll>
#define _ar array
#define ll long long
#define ld long double
#define vpll vector<pair<ll, ll>>
#define vll vector<ll>
#define sza(x) ((int)x.size())
#define szz size
#define all(a) (a).begin(), (a).end()
#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int MAX_FACT = 1e5 + 5;  // Maximum size for factorials
int fact[MAX_FACT], ifact[MAX_FACT];
#define qi queue<int>
#define ii int
#define vvi vector<vector<int>>
#define iin cin
#define fls cout.flush();
#define frnt front
#define frs first
#define scs second
#define cst const
#define re return
#define _exit(x) exit(x)
#define len(x) int((x).size())
#define pb push_back
#define po pop
#define aut  auto
#define pu push
#define input std::cin
#define rall(n) n.rbegin(),n.rend()
#define rep(i,a,b) for(ii i=a;i<b;i++)
#define per(i,a,b) for(ii i=a;i>=b;i--)
#define pri cout
#define word char
#define nfio ios_base ::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define vpii vector<pair<int, int>>
#define ins insert
#define usi unordered_set<int>
#define _br break
#define frr for
#define stc struct
#define usll unsigned long long
#define ponder(x) if(x)
#define too top
#define bgg begin

#define enn end
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


// ----------------------</MATH>-------------------------- 

/****************** Prime Generator **********************/ 
const int N=31; int prime[20000010]; 
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
#define stt static
#define rss resize
#define pob pop_back
#define revz reserve
#define swp swap
// Constants
mt19937_64 rng(time(0));
#define line string
#define tos to_string
// Helper Functions
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l,r)(rng); }
#define mpll map<ll,pair<ll,ll>>
#define emp empty
#define bkk back
#define qpi queue<pair<ii,ii>>
#define clr clear
#define vchr vector<char>
#define vbo vector<bool>
//sybau
#define multii multiset<int>
#define err erase
#define vd vector<double>
#define dou double

#define pich pair<ii,char>
#define wl while
#define sof sizeof

#define frk(v,s,e) for(ii v=s;v<=e;v++)
#define frkd(v,s,e) for(ii v=s;v>=e;v--)

template<typename tp>
struct wr{
    tp* dt;
    ii sz;
    wr(tp* d,ii n):dt(d),sz(n){}
    tp& operator[](ii i){return dt[i];}
    ii size(){return sz;}
    struct it{
        tp* p;
        it(tp* x):p(x){}
        tp& operator*(){return *p;}
        it& operator++(){++p;return *this;}
        bool operator!=(const it& o){return p!=o.p;}
    };
    it begin(){return it(dt);}
    it end(){return it(dt+sz);}
};

template<typename tp>
struct fn{
    function<tp()> call;
    fn(function<tp()> f):call(f){}
    tp operator()(){return call();}
};

struct io{
    function<void()> flush;
    function<void(ii&)> ri;
    function<void(ii)> wi;
    function<void(const char*)> ws;
    io(){
        flush=[&](){cout.flush();};
        ri=[&](ii& x){cin>>x;};
        wi=[&](ii x){cout<<x;};
        ws=[&](const char* s){cout<<s;};
    }
};

struct sv{
    function<void(ii)> slv;
    io* op;
    sv(io* o):op(o){
        slv=[&](ii n){
            ii* raw=new ii[n];
            wr<ii> buf(raw,n);
            frkd(i,n,1) buf[n-i]=i;
            for(auto& x:buf){
                op->wi(x);
                &x!=&buf[buf.size()-1]?(op->ws(" "),(void)0):(void)0;
            }
            op->ws(nl);
            delete[] raw;
        };
    }
};

struct dp{
    function<void()> dispatch;
    dp(sv& s,io& o){
        dispatch=[&](){
            ii t;o.ri(t);
            ii* ts=new ii[t];
            wr<ii> tc(ts,t);
            frk(i,0,t-1){o.ri(tc[i]);}
            frr(auto& n:tc) s.slv(n);
            delete[] ts;
        };
    }
};

int32_t  main(){
    nfio
    io o;
    sv s(&o);
    dp d(s,o);
    fn<void> runner([&](){d.dispatch();return;});
    runner();
}