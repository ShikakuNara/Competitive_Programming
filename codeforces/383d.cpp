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
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'
#define fi first
#define se second
#define PI 3.14159265

const int MAX = 500;
const int MOD = 1e9+7;

#define __ %= MOD;

// Functions
ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
ll abs(ll a, ll b){
  if( a > b) return a-b;
  return b-a;
}
double abs(double a, double b){
  if( a > b)
    return a-b;

  return b-a;
}

bool comp(pp a, pp b)
{
  if(a.se > b.se)
    return 0;
  else if(a.se < b.se)
    return 1;
  else if(a.fi > b.fi)
    return 1;

  return 0;
}

ll maxi(ll a, ll b)
{
  if(a > b) return a;
  return b;
}

ll d[1010][20010] = {0}, a[1010], sum = 0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n; cin>>n;

    for (size_t i = 0; i < n; i++) {
      cin >> a[i]; sum += a[i];
    }
    // cout<<sum<<end;
    // d[0][sum] = 1;
    for (ll i = -sum; i <= sum; i++) {
      if(i == a[0] || i == -a[0])
        d[0][i+sum] = 1;
    }

    for (ll i = 1; i < n; i++) {
      for (ll j = -sum; j <= sum; j++) {
          d[i][sum+j] = d[i-1][sum+j-a[i]] + d[i-1][sum+j+a[i]];
          d[i][sum+j] __;

          if(j == a[i] || j == -a[i])
          {
            d[i][j+sum] += 1; d[i][sum+j] __;
          }
      }
    }

    ll ans = 0;
    for (size_t i = 0; i < n; i++) {
      ans += d[i][sum];
      ans __;
      /* code */
    }
    cout<<ans<<end;


    return 0;
}
