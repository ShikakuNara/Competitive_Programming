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

const int MAX = 300009;
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

ll n;
vll adj[MAX], node[2];
ll start[2][MAX]= {0}, EEnd[2][MAX]= {0}, vis[MAX]= {0}, lvl[MAX] = {0};

ll ft0[MAX+1] = {0};
void update0(ll x, ll v)
{
  x++;    //indexing change
  for (; x <= n; x += (ll)(x&(-x))) ft0[x] += v;
}
void update0(ll a, ll b, ll v)
{
  update0(b+1, -v);
  update0(a, v);
}
ll get0(ll x)
{
  x++;    //indexing change
  ll sum = 0;
  for ( ; x; x -= (ll)(x&(-x))) {
    sum += ft0[x];
  }
  return sum;
}

ll ft1[MAX+1] = {0};
void update1(ll x, ll v)
{
  x++;    //indexing change
  for (; x <= n; x += (ll)(x&(-x))) ft1[x] += v;
}
void update1(ll a, ll b, ll v)
{
  update1(b+1, -v);
  update1(a, v);
}
ll get1(ll x)
{
  x++;    //indexing change
  ll sum = 0;
  for ( ; x; x -= (ll)(x&(-x))) {
    sum += ft1[x];
  }
  return sum;
}

void dfs(ll i, ll step)
{
  vis[i] = 1;
  node[step].pb(i); lvl[i] = step;

  for (size_t j= 0; j < sz(adj[i]); j++) {
    ll u = adj[i][j];

    if(vis[u] == 0)
    {
      start[0][u] = node[0].size();
      start[1][u] = node[1].size();

      dfs(u, (step+1)%2);
    }
  }


  EEnd[0][i] = node[0].size();
  EEnd[1][i] = node[1].size();

  return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll m;cin>>n>>m;

    ll a[MAX] = {0};
    for (size_t i = 0; i < n; i++) cin >> a[i];

    for (size_t i = 0; i < n-1; i++) {
      ll a, b; cin>>a>>b; a--, b--;
      adj[a].pb(b);
      adj[b].pb(a);
    }

    dfs(0, 0);

    for (size_t i = 0; i < m; i++) {
      ll tmp; cin>> tmp;
      if(tmp == 1)
      {
        ll x, val; cin>>x>>val; x--;
        if(lvl[x] == 0)
        {
          update0(start[0][x], EEnd[0][x]-1, val);
          update1(start[1][x], EEnd[1][x]-1, -val);
        }
        else
        {
          update0(start[0][x], EEnd[0][x]-1, -val);
          update1(start[1][x], EEnd[1][x]-1, val);
        }
      }
      else
      {
        ll x; cin>>x; x--;

        if(lvl[x] == 0){
          cout <<  a[x] + get0(start[0][x])<<end;
        }
        else
        {
          cout << a[x] +  get1(start[1][x])<<end;
        }
      }
    }


    return 0;
}
