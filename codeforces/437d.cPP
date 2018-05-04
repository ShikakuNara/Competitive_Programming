#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef pair<ll, pp > ppp;
typedef vector<ppp > vppp;
typedef stack < pair<int, int> > sii;
typedef queue < ll > qll;

#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define rep(i, n)     for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(ll i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define PI 3.14159265
#define X first
#define Y second

const int MAX = 400009;
const int MOD = 1e9+7;

// Functions
ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
ll abs(ll a, ll b){
  if( a > b)
    return a-b;

  return b-a;
}
double abs(double a, double b){
  if( a > b)
    return a-b;

  return b-a;
}

ll a[MAX]; vll adj[MAX];

ll p[MAX] = {0}, r[MAX] = {0}, cnt[MAX] = {0};

void build(ll n)
{
  repA(i,0, n) p[i] = i;
  repA(i,0, n) cnt[i] = 1;
}

ll find(ll x)
{
  if(x != p[x])
    p[x] = find(p[x]);

  return p[x];
}

void merge(ll x, ll y)
{
  if(find(x) == find(y))
    return;

  x = find(x), y = find(y);

  if(r[x] > r[y])
  {
    p[y] = p[x];
    cnt[x] += cnt[y];
    return;
  }

  cnt[y] += cnt[x];
  p[x] = p[y];

  if(r[x] == r[y])
    r[y]++;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n,m; cin>>n>>m;

    build(n);

    for (ll i = 0; i < n; i++) {
      cin>>a[i];
    }

    vppp edge;

    for (size_t i = 0; i < m; i++) {
      ll x,y; cin>>x>>y; x--, y--;

      edge.pb(mp(min(a[x], a[y]), mp(x, y)));
    }

    sortD(edge); ll ans = 0;

    rep(i, m)
    {
      ll x = edge[i].Y.X, y = edge[i].Y.Y;

      if(find(x) == find(y)) continue;

      ans += edge[i].X * cnt[find(x)] * cnt[find(y)];

      merge(x, y);
    }

    cout << fixed << setprecision(8) << (double)ans / (double)((n*(n-1))/2) << "\n";

    return 0;
}
