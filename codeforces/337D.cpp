#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <ll> vi;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;

#define sz(a) (ll)((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define rep(i,n)     for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
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
const ll MAX = 400009;
const ll MOD = 1e9+7;
const ll inf = 1e17;

ll mar[MAX]={0},ddwn[MAX],ddwn2[MAX],dup[MAX],vis[MAX]={0},p[MAX];
vi adj[MAX];


ll dfs1(ll i)
{
  vis[i]=1;
  ll ans=-inf+1,ans2=-inf+1;

  rep(j,sz(adj[i]))
  {
    ll u=adj[i][j];
    if(vis[u]==0)
    {
      p[u]=i;
      ll tmp=1+dfs1(u);
      // if(i==4)cout<<ans<<','<<ans2<<":"<<tmp<<endl;
      if(ans<tmp)
      {
        ans2=ans;
        ans=tmp;
      }
      else if(ans2<tmp)
      {
        ans2=ans;
      }
      // if(i==4)cout<<ans<<','<<ans2<<":"<<tmp<<endl<<endl;
    }
  }

  if(mar[i]==1)ans=max(ans,0LL);

  if(ans<-1e16)ans=-inf;
  if(ans2<-1e16)ans2=-inf;
  ddwn2[i]=ans2;
  return ddwn[i]=ans;
}

void dfs2(ll i)
{
  vis[i]=1;
  if(p[i]==-1)dup[i]=-inf;
  else
  {
    ll tmp=ddwn[p[i]];
    if(1+ddwn[i]==tmp)dup[i]=1+ddwn2[p[i]];
    else dup[i]=1+tmp;

    dup[i]=max(dup[i],1+dup[p[i]]);
  }
  if(mar[i]==1)dup[i]=max(dup[i],0LL);

  rep(j,sz(adj[i]))
  {
    ll u=adj[i][j];
    if(vis[u]==0)dfs2(u);
  }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll n,m,d;cin>>n>>m>>d;
    rep(i,m){ll tmp;cin>>tmp;mar[tmp-1]=1;}
    rep(i,n-1)
    {
      ll a,b;cin>>a>>b;a--,b--;
      adj[a].pb(b),adj[b].pb(a);
    }
    fillA(ddwn),fillA(ddwn2),fillA(dup),fillA(p);

    dfs1(0);fill(vis);
    dfs2(0);

    ll cnt=0;
    rep(i,n)if(dup[i]<=d&&ddwn[i]<=d)cnt++;
    cout<<cnt<<endl;

    return 0;
}
