#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef stack < ll > sii;
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
ll power(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=power(x,y/2);
  if(y%2==1)return tmp*tmp*x;
  return tmp*tmp;
}
const int MAX = 100009;
const int MOD = 1e9+7;


ll dp[40][40][40][40]={0};
ll make(ll a,ll b,ll c,ll d)
{
  if(dp[a][b][c][d]!=-1) return dp[a][b][c][d];
  ll ans=0;
  repA(i,a+1,b-1) ans+=make(a,i,c,d)+make(i+1,b,c,d);
  repA(i,c+1,d-1) ans+=make(a,b,c,i)+make(a,b,i+1,d);
  return dp[a][b][c][d]=ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n,m,q;cin>>n>>m>>q;
    rep(i,40)rep(j,40)rep(k,40)rep(l,40)dp[i][j][k][l]=-1;
    rep(j,m)
    {
      string s;cin>>s;
      rep(i,n)dp[i][i][j][j]=1-s[i]+'0';
    }
    ll a,b,c,d;
    rep(i,q){cin>>a>>b>>c>>d;a--,b--,c--,d--;cout<<make(a,b,c,d)<<end;}
    return 0;
}
