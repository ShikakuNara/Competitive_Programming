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
#define rep(i, n)     for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(ll i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

// Functions
struct Rcompare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X>rhs.X;
  }
}; struct compare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X<rhs.X;
  }
};


ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * (b / gcd(a, b));
}
ll Abs(ll a){
  if( a > 0)
    return a;

  return -a;
}
double Abs(double a){
  if( a > 0)
    return a;

  return -a;
}

const int MAX = 100009;
const int MOD = 1e9+7;


vll adj[26];
std::set<int> mpo[26];
std::set<int> mpi[26];
ll vis[26]={0};
std::vector<char> ans; ll f=0;

void dfs2(ll i)
{
  vis[i]=1;
  if(sz(adj[i])==0||f==1) {vis[i]=2;return;}

  ll u=adj[i][0];
  if(vis[u]==0) dfs2(u);
  else if(vis[u]==1){cout<<"NO\n";f=1;}

  vis[i]=2;
}

void dfs(ll i)
{
  vis[i]=1;
  ans.pb(char(i+'a'));
  if(sz(adj[i])==0||f==1) return;

  ll u=adj[i][0];
  if(vis[u]==0) dfs(u);

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n;cin>>n;
    string a[MAX];
    rep(i,n)cin>>a[i];

    ll exis[26]={0};
    rep(i,n)
    {

      rep(j,sz(a[i])-1)
      {
        ll x=a[i][j]-'a',y=a[i][j+1]-'a';

        if(x==y){cout<<"NO\n";return 0;}

        exis[x]=1,exis[y]=1;

        mpo[x].insert(y);mpi[y].insert(x);

        adj[x].pb(y);
      }
      exis[a[i][sz(a[i])-1]-'a']=1;
    }

    rep(i,26)
    {
      if(mpi[i].size()<2&&mpo[i].size()<2) continue;
      else{cout<<"NO\n"; return 0; }
    }

    rep(i,26)
    {
      if(vis[i]==0&&exis[i]==1) dfs2(i);
      if(f==1)return 0;
    }
    fill(vis);

    rep(i,26)
    {
      if(vis[i]==0&&mpi[i].size()==0&&mpo[i].size()<=1&&exis[i]==1)
        dfs(i);
    }

    rep(i,sz(ans)) cout<<ans[i];



    return 0;
}
