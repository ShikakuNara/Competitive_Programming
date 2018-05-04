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


#define sz(a) (ll) (( a ).size())
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
const int MAX = 400009;
const int MOD = 1e9+7;



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n;cin>>n;
    ll a[MAX]; rep(i,n)cin>>a[i];

    vll b[n];ll j=0;
    b[0].pb(a[0]);
    rep(i,n-1)
    {
      if(a[i]<a[i+1])b[j].pb(a[i+1]);
      else j++,b[j].pb(a[i+1]);
    }j++;

    ll M=b[0].size();
    rep(i,j-1)
    {
      ll aa=b[i].size(),bb=b[i+1].size();
      if(aa==1||bb==1||(b[i+1][1]-b[i][aa-1])>1||b[i+1][0]-b[i][aa-2]>1)M=max(M,aa+bb);
      else M=max(M,aa+1),M=max(M,bb+1);
    }
    cout<<M<<end;

    return 0;
}
