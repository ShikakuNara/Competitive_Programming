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


const int MAX = 50009;
const int MOD = 1e9+7;

vll adj[MAX]; ll n, r1, r2, vis[MAX] = {0}, p[MAX]={0};

void dfs(ll i)
{
  vis[i] = 1;

  rep(j, sz(adj[i]))
  {
    ll u = adj[i][j];
    if(vis[u] == 0)
    {
      p[u] = i+1;
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

    cin >> n>>r1>>r2; r1--, r2--;

    rep(i, n)
    {
      if(i == r1) continue;
      ll tmp; cin>>tmp; tmp--;

      adj[i].pb(tmp);
      adj[tmp].pb(i);
    }

    dfs(r2);

    rep(i, n)
    {
      if(i == r2) continue;

      cout<<p[i]<<' ';
    }cout<<end;




    return 0;
}
