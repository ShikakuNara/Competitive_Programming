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
const int MAX = 400009;
const int MOD = 1e9+7;

ll m,n,ans;
ll solve(ll x[],ll a,ll b,ll c)
{
  m=x[1]-x[0],n=x[2]-x[1],ans=1e18;

  ans=min(ans,a*(x[0]+x[1]+x[2]));//use a
  ans=min(ans,c*x[0]+min(b,2*a)*m+a*n);//use c then a/b

  if(x[0]>=n)ans=min(ans,b*(m+2*n)+c*(x[0]-n));

  if(x[0]<n&&n>=1)ans=min(ans,b*3*(x[0]/2)+b*m+b*2+a*(n-1));
  if(x[0]<n&&n==0)ans=min(ans,b*3*(x[0]/2)+b*m+a*(n+1));

  if(x[0]%2==0)ans=min(ans,b*3*(x[0]/2)+b*m+a*n);
  if(x[0]%2==1)ans=min(ans,b*3*(x[0]/2)+b*m+a*n+min(b+a,c));

  if((x[0]+n)%2==0&&x[0]>=n)ans=min(ans,((3*x[0]+n)/2+m)*b);
  if((x[0]+n)%2==1&&x[0]>=n)ans=min(ans,((3*x[0]+n-3)/2+m)*b+min(b+a,c));
  if(x[0]<n) ans=min(ans,(2*x[0]+m)*b+(n-x[0])*a);

  return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //#ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    //#endif

    cout<<"lol\n";
    ll t,x[3],a,b,c;cin>>t;
    rep(aa,t)
    {
        //ll a;cin>>a;
	//cout<<a<<'k';continue;      	
	cin>>x[0]>>x[1]>>x[2]>>a>>b>>c;sort(x,x+3);//writing this on vim
        cout<<solve(x,a,b,c)<<end;
    }

    return 0;
}
