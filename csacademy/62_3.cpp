#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef vector<pp > vpp;

#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define trav(a, x) for(auto& a : x)
#define rep(i,n)     for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second
#define endl '\n'

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

ll pow(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=pow(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 1009;
const int MOD = 1e9+7;

int vis[MAX]={0},ff=0;
vi adj[MAX];

int x,y=-1;

int p=1e9+7,pw=p,v=0,w=0;

int dfs1(ll i)
{
  // cout<<i<<endl;
  vis[i]=1;

  rep(j,sz(adj[i]))
  {
    int u=adj[i][j];vis[i]=1;
    if(vis[u]==0)
    {
      if(u==y){v+=u*pw,pw*=p,v+=i*pw,pw*=p;return 1;}
      if(dfs1(u)==1){v+=i*pw,pw*=p;return 1;}
    }
  }

  return 0;
}

int dfs2(ll i)
{
  // cout<<i<<endl;
  vis[i]=1;

  repD(j,sz(adj[i])-1,0)
  {
    int u=adj[i][j];vis[i]=1;
    if(vis[u]==0)
    {
      if(u==y){w+=u*pw,pw*=p,w+=i*pw,pw*=p;return 1;}
      if(dfs2(u)==1){w+=i*pw,pw*=p;return 1;}
    }
  }
  return 0;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int n,m,q;cin>>n>>m>>q;

    rep(i,m)
    {
      int x,y;cin>>x>>y;
      adj[x].pb(y),adj[y].pb(x);
    }

    rep(i,q)
    {
      cin>>x>>y;
      v=w=0;
      fill(vis);pw=p;
      dfs1(x);
      fill(vis);pw=p;
      dfs2(x);

      if(w==v)cout<<1<<endl;
      else cout<<0<<endl;
    }




    return 0;
}
