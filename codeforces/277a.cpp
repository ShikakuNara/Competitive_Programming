#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
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
#define end '\n'

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

const int MAX = 110;
const int MOD = 1e9+7;

ll p[MAX] = {0}, r[MAX] = {0}, numset, cnt[MAX] = {0};

void build(ll n)
{
  repA(i,0, n) p[i] = i;
  repA(i,0, n) cnt[i] = 1;
  numset = n;
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

  numset--;
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

    ll n; cin>>n;

    pp p[MAX];

    rep(i, n)
    {
      ll x, y; cin>>x>>y;

      p[i] = mp(x, y);
    }

    build(n);

    rep(i, n)
    {
      repA(j, i+1, n-1)
      {
        if(p[i].X == p[j].X || p[i].Y == p[j].Y)
        {
          merge(i, j);
        }
      }
    }

    cout << numset-1<<end;



    return 0;
}
