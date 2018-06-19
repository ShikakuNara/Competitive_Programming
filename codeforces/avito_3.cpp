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


vll adj[MAX];int vis[MAX];

int dfs(int i){
  vis[i]=1;
  rep(j,sz(adj[i])){
    int u=adj[i][j];
    if(!vis[u])return dfs(u);
  }
  return i;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    int n;cin>>n;
    rep(i,n-1){
      int x,y;cin>>x>>y;x--,y--;
      adj[x].pb(y);
      adj[y].pb(x);
    }

    int an=-1,a2=-1;
    rep(i,n){
      if(sz(adj[i])>2&&an==-1)an=i;
      else if(sz(adj[i])>2){cout<<"No\n";return 0;}
      if(sz(adj[i])==2)a2=i;
    }

    int b=0;
    if(an!=-1)b=an;
    else if(a2!=-1)b=a2;

    int cnt=0;vll ans;
    vis[b]=1;
    rep(i,sz(adj[b])){
      int u=adj[b][i];
      if(!vis[u])cnt++,ans.pb(dfs(u));
    }

    cout<<"Yes\n";
    cout<<cnt<<endl;
    trav(i,ans)cout<<b+1<<' '<<i+1<<endl;



    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
