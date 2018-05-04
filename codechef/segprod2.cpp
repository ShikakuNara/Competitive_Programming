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
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

// Functions
struct Rcompare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X>rhs.X;
  }
}; struct compare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X<rhs.X;
  }
};


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


ll MOD;
int modInverse(int a, int m)
{
    int m0 = m, t, q, x0 = 0, x1 = 1;

    if (m == 1) return 0;
    while (a > 1)
    {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}
ll power(ll x, ll y)
{
  if(y==0) return 1;
  if(y==1) return x;
  ll tmp=power(x, y/2);
  if(y%2==0) return (tmp*tmp)%MOD;
  return (tmp*(tmp*x)%MOD)%MOD;
}

ll a[1000001] = {0}, b[1000002] = {0}, inv[1000001] = {0}, cnt[1000001]={0};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    int t;cin>>t;

    rep(aj, t)
    {
      fill(cnt);
      ll n;ll q;cin>>n>>MOD>>q;
      ll flag=0, x=-1;
      for (ll i = 2; i*i <= MOD; i++) {
          if(MOD%i==0){flag=1, x = i; break;}
      }
      rep(i, n) {cin>>a[i];}
      rep(i, q/64 + 2) cin>>b[i];

      if(flag==1)
      {
        rep(i, n) while(a[i]%x==0) a[i] /= x, cnt[i]++;

        repA(i, 1, n-1) {a[i] *= a[i-1]; a[i] %= MOD;
          cnt[i]+=cnt[i-1];
        }
        rep(i, n){inv[i] = modInverse(a[i], MOD);}

        ll lprev, rprev, ans = -1;
        rep(i, q)
        {
          ll l, r;
          if(i % 64 == 0)
          {
            l = (b[i/64]+(ans+1)%MOD)%n, r = (b[i/64+1]+(ans+1)%MOD)%n;
          }
          else
          {
            l = (lprev+(ans+1)%MOD)%n, r = (rprev+(ans+1)%MOD)%n;
          }
          if( l > r) {ll tmp = l; l = r; r = tmp;}

          if(l > 0)
          {
              ans = (a[r] * inv[l-1]) % MOD;
              ans *= power(x, cnt[r]-cnt[l-1]);
              ans %= MOD;
          }
          else
          {
            ans = a[r];
            ans *= power(x, cnt[r]);
            ans %= MOD;
          }

          lprev = l, rprev = r;
        }
        cout<<(ans+1)%MOD<<end;
      }
      else
      {
        repA(i, 1, n-1) {a[i] *= a[i-1]; a[i] %= MOD;}
        rep(i, n){inv[i] = modInverse(a[i], MOD);}

        ll lprev, rprev, ans = -1;
        rep(i, q)
        {
          ll l, r;
          if(i % 64 == 0)
          {
            l = (b[i/64]+(ans+1)%MOD)%n, r = (b[i/64+1]+(ans+1)%MOD)%n;
          }
          else
          {
            l = (lprev+(ans+1)%MOD)%n, r = (rprev+(ans+1)%MOD)%n;
          }
          if( l > r) {ll tmp = l; l = r; r = tmp;}

          if(l > 0)
            ans = (a[r] * inv[l-1]) % MOD;
          else
            ans = a[r];

          lprev = l, rprev = r;
        }
        cout<<(ans+1)%MOD<<end;
      }
    }

    return 0;
}
