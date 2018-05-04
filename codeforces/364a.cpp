#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef pair<ll, pp > ppp;
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
const int MAX = 4001;
const int MOD = 1e9+7;

string s;
ll sm[MAX*MAX],n;
ll binary(ll i,ll s,ll e)
{
  ll m=(s+e)/2;
  if(s>e)return 0;
  if(s==e)
  {
    if(sm[s]==i)return 1;
    return 0;
  }
  if(sm[m]<i)return binary(i,m+1,e);
  if(sm[m]>i)return binary(i,s,m-1);
  return 1+binary(i,s,m-1)+binary(i,m+1,e);
}

ll check(ll i){return binary(i,0,n-1);}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll a;cin>>a>>s;
    ll v[MAX];v[0]=s[0]-'0';
    repA(i,1,sz(s)-1)v[i]=s[i]-'0',v[i]+=v[i-1];

    ll k=0;
    rep(i,sz(s))repA(j,i+1,sz(s)-1)sm[k]=v[j]-v[i],k++;
    rep(i,sz(s))sm[k]=v[i],k++;

    n=(sz(s)*(sz(s)+1))/2;
    sort(sm,sm+n);

    if(a==0)
    {
      cout<<2*check(0)*(n-check(0))+check(0)*check(0);return 0;
    }
    ll cnt=0;
    std::map<ll, bool> mp;
    repA(i,1,sqrt(a)+1)if(a%i==0)
    {
      if(mp[i]==true)continue;
      if(i*i!=a)cnt+=2*check(i)*check(a/i);
      else cnt+=check(i)*check(a/i);
      if(check(i)*check(a/i))mp[a/i]=true;
    }
    cout<<cnt;

    return 0;
}
