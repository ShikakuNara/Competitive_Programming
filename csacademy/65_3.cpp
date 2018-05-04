#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")

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
const int MAX = 100009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int cnt=0,n,vis[MAX]={0},d[MAX],p[MAX];
vi adj[MAX],ans,pi,pj;
void dfs(int i){
  // if(cnt>=n)return;
  vis[i]=1;
  // cnt++;
  ans.pb(i);
  // if(cnt>=n)return;
  int ff=0;
  trav(j,adj[i])if(vis[j]==0){
    if(ff==0)ff=1;
    else ans.pb(i);
    dfs(j);
    // if(cnt>=n)return;
  }
  if(ff==1)ans.pb(i);
}
void dfsp(int i){
  vis[i]=1;
  trav(j,adj[i]){
    if(vis[j]==0)dfsp(j);
    else p[i]=j;
  }
}
void dfs2(int i,int dd){
  vis[i]=1;d[i]=dd;
  trav(j,adj[i])if(vis[j]==0)dfs2(j,dd+1);
}
void pathi(int i){
  vis[i]=1;
  pi.pb(i);
  if(i==1||p[i]==-1)return;
  pathi(p[i]);
}
void pathj(int i){
  vis[i]=1;
  pj.pb(i);
  if(i==1||p[i]==-1)return;
  pathj(p[i]);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif
    fillA(d),fillA(p);

    cin>>n;
    rep(i,n-1){
      int u,v;cin>>u>>v;
      adj[u].pb(v),adj[v].pb(u);
    }dfsp(1);

    fill(vis);
    dfs2(1,0);fill(vis);
    int i=max_element(d,d+n+1)-d;fillA(d);
    dfs2(i,0);
    int j=max_element(d,d+n+1)-d;

    fill(vis);pathi(i);fill(vis);pathj(j);

    reverse(all(pj));
    trav(i,pj)if(i!=1)pi.pb(i);
    trav(i,pi)vis[i]=1;

    trav(i,pi)dfs(i);

    cout<<sz(ans)-1<<endl;
    trav(i,ans)cout<<i<<' ';cout<<endl;


    return 0;
}
