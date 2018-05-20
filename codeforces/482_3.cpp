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

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 300009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

vll adj[MAX];ll vis[MAX],df[MAX],ds[MAX];
ll num[MAX];
ll t=0;

ll dfs(ll i){
  vis[i]=1;
  ds[i]=t++;

  ll siz=1;

  rep(j,sz(adj[i])){
    int u=adj[i][j];
    if(!vis[u])siz+=dfs(u);
  }

  df[i]=t++;
  return num[i]=siz;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll n,x,y;cin>>n>>x>>y;x--,y--;
    rep(i,n-1){
      ll u,v;cin>>u>>v;u--,v--;
      adj[u].pb(v);adj[v].pb(u);
    }

    dfs(0);
    // rep(i,n)cout<<num[i]<<',';cout<<endl;

    ll ans=n*(n-1);

    if(df[x]<ds[y]&&ds[x]<ds[y])ans-=num[x]*num[y];
    else if(df[y]<ds[x]&&ds[y]<ds[x])ans-=num[x]*num[y];
    else if(df[x]>df[y]&&ds[x]<ds[y]){
      ll tmp=n-num[x]+1;

      rep(j,sz(adj[x])){
        int u=adj[x][j];tmp+=num[u];
        if(df[u]>=df[y]&&ds[u]<=ds[y])tmp-=num[u];
      }
      ans-=(tmp)*num[y];
    }
    else if(df[y]>df[x]&&ds[y]<ds[x]){
      swap(x,y);
      ll tmp=n-num[x]+1;

      rep(j,sz(adj[x])){
        int u=adj[x][j];tmp+=num[u];
        if(df[u]>=df[y]&&ds[u]<=ds[y])tmp-=num[u];
      }
      ans-=(tmp)*num[y];
    }

    cout<<ans<<endl;

    return 0;
}
