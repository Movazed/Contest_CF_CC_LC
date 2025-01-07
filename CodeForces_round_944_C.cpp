#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,avx512,fma")

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ull unsigned long long
#define vii vector<pair<int int>>
#define vpll vector<pair<long long long long>>
#define vi vector<int>
#define vl vector<long>
#define ar array
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
const int MAX_FACT = 1e5 + 5; // Maximum size for factorials
int fact[MAX_FACT], ifact[MAX_FACT];

// -------------------------<RNG>-------------------------
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.

// ----------------------</BITWISE>--------------------------
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1ULL << (b)))
#define BIT_FLIP(a, b) ((a) ^= (1ULL << (b)))

// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a, b) (!!((a) & (1ULL << (b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))
// ----------------------</BITWISE END>--------------------------

// ----------------------<MATH>---------------------------

template <typename T>
T gcd(T a, T b) { return (b ? __gcd(a, b) : a); }

template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

int add(int a, int b, int c = MOD)
{
    int res = a + b;
    return (res >= c ? res - c : res);
}
int mod_neg(int a, int b, int c = MOD)
{
    int res;
    if (abs(a - b) < c)
        res = a - b;
    else
        res = (a - b) % c;
    return (res < 0 ? res + c : res);
}
int mul(int a, int b, int c = MOD)
{
    ll res = (ll)a * b;
    return (res >= c ? res % c : res);
}
int muln(int a, int b, int c = MOD)
{
    ll res = (ll)a * b;
    return ((res % c) + c) % c;
}
ll mulmod(ll a, ll b, ll m = MOD)
{
    ll q = (ll)(((ld)a * (ld)b) / (ld)m);
    ll r = a * b - q * m;
    if (r > m)
        r %= m;
    if (r < 0)
        r += m;
    return r;
}
template <typename T>
T expo(T e, T n)
{
    T x = 1, p = e;
    while (n)
    {
        if (n & 1)
            x = x * p;
        p = p * p;
        n >>= 1;
    }
    return x;
}
template <typename T>
T power(T e, T n, T m = MOD)
{
    T x = 1, p = e;
    while (n)
    {
        if (n & 1)
            x = mul(x, p, m);
        p = mul(p, p, m);
        n >>= 1;
    }
    return x;
}
template <typename T>
T extended_euclid(T a, T b, T &x, T &y)
{
    T xx = 0, yy = 1;
    y = 0;
    x = 1;
    while (b)
    {
        T q = a / b, t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}
template <typename T>
T mod_inverse(T a, T n = MOD)
{
    T x, y, z = 0;
    T d = extended_euclid(a, n, x, y);
    return (d > 1 ? -1 : mod_neg(x, z, n));
}

// Permutation and Combination
int ncr(int n, int r, int c = MOD)
{
    return mul(mul(ifact[r], ifact[n - r], c), fact[n], c);
}

void precompute_factorials()
{
    fact[0] = 1;
    for (int i = 1; i < MAX_FACT; i++)
    {
        fact[i] = mul(fact[i - 1], i);
    }
    ifact[MAX_FACT - 1] = mod_inverse(fact[MAX_FACT - 1]);
    for (int i = MAX_FACT - 2; i >= 0; i--)
    {
        ifact[i] = mul(ifact[i + 1], i + 1);
    }
}
// ----------------------</MATH>--------------------------

/****************** Prime Generator **********************/
const int N = 1e7 + 10;
int prime[20000010];
bool isprime[N];
int nprime;
template <typename T>
void Sieve(T a)
{
    nprime = 0;
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            prime[nprime++] = i;
            for (int j = 2; i * j < N; j++)
                isprime[i * j] = false;
        }
    }
}

template <typename T>
bool miller_rabin(T p, T itt)
{
    if (p < 2)
        return 0;
    if (p == 2)
        return 1;
    if (p % 2 == 0)
        return 0;
    unsigned long long s = p - 1;
    while (s % 2 == 0)
        s /= 2;
    for (ll i = 1; i <= itt; i++)
    {
        unsigned long long a = rand() % (p - 1) + 1, temp = s;
        unsigned long long mod = mulmod(a, temp, (unsigned long long)p);
        while (mod != 1 and mod != p - 1 and temp != p - 1)
        {
            mod = mulmod(mod, mod, (unsigned long long)p);
            temp *= 2;
        }
        if (temp % 2 == 0 and mod != p - 1)
            return false;
    }
    return true;
}
#define FIND_MEX(s, T) ({ T mex = 0; while (s.find(mex)!= s.end()) mex++; mex; })
template <typename T>
inline T PrimeFactors(T n)
{
    ll cnt = 0, sum = 1;
    for (int i = 0; prime[i] * prime[i] <= n and i < nprime; i++)
    {
        cnt = 0;
        while (n % prime[i] == 0)
        {
            cnt++;
            n /= prime[i];
        }
        sum *= (cnt + 1);
    }
    if (n > 1)
        sum *= 2;
    return sum;
}
/****************** Prime Generator End **********************/
#define INIT_QUEUE(q, x, y) \
    {                       \
        q.push(x);          \
        q.push(y);          \
    } // Macro to initialize queue with x and y
