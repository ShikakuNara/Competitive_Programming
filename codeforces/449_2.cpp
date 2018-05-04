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
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}


ll n,p;
ll power(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=power(x,y/2);
  if(y%2==1)return (((tmp*tmp))*x);
  return (tmp*tmp);
}
const int MAX = 400009;
const int MOD = 1e9+7;

ll calc(ll i)
{
  ll d=0,tmp=i;
  while(tmp>0)tmp/=10,d++;
  ll ans=0;
  rep(j,d)
  {
    ll t=i%power(10,d-j);t=(t/power(10,d-j-1));
    ans=(ans+power(10,j)*t)%p;
  }
  rep(j,d)
  {
    ll t=i%power(10,j+1)-i%power(10,j);t=t/power(10,j);
    ans=(ans+power(10,j+d)*t)%p;
  }
  return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll sum=0;cin>>n>>p;
    // cout<<calc(1000)<<end;
    repA(i,1,n)sum=(sum+calc(i))%p;
    cout<<sum<<end;

    return 0;
}
