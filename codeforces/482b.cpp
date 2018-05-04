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
const int MAX = 400009;
const int MOD = 1e9+7;

ll n,m,l[MAX],r[MAX],q[MAX],sum[30][MAX],a[MAX];
ll tree[4*MAX]={0};
ll getSumU(ll s,ll e,ll qs,ll qe,ll i)
{
    if (s>e||s>qe||e<qs)return (1<<30)-1;
    if (s>=qs&&e<=qe)return tree[i];
    ll m=(s+e)/2;
    return getSumU(s,m,qs,qe,2*i+1)&getSumU(m+1,e,qs,qe,2*i+2);
}

ll getSum(ll qs,ll qe,ll n)
{
    if (qs<0||qe>n-1||qs>qe) {cout<<"invalid input\n"; return -1;}
    return getSumU(0,n-1,qs,qe,0);
}

void buildtreeU(ll arr[],ll s,ll e,ll i)
{
    if (s>e)return;
    if (s==e){tree[i]=arr[s];return;}
    ll m=(s+e)/2;
    buildtreeU(arr,s,m,i*2+1);buildtreeU(arr,m+1,e,i*2+2);
    tree[i]=tree[i*2+1]&tree[i*2+2];
}

void build(ll a[],ll  n){buildtreeU(a,0,n-1,0); return;}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>n>>m;
    rep(i,m)
    {
      cin>>l[i]>>r[i]>>q[i],l[i]--;
      rep(j,30)if(q[i]>>j&1)sum[j][l[i]]++,sum[j][r[i]]--;
    }
    rep(j,30)rep(i,n)
    {
      if(i)sum[j][i]+=sum[j][i-1];
      if(sum[j][i]>0)a[i]|=(1<<j);
    }

    build(a,n);
    rep(i,m) if(getSum(l[i],r[i]-1,n)!=q[i]){cout<<"NO\n";return 0;}

    cout<<"YES\n";
    rep(i,n)cout<<a[i]<<" ";

    return 0;
}
