#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")

using namespace std;
#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a,b) (make_pair((a),(b)) )
#define all(c)  (c).begin(),(c).end()
#define fill(a) (memset((a), 0, sizeof (a)))
#define fillA(a) (memset((a), -1, sizeof (a)))
#define trav(a,x) for(auto& (a):(x))
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=(a);i<=(n);++i)
#define repD(i,a,n) for(int i=(a);i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define fst first
#define snd second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<ll, ll> pp;
typedef pair<ll, pp> ppp;
typedef vector<pp > vpp;

#ifdef LOCAL_TEST
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll vis[MAX],a[MAX],b[MAX],c[MAX],d[MAX],v[MAX];
vll adj[MAX];

bool diff(ll i,ll j){
  ll k=max(v[i],v[j]);
  ll tk=1,lk=0;while(tk<=k)tk*=2,lk++;
  ll ans=0;
  rep(k,lk)if((v[i]^v[j])&(1LL<<k))
    ans^=1;//cout<<i<<','<<j<<":"<<i<<endl;
  return ans;
}

void dfs1(ll i){
  vis[i]=1;
  a[i]=0,b[i]=1;

  rep(j,sz(adj[i])){
    ll u=adj[i][j];
    if(!vis[u]){
      dfs1(u);
      if(diff(i,u))a[i]+=a[u],b[i]+=b[u];
      else a[i]+=b[u],b[i]+=a[u];
    }
  }
}

void dfs2(ll i,ll p){
  vis[i]=1;
  c[i]=0,d[i]=0;
  if(p!=-1){
    if(diff(i,p))
      c[i]=c[p]+a[p]-a[i],
      d[i]=d[p]+b[p]-b[i];
    else
      c[i]=d[p]+b[p]-a[i],
      d[i]=c[p]+a[p]-b[i];
  }


  rep(j,sz(adj[i])){
    ll u=adj[i][j];
    if(!vis[u])dfs2(u,i);
  }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif


    int t;cin>>t;
    rep(aa,t){
      fill(a),fill(b),fill(c),fill(d),fill(vis);
      rep(i,MAX)adj[i].clear();

      ll n;cin>>n;
      rep(i,n-1){
        ll u,v;cin>>u>>v;u--,v--;
        adj[u].pb(v),adj[v].pb(u);
      }
      rep(i,n)cin>>v[i];

      dfs1(0);
      fill(vis);
      dfs2(0,-1);

      // cout<<diff(0,1)<<','<<diff(0,2)<<','<<diff(1,2)<<endl;

      ll ans=0;
      rep(i,n)ans+=a[i]+c[i];
      // rep(i,n)cout<<a[i]<<',';cout<<endl;
      // rep(i,n)cout<<b[i]<<',';cout<<endl;
      // rep(i,n)cout<<c[i]<<',';cout<<endl;
      // rep(i,n)cout<<d[i]<<',';cout<<endl;
      cout<<ans/2<<endl;
    }


    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
