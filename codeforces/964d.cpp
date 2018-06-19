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

const int MAX = 400009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll deg[MAX],vis[MAX],dep[MAX];
vll adj[MAX];

void dfs(int i,int d){
  vis[i]=1;
  dep[i]=d++;
  rep(j,sz(adj[i])){
    int u=adj[i][j];
    if(!vis[u])dfs(u,d);
  }
}

priority_queue< ppp >pq;
set< ppp > st;
vll ans;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    int n;cin>>n;
    rep(i,n){
      int p;cin>>p;p--;
      if(p==-1)continue;
      adj[i].pb(p),adj[p].pb(i);
      deg[i]++,deg[p]++;
    }

    dfs(0,1);fill(vis);

    rep(i,n)if(deg[i]%2==0)pq.push(mp(dep[i],mp(i,deg[i])));
    ll cnt=0;
    while(!pq.empty()){
      ppp c=pq.top();pq.pop();
      if(st.find(c)!=st.end()){st.erase(c);continue;}

      int i=c.snd.fst;
      vis[i]=1;cnt++;ans.pb(i);

      rep(j,sz(adj[i])){
        int u=adj[i][j];
        if(vis[u])continue;
        deg[u]--;
        if(deg[u]%2==0)pq.push(mp(dep[u],mp(u,deg[u])));
        else st.insert(mp(dep[u],mp(u,deg[u]+1)));
      }
    }

    if(cnt==n){
      cout<<"YES\n";
      trav(it,ans)cout<<it+1<<endl;
    }
    else cout<<"NO\n";


    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
