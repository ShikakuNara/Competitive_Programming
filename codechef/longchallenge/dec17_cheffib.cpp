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
const int MAX = 3009;
const int MOD = 1e9+7;

ll f[MAX],val[MAX]={0},vis[MAX]={0};
vll adj[MAX];
void dfs(ll i,ll d,ll k)
{
	if(d>k)return;
	vis[i]=1;
	val[i]=(val[i]+f[d])%MOD;
	rep(j,sz(adj[i]))if(vis[adj[i][j]]==0)dfs(adj[i][j],d+1,k);
	return;
}
void query(ll v,ll k, ll a,ll b)
{
	f[0]=a,f[1]=b;
	repA(i,2,MAX-1)f[i]=(f[i-1]+f[i-2])%MOD;

	fill(vis);
	dfs(v,0,k);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll t;cin>>t;
	
    rep(aa,t)
    {
	fill(val);//fill(adj);
	rep(i,MAX)adj[i].clear();
	ll n,q;cin>>n>>q;
	rep(i,n-1){ll x,y;cin>>x>>y;x--,y--;adj[x].pb(y),adj[y].pb(x);}
	//query(0,n-1,0,0);

	rep(i,q)
	{
		ll t,v;cin>>t>>v;v--;
		if(t==1){ll k,a,b;cin>>k>>a>>b;query(v,k,a,b);}
		else cout<<val[v]<<end;
	}
    }	    

    return 0;
}

