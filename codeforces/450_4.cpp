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
const long double PI = 3.141592653589793238462643383;
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


const int MAX = 400009;
const int MOD = 1e9+7;

ll powe(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=powe(x,y/2);
  if(y%2==1)return ((tmp*tmp+MOD)%MOD*x+MOD)%MOD;
  return (tmp*tmp+MOD)%MOD;
}

ll get(vll pr, vll pw)
{
    ll x=1;
    rep(i,sz(pr))rep(j,pw[i])x*=pr[i];
    x--;
    return powe(2,x);
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll x,y;cin>>x>>y;
    if(y%x!=0){cout<<0<<endl;return 0;}
    y=y/x;
    vll pr,pw;
    repA(i,2,y)if(y%i==0)
    {
      bool ff=true;
      repA(j,2,sqrt(i))if(i%j==0)ff=false;

      if(ff)
      {
        pr.pb(i),y/=i,pw.pb(1);
        while(y%i==0&&y>0)pw[sz(pw)-1]++,y/=i;
      }
    }

    ll k=1<<(sz(pr));
    ll ans=0;
    while(k)
    {
      k--;
      ll cnt=0;
      rep(i,sz(pr))if(k&(1<<i))cnt++,pw[i]--;
      ll tmp=get(pr,pw);
      rep(i,sz(pr))if(k&(1<<i))pw[i]++;
      if(cnt%2==1)ans=(ans-tmp+MOD)%MOD;
      else ans=(ans+tmp+MOD)%MOD;
    }

    cout<<ans<<endl;

    return 0;
}
