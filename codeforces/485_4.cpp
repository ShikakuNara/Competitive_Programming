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

const int MAX = 100009;
const int MOD = 1e9+7;
const int inf = 1e9+10;


ll c[MAX], dp[MAX][109]={0};int vis[MAX];
vll adj[MAX];


ll dfs(int i,int j){
  vis[i]=1;

  if(c[i]==j)dp[i][j]=0;

  rep(x,sz(adj[i])){
    int u=adj[i][x];
    dp[u][j]=min(dp[u][j],1+dp[i][j]);//update child

    if(c[u]==j)dp[i][j]=min(dp[i][j],1LL);//update parent
    dp[i][j]=min(dp[i][j],1+dp[u][j]);//update parent


    if(!vis[u])dp[i][j]=min(dp[i][j],1+dfs(u,j));//update parent
  }
  return dp[i][j];
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    int n,m,k,s;cin>>n>>m>>k>>s;
    rep(i,n)cin>>c[i],c[i]--;

    rep(i,m){
      int x,y;cin>>x>>y; x--,y--;
      adj[x].pb(y),adj[y].pb(x);
    }

    rep(i,MAX)rep(j,109)dp[i][j]=1e15;

    rep(j,k){
      fill(vis);
      rep(i,n)if(!vis[i])dfs(i,j);
      fill(vis);
      rep(i,n)if(!vis[i])dfs(i,j);
    }

    rep(i,n){
      ll tmp=0;vll v;
      rep(j,k)v.pb(dp[i][j]);
      sort(all(v));
      rep(j,s)tmp+=v[j];
      cout<<tmp<<' ';
    }



    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
