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
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define rep(i,n)     for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
ll gcd(ll a, ll b){if (a == 0) return b;return gcd(b%a, a);}
ll lcm(ll a, ll b){return a * (b / gcd(a, b));}
ll Abs(ll a){if( a > 0)return a;return -a;}
double Abs(double a){if( a > 0)return a;return -a;}

ll power(ll x,ll y)
{
  if(y==0)return 1;
  if(y%2==1)return power(x*x,y/2)*x;
  return power(x*x,y/2);
}
const int MAX = 100009;
const int MOD = 1e9+7;
ll n,vis[MAX],v[MAX],inc[MAX],Dec[MAX];vll adj[MAX];

void dfs(ll i)
{
  vis[i]=1;

  ll val=v[i],Mi=0,Md=0;
  rep(j,sz(adj[i]))
  {
    ll u=adj[i][j];
    if(vis[u]==0)dfs(u),Mi=max(Mi,inc[u]),Md=max(Md,Dec[u]);
  }
  val+=Mi-Md;
  if(val>0)Md+=val;
  else Mi-=val;
  inc[i]=Mi,Dec[i]=Md;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>n;
    rep(i,n-1)
    {
      ll a,b;cin>>a>>b;a--,b--;
      adj[a].pb(b),adj[b].pb(a);
    }
    rep(i,n)cin>>v[i];

    dfs(0);
    cout<<inc[0]+Dec[0]<<end;



    return 0;
}
