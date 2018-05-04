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
const int MAX = 1009;
const int MOD = 1e9+7;

ll n,m,x,y,dp[MAX][2],c[MAX];
ll func(ll i,ll t)
{

  if(dp[i][t]!=-1)return dp[i][t];
  if(i==0)return dp[0][0]=dp[0][1]=0;
  if(i<x&&t==0)return dp[i][0]=c[i];
  if(i<x&&t==1)return dp[i][1]=n*i-c[i];
  ll ans=1e8;
  dp[i][t]=0;
  if(t==0)repA(k,x,min(y,i))if(i-k>=x||i-k==0)ans=min(ans,func(i-k,1)+c[i]-c[i-k]);
  if(t==1)repA(k,x,min(y,i))if(i-k>=x||i-k==0)ans=min(ans,func(i-k,0)+n*k-c[i]+c[i-k]);
  return dp[i][t]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>n>>m>>x>>y;
    string s[MAX];
    rep(i,n)cin>>s[i];
    fillA(dp);

    c[0]=0;
    rep(j,m)rep(i,n)
    {
      if(s[i][j]=='.')
        c[j+1]+=1;
    }
    rep(j,m)c[j+1]+=c[j];
    dp[1][0]=c[1],dp[1][1]=n-c[1];

    // cout<<func(2,1);
    cout<<min(func(m,0),func(m,1));

    return 0;
}
