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
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

ll power(ll x,ll y)
{
  if(y==0)return 1;
  if(y%2==1)return power(x*x,y/2)*x;
  return power(x*x,y/2);
}
const int MAX = 100009;
const int MOD = 1e9+7;

vll adj[MAX],adj2[MAX];
ll nn,vis[MAX],val[MAX],cnt=0,ff=0,gg=0;
std::priority_queue<ll> pq;
ll chk(ll i)
{
  if(ff==1)return 0;
  vis[i]=1;
  rep(j,sz(adj[i]))
  {
    if(ff==1)break;

    ll u=adj[i][j];
    if(vis[u]==0)chk(u);
    else if(vis[u]==1)ff=1;
  }
  vis[i]=2;
  return 0;
}
void dfs(ll i)
{
  if(gg==1)return;
  vis[i]=1;
  rep(j,sz(adj[i]))
  {
    ll u=adj[i][j];
    if(gg==1)return;
    if(vis[u]==0&&pq.empty()){gg=1;return;}
    if(vis[u]==0)val[u]=-pq.top(),pq.pop(),dfs(u);
  }
}

stack<ll> stk;
void topo(ll i)
{
    vis[i] = 1;
    rep(j,sz(adj[i]))
    {
      ll u=adj[i][j];
      if(vis[u]==0)topo(u);
    }
    stk.push(i);
}
void topo2(ll i)
{
    vis[i]=1;
    rep(j,sz(adj2[i]))
    {
      ll u=adj2[i][j];
      if(vis[u]==0)topo(u);
    }
    stk.push(i);
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll n,k,m;cin>>n>>k>>m;
    ll p[MAX],c[MAX];
    rep(i,m)cin>>p[i];
    ll fi[MAX];

    fi[0]=p[0];
    rep(i,n-1)
    {
      rep(i,m)cin>>c[i];
      fi[i+1]=c[0];
      rep(i,m)if(c[i]!=p[i]){adj[p[i]].pb(c[i]);break;}
      rep(i,m)p[i]=c[i];
    }

    std::map<ll, ll> mp;
    rep(i,n)mp[fi[i]]=1;
    rep(i,k)rep(j,sz(adj[i]))
    {
      ll u=adj[i][j];
      if(mp.find(i)!=mp.end()||mp.find(u)!=mp.end())adj2[i].pb(u);
    }
    //cycle check
    rep(i,k)if(vis[i]==0&&chk(i)==0&&ff==1){cout<<-1;return 0;}


    fill(vis);repA(i,1,k-1)pq.push(-i);

    rep(i,k)if(vis[i]==0&&mp.find(i)!=mp.end())topo2(i);//add to the rest
    while (!stk.empty()&&!pq.empty())val[stk.top()]=-pq.top(),pq.pop(),stk.pop();

    if(pq.empty()&&!stk.empty()){cout<<-1;return 0;}


    pq.push(0);
    rep(i,k)if(vis[i]==0)topo(i);//add to the rest
    while (!stk.empty())val[stk.top()]=-pq.top(),pq.pop(),stk.pop();

    rep(i,k)cout<<val[i]<<' ';


    return 0;
}
