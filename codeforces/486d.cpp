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
#define PI 3.14159265

const int MAX = 100009;
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
  if( a > b)
    return a-b;

  return b-a;
}
double abs(double a, double b){
  if( a > b)
    return a-b;

  return b-a;
}

ll d, n, a[MAX] = {0}, f[MAX] = {0}, vis[MAX] = {0}; vll adj[MAX];

void dfs(ll i, ll root)
{
  if(vis[i] == 1)
    return;

  vis[i] = 1;
  f[i] = 1;

  for (ll j = 0; j < sz(adj[i]); j++) {
    ll u = adj[i][j];
    if( vis[u] == 0)
    {
      if(a[u] < a[root] || a[u] > a[root] + d) continue;
      if(a[u] == a[root] && u < root) continue;

      dfs(u, root);
      f[i] *= (f[u] + 1);
      f[i] __;
    }
  }

  return ;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>d>>n;
    for (size_t i = 0; i < n; i++) {
      cin>>a[i];
    }
    for (size_t i = 0; i < n-1; i++) {
      ll u, v; cin >> u >> v; u--, v--;
      adj[u].pb(v);
      adj[v].pb(u);
    }

    ll sum = 0;
    for (size_t i = 0; i < n; i++) {
      dfs(i, i);
      
      sum += f[i];
      sum __;

      fill(f);fill(vis);
    }


    for (size_t i = 0; i < n; i++) {
      sum += f[i];
      sum __;
    }

    cout<<sum<<end;

    return 0;
}
