#include <bits/stdc++.h>

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
#define X first
#define Y second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

ll pow(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=pow(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int n,m,vis[MAX]={0},d[MAX],vis2[MAX]={0};
vi adj[MAX];

vi a;set<int> st;
bool dfs(int i){
  vis[i]=1;bool ff=false;

  if(st.find(i)!=st.end())vis[i]=2,ff=true;

  trav(j,adj[i])if(vis[j]==0)ff|=dfs(j);

  if(ff){vis[i]=2;return true;}
  return false;
}

void dfs2(int i,int dd){
  if(vis[i]!=2)return;

  vis2[i]=1;d[i]=dd;
  trav(j,adj[i])if(vis2[j]==0)dfs2(j,dd+1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif
    fillA(d);fill(vis),fill(vis2);

    cin>>n>>m;
    rep(i,n-1){
      int u,v;cin>>u>>v;
      adj[u].pb(v),adj[v].pb(u);
    }
    rep(i,m){int t;cin>>t;a.pb(t),st.insert(t);}

    sort(all(a));

    dfs(a[0]);int cnt=0;
    rep(i,n+2)if(vis[i]==2)cnt++;

    dfs2(a[0],0);pp ans=mp(0,0);
    int i=-1,mm=-2;
    repA(j,1,n+1)if(d[j]>mm)i=j,mm=d[j];

    ans=mp(i,2*(cnt-1)-mm);
    fillA(d),fill(vis2);
    dfs2(ans.X,0);

    i=-1,mm=-2;
    repA(j,1,n+1)if(d[j]>mm)i=j,mm=d[j];

    if(i<ans.X)ans=mp(i,2*(cnt-1)-mm);
    else ans=mp(ans.X,2*(cnt-1)-mm);

    cout<<ans.X<<endl<<ans.Y;

    return 0;
}
