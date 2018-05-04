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
ll gcd(ll a, ll b){if (a == 0) return b;return gcd(b%a, a);}
ll lcm(ll a, ll b){return a * (b / gcd(a, b));}
ll Abs(ll a){if( a > 0)return a;return -a;}
double Abs(double a){if( a > 0)return a;return -a;}

ll power(ll x,ll y)
{
  if(y==0)return 1;
  if(y%2==1)return power(x*x,y/2)*x;
  return power(x*x,y/2);
}
const int MOD = 1e9+7;
ll powe(ll x,ll y)
{
  if(y<=0)return 1;
  ll tmp=powe(x,y/2);
  if(y%2==1)return (((tmp*tmp)%MOD)*x)%MOD;
  return (tmp*tmp)%MOD;
}
const int MAX = 400009;

ll prime[19]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 , 53, 59, 61, 67};
ll a[MAX],cnt[72]={0},po[71]={0};long dp[71][530000];bitset<19> bit[71];

ll func(ll i,ll p)
{
  if(dp[i][p]!=-1)return dp[i][p];
  if(i==0)
  {
    if(p==0)return 1;
    else  return 0;
  }
  if(cnt[i]==0)return dp[i][p]=func(i-1,p);
  return dp[i][p]=((func(i-1,p)+func(i-1,p^bit[i].to_ulong()))%MOD*po[i])%MOD;;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    fillA(dp);
    ll n;cin>>n;
    rep(i,n)cin>>a[i],cnt[a[i]]++;
    repA(i,1,71)rep(j,19)if(i%prime[j]==0)
    {
      ll tmp=i,ct=0;
      while(tmp>0&&tmp%prime[j]==0)tmp/=prime[j],ct++;
      bit[i][j]=(ct%2);
    }
    repA(i,0,70)po[i]=powe(2,cnt[i]-1);
    cout<<func(70,0)-1<<end;

    return 0;
}
