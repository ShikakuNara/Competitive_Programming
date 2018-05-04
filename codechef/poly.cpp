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
const ll INF = 100000000000;

vll poly[4];


ll eval(ll t, ll i)
{
  return poly[0][i]+ t*poly[1][i] + t*t*poly[2][i] + t*t*t*poly[3][i];
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll t; cin>>t;

    rep(aaja, t)
    {
      poly[0].clear();
      poly[1].clear();
      poly[2].clear();
      poly[3].clear();
      ll n; cin>>n;
      rep(i, n)
      {
        ll a,b,c,d;cin>>a>>b>>c>>d;
        poly[0].pb(a);
        poly[1].pb(b);
        poly[2].pb(c);
        poly[3].pb(d);
      }

      ll q;cin>>q;


      rep(i, q)
      {
        ll v;cin>>v;
        ll min = eval(v, 0);
        repA(j, 1, n-1)
        {
          if(eval(v, j) < min) min = eval(v, j);
        }
        cout << min << end;
      }
    }




    return 0;
}
