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
const int MAX = 200009;
const int MOD = 1e9+7;

ll tree[4*MAX] = {0};  // To store segment tree
ll lazy[4*MAX] = {0};  // To store pending updates

void updateU(ll i, ll s, ll e, ll us, ll ue, ll diff)
{
    if (lazy[i] != 0)
    {
        tree[i] += (e-s+1)*lazy[i];

        if (s != e)
        {
            lazy[i*2 + 1]   += lazy[i];
            lazy[i*2 + 2]   += lazy[i];
        }
        lazy[i] = 0;
    }

    if (s>e || s>ue || e<us)
        return ;

    if (s>=us && e<=ue)
    {
        tree[i] += (e-s+1)*diff;

        if (s != e)
        {
            lazy[i*2 + 1]   += diff;
            lazy[i*2 + 2]   += diff;
        }
        return;
    }

    ll m = (s+e)/2;
    updateU(i*2+1, s, m, us, ue, diff); updateU(i*2+2, m+1, e, us, ue, diff);

    tree[i] = tree[i*2+1] + tree[i*2+2];
}

void update(ll us, ll ue, ll diff, ll n)
{
   updateU(0, 0, n-1, us, ue, diff);
}

ll getSumU(ll s, ll e, ll qs, ll qe, ll i)
{
    if (lazy[i] != 0)
    {
        tree[i]+=(e-s+1)*lazy[i];

        if (s != e)
        {
            lazy[i*2+1]+=lazy[i];
            lazy[i*2+2]+=lazy[i];
        }
        lazy[i] = 0;
    }

    if (s>e||s>qe||e<qs) return 0;

    if (s>=qs && e<=qe)  return tree[i];

    ll m=(s+e)/2;
    return getSumU(s,m,qs,qe,2*i+1)+getSumU(m+1,e,qs,qe,2*i+2);
}

ll getSum(ll qs, ll qe, ll n)
{
    if (qs<0||qe>n-1||qs>qe) {cout<<"invalid input\n"; return -1;}
    return getSumU(0,n-1,qs,qe,0);
}

void buildtreeU(ll arr[],ll s,ll e,ll i)
{
    if (s > e) return;

    if (s == e){tree[i] = arr[s]; return;}

    ll m=(s+e)/2;
    buildtreeU(arr,s,m,i*2+1); buildtreeU(arr,m+1,e,i*2+2);

    tree[i]=tree[i*2+1]+tree[i*2+2];
}

void buildtree(ll a[], ll  n)
{
  buildtreeU(a, 0, n-1, 0);
  return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n,q;cin>>n>>q;
    ll a[MAX],cnt[MAX]={0};rep(i,n)cin>>a[i]; sort(a,a+n);
    buildtree(cnt,n);
    rep(i,q){ll a,b;cin>>a>>b;a--,b--;update(a,b,1,n);}
    ll c[MAX];rep(i,n)c[i]=getSum(i,i,n);sort(c,c+n);
    ll ans=0;rep(i,n)ans+=c[i]*a[i];
    cout<<ans<<end;


    return 0;
}
