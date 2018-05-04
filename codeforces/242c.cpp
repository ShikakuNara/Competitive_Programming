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


std::map<pp, bool> mp;
std::priority_queue<ppp > que;
std::map<pp, bool> vis;
bool check(ll h, ll k) {
  if(h<=0||h>1000000000||k>1000000000||k<=0)return 0;
  if(vis[mp(h,k)]==true)return 0;
  if(mp[mp(h,k)]==false)return 0;
  return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll a,b,x,y;cin>>a>>b>>x>>y;
    ll n;cin>>n;
    rep(i,n)
    {
      ll r,a,b;cin>>r>>a>>b;
      repA(j,a,b)mp[mp(r,j)]=1;
    }

    que.push(mp(0,mp(a,b)));ll cnt=1;
    while(!que.empty())
    {
      ppp u=que.top();que.pop();
      ll h=u.Y.X,k=u.Y.Y,d=-u.X;
      if(d>100000)break;

      if(h==x&&k==y){cout<<d<<end;return 0;}

      if(check(h-1,k))que.push(mp(-d-1,mp(h-1,k))),cnt++,vis[mp(h-1,k)]=1;
      if(check(h+1,k))que.push(mp(-d-1,mp(h+1,k))),cnt++,vis[mp(h+1,k)]=1;
      if(check(h,k-1))que.push(mp(-d-1,mp(h,k-1))),cnt++,vis[mp(h,k-1)]=1;
      if(check(h,k+1))que.push(mp(-d-1,mp(h,k+1))),cnt++,vis[mp(h,k+1)]=1;
      if(check(h-1,k-1))que.push(mp(-d-1,mp(h-1,k-1))),cnt++,vis[mp(h-1,k-1)]=1;
      if(check(h+1,k+1))que.push(mp(-d-1,mp(h+1,k+1))),cnt++,vis[mp(h+1,k+1)]=1;
      if(check(h-1,k+1))que.push(mp(-d-1,mp(h-1,k+1))),cnt++,vis[mp(h-1,k+1)]=1;
      if(check(h+1,k-1))que.push(mp(-d-1,mp(h+1,k-1))),cnt++,vis[mp(h+1,k-1)]=1;
    }
    cout<<-1<<end;


    return 0;
}
