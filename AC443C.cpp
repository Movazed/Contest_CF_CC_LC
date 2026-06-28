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
#define nl std::endl
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define ar array
#define ll long long
#define ld long double
#define vpll vector<pair<ll, ll>>
#define vll vector<ll>
#define sza(x) ((int)x.size())
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
#define vc vector<char>
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
#define mpll map<ll,ll>
#define _br break
#define ad add
#define frr for
#define fr(i,a,b) for(ii i=(a);i<(b);++i)
#define frx for(ii v=cn;v>lb;--v)
#define wl(x) while(x)
#define stc struct
#define usll unsigned long long
#define ponder(x) if(x)
#define too top
#define bgg begin
#define vb vector<bool>
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


void precompute_factorials() {
    fact[0] = 1;for (int i = 1; i < MAX_FACT; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    ifact[MAX_FACT - 1] = mod_inverse(fact[MAX_FACT - 1]);
    for (int i = MAX_FACT - 2; i >= 0; i--) {
        ifact[i] = mul(ifact[i + 1], i + 1);
    }
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
#define rss resize
// Constants
mt19937_64 rng(time(0));
#define line string
#define tos to_string
// Helper Functions
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l,r)(rng); }
#define fl(i,n) for(ii i=0;i<(n);++i)
#define wl(c) while(c)

stc a0{ virtual void rn(void*)=0; virtual ~a0(){} };
stc a1{ virtual void rn(a0*,void*)=0; virtual ~a1(){} };
stc a2{ virtual void rn(a1*,a0*,void*)=0; virtual ~a2(){} };

template<class T>
stc h0{ static void g(T& x){ x(); } };

stc dp:a0{
    void rn(void* pv) override{
        ii n;
        ll t;
        (iin>>n>>t)?
        (void)([&](){

            vll a(static_cast<size_t>(n));

            fl(i,n){
                iin>>a[static_cast<size_t>(i)];
            }

            ll tv=0,co=0;

            aut it=reinterpret_cast<vll&>(a).bgg();

            wl(it!=reinterpret_cast<vll&>(a).enn()){
                ll tp=*it;
                (tp>co)?
                    (void)(tv=tv + (tp-co),co=tp+100):
                    (void)0;
                ++it;
            }

            (co<t)?
                (void)(tv+=(t-co)):
                (void)0;

            pri<<tv<<nl;

        }()):
        (void)0;
    }
};

stc m0:a1{
    void rn(a0* o,void* pv) override{
        reinterpret_cast<a0*>(o)->rn(pv);
    }
};

stc x0:a2{
    void rn(a1* m,a0* o,void* pv) override{
        reinterpret_cast<a1*>(m)->rn(o,pv);
    }
};

stc rt{ virtual void go()=0; virtual ~rt(){} };

stc sl:rt{
    void go() override{

        static dp od;
        static m0 md;
        static x0 xd;

        a0* po=reinterpret_cast<a0*>(static_cast<a0*>(&od));
        a1* pm=reinterpret_cast<a1*>(static_cast<a1*>(&md));
        a2* px=reinterpret_cast<a2*>(static_cast<a2*>(&xd));

        static ll ar[1];

        px->rn(pm,po,reinterpret_cast<void*>(ar));
    }
};

int32_t main(){
    nfio
    static sl s;
    rt* rp=reinterpret_cast<rt*>(static_cast<rt*>(&s));
    aut fn=[&](){ reinterpret_cast<rt*>(rp)->go(); };
    h0<decltype(fn)>::g(fn);
    re 0;
}