#define PUSH_TO_QUEUE(q, v) q.push(v)
/****************** Geometry *****************/
template <typename T>
inline T PointDistanceHorVer(T x1, T y1, T x2, T y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
template <typename T>
inline T PointDistanceDiagonally(T x1, T y1, T x2, T y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
template <typename T>
inline T PointDistanceMinimum(T x1, T y1, T x2, T y2)
{
    T tmp1 = abs(x1 - x2);
    T tmp2 = abs(y1 - y2);
    T tmp3 = abs(tmp1 - tmp2);
    T tmp4 = min(tmp1, tmp2);
    return tmp3 + tmp4;
}
template <typename T>
inline T PointDistance3D(T x1, T y1, T z1, T x2, T y2, T z2)
{
    return sqrt(square(x2 - x1) + square(y2 - y1) + square(z2 - z1));
}
#define GET_LEFT(i, n) (i == 1 ? n : i - 1)
#define GET_RIGHT(i, n) (i == n ? 1 : i + 1)
template <typename T>
inline T Cube(T a) { return a * a * a; }
template <typename T>
inline T RectengularPrism(T a, T b, T c)
{
    return a * b * c;
}
template <typename T>
inline T Pyramid(T base, T height)
{
    return (1 / 3) * base * height;
}
template <typename T>
inline T Ellipsoid(T r1, T r2, T r3)
{
    return (4 / 3) * PI * r1 * r2 * r3;
}
template <typename T>
inline T IrregualarPrism(T base, T height)
{
    return base * height;
}
template <typename T>
inline T Sphere(T radius)
{
    return (4 / 3) * PI * radius * radius * radius;
}
template <typename T>
inline T CylinderB(T base, T height)
{
    return base * height;
} // base and height
template <typename T>
inline T CylinderR(T radius, T height)
{
    return PI * radius * radius * height;
} // radius and height
template <typename T>
inline T Cone(T radius, T base, T height)
{
    return (1 / 3) * PI * radius * radius * height;
}
/****************** Geometry end *****************/
#define len(x) int((x).size())
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
#define INIT_VECTOR(n) vector<ll>(n + 1, -1)
// Constants
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Helper Functions
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

template <typename T>
T find_mex(const vector<T> &elements)
{
    unordered_set<T> unique_elements(elements.begin(), elements.end());
    return FIND_MEX(unique_elements, T);
}

void solve()
{
    long long node_count, node_x, node_y;
    cin >> node_count >> node_x >> node_y;

    vector<vector<long long>> adjacency_list(node_count + 1, vector<long long>());

    long long idx = 1;
    while (idx <= node_count)
    {
        adjacency_list[idx].push_back(GET_LEFT(idx, node_count));
        adjacency_list[idx].push_back(GET_RIGHT(idx, node_count));
        idx++;
    }

    adjacency_list[node_x].push_back(node_y);
    adjacency_list[node_y].push_back(node_x);

    vector<ll> distance = INIT_VECTOR(node_count);

    distance[node_x] = 0;
    distance[node_y] = 1;

    queue<ll> bfs_queue;
    INIT_QUEUE(bfs_queue, node_x, node_y);

    while (!bfs_queue.empty())
    {
        ll current_node = bfs_queue.front();
        bfs_queue.pop();
        ll adj_idx = 0;
        while (adj_idx < adjacency_list[current_node].size())
        {
            ll neighbor = adjacency_list[current_node][adj_idx];
            if (distance[neighbor] == -1)
            {
                vector<ll> labels;
                ll neighbor_idx = 0;
                while (neighbor_idx < adjacency_list[neighbor].size())
                {
                    ll adjacent_node = adjacency_list[neighbor][neighbor_idx];
                    if (distance[adjacent_node] != -1)
                    {labels.push_back(distance[adjacent_node]);}
                    neighbor_idx++;}
                distance[neighbor] = FIND_MEX(unordered_set<ll>(labels.begin(),labels.end()),ll);
                PUSH_TO_QUEUE(bfs_queue, neighbor);
            }
            adj_idx++;
        }
    }

    idx = 1;
    while (idx <= node_count)
    {
        if (distance[idx] == -1)
            distance[idx] = 0;
        idx++;
    }

    idx = 1;
    while (idx <= node_count)
    {
        cout << distance[idx];
        if (idx < node_count)
            cout << " ";
        else
            cout << endl;
        idx++;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precompute_factorials();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}
