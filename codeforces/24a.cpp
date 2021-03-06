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

vll adj[MAX]; ll n, vis[MAX] = {0}, cost[MAX][MAX], sum = 0;

void dfs(ll i)
{
  vis[i] = 1;

  rep(j, sz(adj[i]))
  {
    ll u = adj[i][j];
    if(vis[u] == 0)
    {
      sum+= cost[i][u];
      dfs(u);
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

    cin >> n;

    rep(i, n)
    {
      ll a,b,c; cin>>a>>b>>c; a--, b--;

      adj[a].pb(b); cost[a][b] = 0;
      adj[b].pb(a); cost[a][b] = c;
    }

    ll mmax = 0;

    vis[0] = 1;
    sum += cost[0][adj[0][0]];
    dfs(adj[0][0]);
    sum += cost[adj[0][1]][0];

    fill(vis); mmax = sum; sum = 0;

    vis[0] = 1;
    sum += cost[0][adj[0][1]];
    dfs(adj[0][1]);
    sum += cost[adj[0][0]][0];


    cout << min(mmax, sum);

    return 0;
}
