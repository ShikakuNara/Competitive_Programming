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
#define trav(a, x) for(auto& a : x)
#define rep(i,n)     for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

ll power(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=power(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 400009;
const int MOD = 1e9+7;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    ll n;cin>>n;
    ll a[MAX];
    rep(i,n)cin>>a[i];

    std::priority_queue<pp> pq;

    ll cnt=0;
    if(n==1){cout<<0<<endl;return 0;}
    if(n==2)
    {
       cout<<1<<endl;
      return 0;
    }

    map<pp,ll> c;

    pp m,sm;
    int a0=a[0],a1=a[1];
    pq.push(mp(a0,0LL)),pq.push(mp(a1,1LL));

    m=pq.top(),pq.pop();
    sm=pq.top(),pq.pop();
    pq.push(m),pq.push(sm);

    if(c.find(mp(a[0],0))==c.end())c[mp(a[0],0)]=-1;
    else c[mp(a[0],-0)]--;

    if(a[1]>=m.X)
    {
      if(c.find(m)==c.end())c[m]=-1;
      else c[m]--;
    }
    if(a[1]>=sm.X&&a[1]<m.X)
    {
      if(c.find(m)==c.end())c[m]=1;
      else c[m]++;
    }
    int ff=1;
    rep(i,n-1)if(a[i]>a[i+1])ff=0;

    if(ff==1)
    {
      ff=1;
      rep(i,n-1)if(a[i]==a[i+1])ff=0;

      ll mm=-1,cc=0;
      rep(i,n)
      {
        if(a[i]>mm)cc++,mm=a[i];
      }
      if(ff==0)cout<<cc;
      else cout<<cc-1<<endl;
      return 0;
    }


    repA(i,2,n-1)
    {
      pq.push(mp(a[i],i));
      m=pq.top(),pq.pop();
      sm=pq.top(),pq.pop();

      pq.push(m),pq.push(sm);

      if(a[i]>=m.X)
      {
        if(c.find(m)==c.end())c[m]=-1;
        else c[m]--;
      }
      if(a[i]>=sm.X&&a[i]<m.X)
      {
        if(c.find(m)==c.end())c[m]=1;
        else c[m]++;
      }
    }

    ll min=-1e18;pp ind=mp(-1,-1);
    trav(it, c)
    {
      if(min<=it.Y)min=it.Y,ind=it.X;
      // cout<<it.X.X<<','<<it.X.Y<<' '<<it.Y<<endl;
    }
    // cout<<"ind: "<<ind.X<<','<<ind.Y<<' '<<min<<endl;

    ll mm=-1,cc=0;
    rep(i,n)
    {
      if(a[i]==ind.X&&i==ind.Y)continue;
      if(a[i]>mm)cc++,mm=a[i];
    }
    ll mm2=-1,cc2=0;
    rep(i,n-1)
    {
      if(a[i]>mm2)cc2++,mm2=a[i];
    }


    cout<<max(cc,cc2)<<endl;


    return 0;
}
