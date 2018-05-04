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

vpp adj[MAX];
ll n, m, vis[MAX] = {0}, l, r;
map<int, map<int, int> > dp;

void dfs(ll i)
{
  vis[i] = 1;

  for (size_t j = 0; j < sz(adj[i]); j++)
  {
    // cout<< "a : "<<i<<", "<<adj[i][j].fi<<", " << vis[adj[i][j].fi] <<", "<<  adj[i][j].se<<end;
    if( vis[adj[i][j].fi] == 0 && (adj[i][j].se < l || adj[i][j].se > r) )
    {
      // cout<<"b: "<< i<<", "<<adj[i][j].fi<<end;
      dfs(adj[i][j].fi);
    }
  }

  return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin >> n >>m;

    for (size_t i = 0; i < m; i++) {
      ll a, b; cin>>a>>b; a--; b--;

      adj[a].pb(mp(b, i)); adj[b].pb(mp(a, i));
    }

    ll k; cin>>k;

    for (size_t i = 0; i < k; i++) {
      cin>>l>>r; l--, r--;

      if(dp[l][r] != 0)
      {
         cout<<dp[l][r]<<end; continue;
      }

      fill(vis); ll ans = 0;

      for (size_t i = 0; i < n ; i++) {
        if(vis[i] == 0)
        {
          dfs(i); ans++;
        }
      }

      dp[l][r] = ans;
      cout<<ans<<end;
    }

    return 0;
}
