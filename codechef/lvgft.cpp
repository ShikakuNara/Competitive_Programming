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

const int MAX = 1020;
const int MOD = 1e9+7;

vll adj[MAX]; ll n,e,b[MAX],vis[MAX],m[3]={-1,-1,-1};

void dfs(ll i, ll flag)
{
  vis[i] =1;
  flag|=b[i];

  if(flag == 1){m[0]=i;sort(m,m+3);}

  rep(j,sz(adj[i]))
  {
    ll u=adj[i][j];
    if(vis[u]==0)
    {
      dfs(u,flag);
    }
  }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    int t;cin>>t;
    rep(aja,t)
    {
      fill(b);cin>>n>>e;
      rep(i, n-1)
      {
        ll a,b;cin>>a>>b;a--,b--;
        adj[a].pb(b),adj[b].pb(a);
      }
      rep(i, e)
      {
        ll ty;cin>>ty;
        if(ty==1) {ll tmp;cin>>tmp;tmp--;b[tmp]=1;}
        else
        {
          ll c;cin>>c;c--;

          m[0]=-1,m[1]=-1,m[2]=-1,fill(vis);
          dfs(c,b[c]);
          if(m[1]!=-1)cout<<m[1]+1<<end;
          else cout<<-1<<end;
        }
      }
      rep(i, n) adj[i].clear();
    }

    return 0;
}
