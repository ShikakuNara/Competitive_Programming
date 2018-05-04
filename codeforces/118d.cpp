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
const int MAX = 400009;
const int MOD = 1e8;

ll dp[101][101][2];
ll n,m,k,l;
ll func(ll i,ll j,ll t)
{
  if(dp[i][j][t]!=-1)return dp[i][j][t];
  if((i==0&&t==0)||(j==0&&t==1))return 0;

  dp[i][j][t]=0;
  if(t==0)repA(x,1,min(i,k))dp[i][j][0]+=func(i-x,j,1),dp[i][j][0]%=MOD;
  if(t==1)repA(x,1,min(j,l))dp[i][j][1]+=func(i,j-x,0),dp[i][j][1]%=MOD;
  return dp[i][j][t];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>n>>m>>k>>l;
    fill(dp);
    dp[0][0][0]=dp[0][0][1]=1;
    // cout<<(func(n,m,0)+func(n,m,1)+MOD)%MOD;

    rep(i,n+1)rep(j,m+1)
    {
      repA(x,1,min(i,k)) dp[i][j][0]=(dp[i][j][0]+dp[i-x][j][1])%MOD;
      repA(x,1,min(j,l)) dp[i][j][1]=(dp[i][j][1]+dp[i][j-x][0])%MOD;
    }
    cout<<(dp[n][m][0]+dp[n][m][1])%MOD<<end;


    return 0;
}
