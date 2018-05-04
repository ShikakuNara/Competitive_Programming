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
#define end '\n'

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
ll vis[MAX],val[MAX],cnt=0,ff=0,gg=0;
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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll n,k,m;cin>>n>>k>>m;
    ll p[MAX],c[MAX];
    rep(i,m)cin>>p[i];

    ll fi[MAX]={0};fi[p[0]]=1;

    rep(i,n-1)
    {
      rep(i,m)cin>>c[i];
      fi[c[0]]=1;
      rep(i,m)if(c[i]!=p[i]){adj[p[i]].pb(c[i]),adj2[c[i]].pb(p[i]);break;}
      rep(i,m)p[i]=c[i];
    }

    //cycle check
    rep(i,k)if(vis[i]==0&&chk(i)==0&&ff==1){cout<<-1;return 0;}

    ll done=0;fill(vis);
    rep(i,k)if(fi[i]==0&&sz(adj2[i])==0){vis[i]=1,val[i]=0,done=1;break;}
    if(done==0){cout<<-1;return 0;}

    repA(i,1,k-1)pq.push(-i);
    rep(i,k)if(vis[i]==0)topo(i);//add to the rest

    while (!stk.empty())
    {
      if(pq.empty()){cout<<-1;return 0;}
      val[stk.top()]=-pq.top(),pq.pop(),stk.pop();
    }

    rep(i,k)cout<<val[i]<<' ';


    return 0;
}
