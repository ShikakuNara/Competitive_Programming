#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <int> vii;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
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
  if(y%2==1)return power(x*x,y/2)*x;
  return power(x*x,y/2);
}

ll Min(ll a,ll b){if(a<b)return a;return b;}

const int MAX = 400009;
const int MOD = 1e9+7;

ll count(ll n)
{
  ll count = 0;
  while (n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

void bin(ll n,ll nn)
{
    ll b[40];
    ll i,j;
    for (j=0;j<nn;j++) {
      if(n&(1<<j))b[j]=1;
      else b[j]=0;
    }
    rep(i,j)cout<<b[i];

}

vii s[(1<<20)+5];
std::map<ll, ll> mp;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll n;cin>>n;
    // bin(3,5);
    // printf("\n");
    pp a[42];
    repA(i,0,n-1)cin>>a[i].X>>a[i].Y;

    ll ind=0,ind1=0,ind2=0;
    if(n<=20)
    {
      ll m=1e17;
      rep(i,1<<(n))
      {
        ll sum=0;
        rep(j,n)if(i&(1<<j))sum+=a[j].Y;else sum-=a[j].X;

        if(sum==0)ind=i,m=Abs(n-2*count(i));
      }
      if(m<1e16) {
        repA(j,0,n-1) cout<<(ll)((ind>>j)&1);
      }
      else cout<<-1<<'\n';
      // cout<<ind<<'\n';
      // printf("\n");
    }
    else
    {
      ll k=0;
      rep(i,1<<20)
      {
        ll sum=0;
        rep(j,20)if(i&(1<<j))sum+=a[j].Y;else sum-=a[j].X;
        mp[sum]=k,s[k].pb(i),k++;
      }

      ll m=1e17;
      rep(i,1<<(n-20))
      {
        ll sum=0;
        rep(j,n-20)if(i&(1<<j))sum-=a[j+20].Y;else sum+=a[j+20].X;

        if(mp.find(sum)==mp.end())continue;
        ll u=mp[sum];
        rep(j,sz(s[u]))
        {
          ll v=Abs(n-2*count(s[u][j])-2*count(i));
          if(v<m)m=v,ind1=i,ind2=s[u][j];
        }
      }

      if(m<1e16) {
        repA(j,0,19)cout<<(ll)((ind2>>j)&1);
		    repA(j,0,n-21)cout<<(ll)((ind1>>j)&1);
      }
      else cout<<-1<<'\n';
    }

    return 0;
}
