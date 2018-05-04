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
const int MAX = 200009;
const int MOD = 1e9+7;
pp a[MAX];
map<ll,ll>mp;
ll cnt[MAX]={0},up[MAX]={0};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

	ll n;cin>>n;
	ll m=Ceil(n,2);
	
	//cout<<m<<'\n';
	ll k=0;
	rep(i,n)
	{
		cin>>a[i].X>>a[i].Y;
		if(mp.find(a[i].X)==mp.end())mp[a[i].X]=k,k++;
		if(mp.find(a[i].Y)==mp.end())mp[a[i].Y]=k,k++;
		up[mp[a[i].X]]++;
		if(a[i].X==a[i].Y)cnt[mp[a[i].X]]++;
		else cnt[mp[a[i].X]]++,cnt[mp[a[i].Y]]++;
	}
	ll d[4],ii=0;
	rep(i,k)if(cnt[i]>=m)d[ii]=i,ii++;
	if(ii==0){cout<<-1;return 0;}
	ll mm=1e17;
	rep(i,ii)mm=min(mm,m-up[d[i]]);//cout<<d[i]<<' '<<up[d[i]]<<'\n';
	cout<<max((ll)0,mm);


    return 0;
}

