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
ll power(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=power(x,y/2);
  if(y%2==1)return tmp*tmp*x;
  return tmp*tmp;
}
const int MAX = 400009;
const int MOD = 1e9+7;

ll a[MAX];
ll binary(ll i,ll s,ll e)
{
  ll m=(s+e)/2;
  if(s==e&&a[s]>=i)return s;
  if(s==e&&a[s]<i)return -1;
  if(a[m]>=i)return binary(i,s,m);
  return binary(i,m+1,e);
}
ll binary2(ll i,ll s,ll e)
{
  ll m=(s+e+1)/2;
  if(s==e&&a[s]<=i)return s;
  if(s==e&&a[s]>i)return -1;
  if(a[m]>i)return binary2(i,s,m-1);
  return binary2(i,m,e);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n,x,k;cin>>n>>x>>k;
    rep(i,n)cin>>a[i];sort(a,a+n);

    ll ans=0;
    repA(j,0,n-1)
    {
      ll s=x*(a[j]/x-k)+1,l=x*(a[j]/x-k+1);
      if(k==0)s=x*(a[j]/x)+1,l=a[j];
      ll a=binary(s,0,n-1),b=binary2(l,0,n-1);
      if(a==-1||b==-1)continue;
      ans+=b-a+1;
    }
    cout<<ans<<end;


    return 0;
}
