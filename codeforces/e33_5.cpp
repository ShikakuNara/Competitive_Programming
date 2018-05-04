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

const int MAX = 400009;
const int MOD = 1e9+7;

#define MAXN   1000001
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)  spf[i] = i;
    for (ll i=4; i<MAXN; i+=2) spf[i] = 2;
    for (ll i=3; i*i<MAXN; i++)if (spf[i] == i) for (ll j=i*i; j<MAXN; j+=i) if (spf[j]==j) spf[j] = i;
}

vector<ll> getFactorization(ll x)
{
    vector<ll> ret;
    while (x!=1)
    {
        ret.push_back(spf[x]);
        x=x/spf[x];
    }
    return ret;
}

ll gcdExtended(ll a, ll b, ll *x,ll *y);

ll modI(ll a, ll m=MOD)
{
    ll x,y;
    ll g=gcdExtended(a,m,&x,&y);
    if (g != 1)
        cout<<"Inverse doesn't exist";
    else
    {
        ll res=(x%m+m)%m;
        return res;
    }
    return -1;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if(a == 0)
    {
        *x=0,*y=1;
        return b;
    }
    ll x1,y1;
    ll gcd=gcdExtended(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;

    return gcd;
}
ll power(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=power(x,y/2);
  if(y%2==1)return (((tmp*tmp)%MOD)*x)%MOD;
  return ((tmp*tmp)%MOD);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    sieve();
    ll q;cin>>q;
    rep(aja,q)
    {
      ll x,y;cin>>x>>y;
      ll c[21]={0}; c[0]=1;
      repA(i,1,20)c[i]=((((i+y-1)*c[i-1])%MOD)*modI(i))%MOD;
      vll p=getFactorization(x); std::map<ll, ll> mp;
      rep(i,sz(p))mp[p[i]]=0;
      rep(i,sz(p)){mp[p[i]]+=1;}

      ll ans=power(2,y-1);
      rep(i,sz(p))
      {
        if(mp[p[i]]!=0) ans*=c[mp[p[i]]],ans%=MOD,mp[p[i]]=0;
      }
      cout<<ans<<end;
    }

    return 0;
}