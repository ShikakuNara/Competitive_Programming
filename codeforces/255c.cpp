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
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define rep(i,n)     for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

ll power(ll x,ll y)
{
  if(y==0)return 1;
  if(y%2==1)return power(x*x,y/2)*x;
  return power(x*x,y/2);
}
const int MAX = 4009;
const int MOD = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n;cin>>n;
    ll j=1,a,cnt[MAX];
    std::map<ll, ll> mp;
    vll adj[MAX];
    rep(i,n)
    {
      cin>>a;
      if(mp[a]==0)mp[a]=j,adj[j].pb(i),cnt[j]++,j++;
      else adj[mp[a]].pb(i),cnt[mp[a]]++;
    }


    if(n==1){cout<<1;return 0;}
    ll m=j,M=1;
    repA(a,1,m-1)M=max(M,cnt[a]);
    repA(a,1,m-1)repA(b,1,m-1)
    {
      if(a==b)continue;
      ll i=0,j=0;
      ll cnt=0;
      while(i<sz(adj[a])&&j<sz(adj[b]))
      {
        while(j<sz(adj[b])&&adj[b][j]<adj[a][i])j++;
        if(j<sz(adj[b]))cnt++;
        else break;

        while(i<sz(adj[a])&&adj[a][i]<adj[b][j])i++;
        if(i<sz(adj[a]))cnt++;
        else break;
      }
      if(i==sz(adj[a])&&j<sz(adj[b]))cnt++;
      if(j==sz(adj[b])&&i<sz(adj[a]))cnt++;
      M=max(M,cnt);
    }
    cout<<M<<end;

    return 0;
}
