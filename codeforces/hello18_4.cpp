#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")

using namespace std;
#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a,b) (make_pair((a),(b)) )
#define all(c)  (c).begin(),(c).end()
#define fill(a) (memset((a), 0, sizeof (a)))
#define fillA(a) (memset((a), -1, sizeof (a)))
#define trav(a,x) for(auto& (a):(x))
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=(a);i<=(n);++i)
#define repD(i,a,n) for(int i=(a);i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<ll, ll> pp;
typedef pair<ll, pp> ppp;
typedef vector<pp > vpp;

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

ll pow(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=pow(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ppp p[MAX];ll M=0;
int n;ll t;

ll solve(ll m){
  ll s=0,a=0;

  rep(i,n){
    if(s>t||a==m)break; 
    if(p[i].Y.X>=m)s+=p[i].X,a++;
    if(s>t||a==m)break;
  }
  if(a!=m||s>t)return -1;
  return a;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    cin>>n>>t;
    rep(i,n)cin>>p[i].Y.X>>p[i].X,p[i].Y.Y=i;
    sort(p,p+n);


    ll s=0,e=n;
    while(s<e){
      ll m=(s+e+1)/2;
      ll tmp=solve(m);

      if(tmp>M)s=m,M=tmp;
      else e=m-1;
    }

    vll ans;
    s=0;ll a=0;
    rep(i,n){
      if(s>t||a>=M)break;
      if(p[i].Y.X>=M)ans.pb(p[i].Y.Y),a++;
      if(s>t||a>=M)break;
    }
    cout<<M<<endl;
    cout<<sz(ans)<<endl;
    trav(i,ans)cout<<i+1<<' ';cout<<endl;


    return 0;
}
