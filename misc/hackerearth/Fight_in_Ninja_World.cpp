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

const int MAX = 100009;
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
vll adj[MAX]; ll vis[MAX] = {0};

void dfs(ll i, ll &r, ll &b, ll prev)
{
  vis[i] = 1;

  if(prev == 1)
    r++;
  else b++;

  for (size_t j = 0; j < sz(adj[i]); j++) {
    if(vis[adj[i][j]] == 0)
    {
      if(prev == 1)
        dfs(adj[i][j], r, b, 0);
      else
        dfs(adj[i][j], r, b, 1);
    }
  }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll t; cin>> t;
    for (size_t skjsk = 0; skjsk < t; skjsk++) {

      ll n; cin>>n;
      std::map<ll, ll> mp;

      for (size_t i = 0; i < MAX; i++) {
        adj[i].clear();
      }

      fill(vis); ll j = 1;
      for (size_t i = 0; i < n; i++) {
        ll a, b;cin>>a>>b;

        if(mp[a] == 0)
        {
          mp[a] = j, j++;
        }
        if(mp[b] == 0)
        {
          mp[b] = j, j++;
        }
        a = mp[a], b = mp[b];
        adj[a].pb(b);
        adj[b].pb(a);
      }

      ll MM = 0;
      for (size_t i = 1; i < j; i++) {
        ll r = 0, b = 0;
        if( vis[i] == 0)
          dfs(i, r, b, 0);

        MM += max(r, b);
      }

      cout << "Case " << skjsk+1<< ": "<< MM << end;
    }


    return 0;
}
