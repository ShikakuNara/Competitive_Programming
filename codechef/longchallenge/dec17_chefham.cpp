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

ll power(ll x,ll y)
{
  if(y==0)return 1;
  if(y%2==1)return power(x*x,y/2)*x;
  return power(x*x,y/2);
}
const int MAX = 100009;
const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll t;cin>>t;
    rep(aaja,t)
    {
      ll n;pp a[MAX],b[MAX];cin>>n;
      rep(i,n)cin>>a[i].X,a[i].Y=i;

      ll vis[MAX]={0},d=0,j=1;
      rep(i,n)b[i].X=a[i].X,b[i].Y=a[i].Y;sort(a,a+n);

      std::map<pp,ll> mp;
      if(n==1){cout<<0<<end<<b[0].X<<end;continue;}

      rep(i,n)
      {
        ll cur=0;
        while(true)
        {
          if(vis[j]==1);
          else if(a[j].X!=a[i].X){mp[a[j]]=a[i].X,vis[j]=1,j=(j+1)%n;break;}
          else if(cur>=n)    {mp[a[j]]=a[i].X,vis[j]=1,d++,j=(j+1)%n;break;}

          j=(j+1)%n,cur++;
        }
      }

      sort(a,a+n,Rcompare());
      ll d2=0;j=1;fill(vis);
      std::map<pp, ll> mp2;
      rep(i,n)
      {
        ll cur=0;
        while(true)
        {
          if(vis[j]==1);
          else if(a[j].X!=a[i].X){mp2[a[j]]=a[i].X,vis[j]=1,j=(j+1)%n;break;}
          else if(cur>=n)    {mp2[a[j]]=a[i].X,vis[j]=1,d2++,j=(j+1)%n;break;}

          j=(j+1)%n,cur++;
        }
      }

      if(d<=d2)
      {
        cout<<n-d<<end;
        rep(i,n)cout<<mp[b[i]]<<' ';cout<<end;
      }
      else
      {
        cout<<n-d2<<end;
        rep(i,n)cout<<mp2[b[i]]<<' ';cout<<end;
      }

    }

    return 0;
}
