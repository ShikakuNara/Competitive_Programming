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
const int MAX = 100009;
const int MOD = 1e9+7;

ll p[MAX],c[MAX],a,n,m;
bool okay(ll m)
{
  ll mon=a;
  rep(i,m)
  {
    if(c[i]>p[n-m+i])mon-=c[i]-p[n-m+i];
    // cout<<mon<<","<<c[i]<<","<<p[n-m+i]<<"    ";
    if(mon<0)return false;
  }
  return true;
}
void print(ll m)
{
  ll mon=0;
  rep(i,m)mon+=c[i];
  if(mon-a<0)mon=0;
  else mon-=a;
  cout<<m<<" "<<mon<<end;
}
void binary(ll s,ll e)
{
  ll m=(s+e+1)/2;
  if(s==e)
  {
    if(okay(s))print(s);
    else cout<<"0 0";
    return;
  }
  if(okay(m))return binary(m,e);
  return binary(s,m-1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>n>>m>>a;
    rep(i,n)cin>>p[i];sort(p,p+n);
    rep(i,m)cin>>c[i];sort(c,c+m);

    binary(0,min(n,m));

    return 0;
}
