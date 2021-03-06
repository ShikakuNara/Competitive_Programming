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
// double Abs(double a){
//   if( a > 0)
//     return a;
//
//   return -a;
// }

const int MAX = 400009;
const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


    ll n, p;cin>>n>>p;

    if(p > n/2) p = n-p+1;
    p--;

    string a; cin>>a;
    ll M = -1, m = -1;
    repD(i, n/2-1, 0)
    {
      if(a[i] != a[n-i-1]){ M = i; break;}
    }
    repA(i, 0, n/2-1)
    {
      if(a[i] != a[n-i-1]){ m = i; break;}
    }

    ll ans = 0;
    if(M == -1)
    {

    }
    else if(m <= p && M >= p)
    {
      ans += Abs(p-M) + Abs(p-m);
      ans += min(Abs(p-M), Abs(p-m));
    }
    else if(m <= p && M <= p)
    {
      ans+= Abs(p-m);
    }
    else if(m >= p && M >= p)
    {
      ans+= Abs(p-M);
    }


    repA(i, 0, n/2-1)
    {
      if(a[i] != a[n-i-1])
      {
        ll tmp = Abs( a[n-i-1] - a[i] );
        ans += min(tmp, 26-tmp);
      }
    }

    cout << ans<<end;




    return 0;
}
