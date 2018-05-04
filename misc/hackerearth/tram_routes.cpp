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
// #define end '\n'
#define fi first
#define se second
#define PI 3.14159265

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


const int MAX = 100009;
const int MAX2 = 10009;
const int MOD = 1e9+7;
ll cnt[MAX2]= {0}, res[2][MAX2]; vll rou[MAX2]; vpp p;
std::map<ll, bool> mp;
std::map<ll, bool> chosen;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n, m, q;cin>>n>>m>>q;

    for (ll i = 0; i < m; i++) {
      ll tmp;
      cin>>tmp>>cnt[i];

      p.pb(mp(tmp, i));

      for (size_t j = 0; j < cnt[i]; j++) {
        ll tmp; cin>>tmp;
        rou[i].pb(tmp);
      }
    }

    for (size_t i = 0; i < q; i++) {
      ll a, b;cin>>a>>b;
      if(a < b)
      {
        res[0][i]= a;
        res[1][i]= b;
      }
      else
      {
        res[0][i]= b;
        res[1][i]= a;
      }
    }

    sortA(p);

    ll ans = 0;
    for (size_t k = 0; k < m; k++) {
      ll i = p[k].se;

      for (size_t j = 0; j < cnt[i]; j++) {
        ll u = rou[i][j];
        if(mp[u] == 0)
        {
          mp[u] = 1;
          if(chosen[i] == 0)
          {
            chosen[i] = 1;
            ans++;
          }
        }
      }
    }

    cout << ans <<"\n";
    for (size_t i = 0; i < m; i++) {
      if(chosen[i] == 1)
      {
        cout << i+1<<" ";
      }
    }

    return 0;
}
