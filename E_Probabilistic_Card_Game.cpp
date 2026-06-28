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
#define frr for
#define wl(x) while(x)
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
#define fr(i,a,b) for(ii i=(a);i<=(b);++i)
#define mpll map<ll,pair<ll,ll>>
#define emp empty
#define bkk back
#define wh(x) while(x)
#define clr clear
#define vchr vector<char>
//sybau
const ii mx = 998244353;

template<class t>
stc ab{ virtual void go(void*)=0; virtual ~ab(){} };

template<class t>
stc im:ab<t>{
    function<void(void*)> fn;
    im(function<void(void*)> f):fn(f){}
    void go(void* p) override{ fn(p); }
};

template<class t>
stc bx{ static t* cv(void* p){ return reinterpret_cast<t*>(p); } };

stc nd{ ii ct; ll sm; };

vector<nd> tr;
vll ov, vr;
ii nc;

ll pw(ll b,ll e){
    ll r=1;
    b%=mx;
    wh(e){
        (e&1)?(void)(r=r*b%mx):(void)0;
        b=b*b%mx;
        e>>=1;
    }
    return r;
}

ll inv(ll x){ return pw(x,mx-2); }

void upd(ii no,ii l,ii r,ii id,ll v){
    (l==r)
    ? ([&](){ tr[no].ct=1; tr[no].sm=v; }())
    : ([&](){
            ii md=(l+r)>>1;
            (id<=md)?upd(no<<1,l,md,id,v):upd(no<<1|1,md+1,r,id,v);
            tr[no].ct=tr[no<<1].ct+tr[no<<1|1].ct;
            tr[no].sm=tr[no<<1].sm+tr[no<<1|1].sm;
      }());
}

pair<ii,ll> qry(ii no,ii l,ii r,ii ql,ii qr){
    return (qr<l||r<ql)
    ? make_pair(0,0ll)
    : (ql<=l&&r<=qr)
        ? make_pair(tr[no].ct,tr[no].sm)
        : ([&](){
                ii md=(l+r)>>1;
                aut a=qry(no<<1,l,md,ql,qr);
                aut b=qry(no<<1|1,md+1,r,ql,qr);
                re make_pair(a.frs+b.frs,a.scs+b.scs);
          }());
}

ii kth(ii no,ii l,ii r,ii k){
    re (l==r)
    ? l
    : ([&](){
            ii md=(l+r)>>1;
            re (tr[no<<1].ct>=k)?kth(no<<1,l,md,k):kth(no<<1|1,md+1,r,k-tr[no<<1].ct);
      }());
}

ll gl(ii rk){
    ii id=kth(1,1,nc,rk);
    ll v=ov[id-1];
    ll s=qry(1,1,nc,1,id-1).scs;
    re v*(rk-1ll)-s;
}

ll gr(ii rk,ii n){
    ii id=kth(1,1,nc,rk);
    ll v=ov[id-1];
    ll s=qry(1,1,nc,id+1,nc).scs;
    re s-v*(n-rk);
}

void sl(void*){
    aut lm=[&](void*){
        ii m;
        (iin>>m)
        ? ([&](){
                vr.resize(m);
                vll sa;

                ll* pvr=nullptr;

                fr(i,0,m-1){
                    pvr=vr.data();
                    iin>>*(pvr+i);
                    sa.pb(*(pvr+i));
                }
                sort(all(sa));
                sa.erase(unique(all(sa)),sa.end());
                ov=sa;
                nc=(ii)sa.size();
                tr.resize(4*nc+5);
                fill(tr.begin(),tr.end(),nd{0,0});
                ll* psa=sa.data();
                ll* pvr2=vr.data();
                fr(i,0,m-1){
                    ii id=(ii)(lower_bound(psa,psa+nc,*(pvr2+i))-psa)+1;
                    upd(1,1,nc,id,*(pvr2+i));

                    (i<2)?(void)0:([&](){
                        ii n=i+1;
                        ii lo=1,hi=n,po=1;

                        wh(lo<=hi){
                            ii md=(lo+hi)>>1;
                            ll lv=-4e18,rv=-4e18;

                            (md>1)?(void)(lv=gl(md-1)):(void)0;
                            (md<n)?(void)(rv=gr(md+1,n)):(void)0;

                            (lv<=rv)?(po=md,lo=md+1):(hi=md-1);
                        }

                        ll av=4e18;

                        aut ck=[&](ii p){
                            (p<1||p>n)?(void)0:([&](){
                                ll l=-4e18,r=-4e18;
                                (p>1)?(void)(l=gl(p-1)):(void)0;
                                (p<n)?(void)(r=gr(p+1,n)):(void)0;
                                ll rs;
                                rs=(p==1)?r:((p==n)?l:max(l,r));
                                av=min(av,rs);
                            }());
                        };

                        ck(po); ck(po+1);

                        ll fa=((av%mx)+mx)%mx;
                        ll iv=inv(n-2);
                        pri<<(fa*iv)%mx<<nl;
                    }());
                }
          }())
        : ([&](){ }());

        void* vp=nullptr;
        bx<ll>::cv(vp);
    };

    ab<ll>* ob=new im<ll>(lm);
    void* px=nullptr;
    ob->go(px);
    delete ob;
}

stc oox{
    void run(){
        nfio
        ab<ii>* ob=new im<ii>(sl);
        void* px=nullptr;
        ob->go(px);
        delete ob;
    }
};

int main(){
    oox oo;
    oo.run();
    return 0;
}