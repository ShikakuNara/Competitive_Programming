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

// Functions
ll gcd(ll a, ll b){
    if(a > b) return gcd(b, a);
    if (a == 0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * (b / gcd(a, b));
}
ll Abs(ll a){
  if( a > 0)
    return a;

  return -a;
}
double Abs(double a){
  if( a > 0)
    return a;

  return -a;
}

const int MAX = 400009;
const int MOD = 1e9+7;


vll fac;
ll binarysearch(ll s, ll e, ll v)
{
  ll m = (s+e+1)/2;
  if(s == e)
  {
    if(fac[m] <= v) return fac[m];

    return -1;
  }

  if(fac[m] == v)
  {
    return v;
  }

  if(fac[m] > v)
  {
    return binarysearch(s, m-1, v);
  }

  return binarysearch(m, e, v);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n, m; cin>>n>>m;

    ll g = gcd(n, m);

    for (ll i = 1; i*i <= g; i++) {
      if(g % i == 0)
      {
        fac.pb(i);
        if(i*i != g) fac.pb(g/i);
      }
    }

    sortA(fac);

    ll q; cin>>q;

    rep(i, q)
    {
      ll a, b; cin>>a>>b;

      ll num = binarysearch(0, sz(fac)-1, b);

      if(num >= a) cout << num<<'\n';
      else cout <<-1<<'\n';
    }




    return 0;
}