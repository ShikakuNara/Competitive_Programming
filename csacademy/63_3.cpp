#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;


typedef long long int ll;
typedef long double ld;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef vector<pp > vpp;

#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define trav(a, x) for(auto& a : x)
#define rep(i,n)     for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second
#define endl '\n'

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
const int MAX = 100009;
const int MOD = 1e9+7;
const ll inf = 1e18+10;

ll a[MAX],b[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int n;cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n)if(a[i]<b[i]){cout<<-1;return 0;}

    ll cur,j=0;
    while(j<n&&a[j]-b[j]==0)j++;
    if(j==n){
      ll m=-1;
      rep(i,n)m=max(m,b[i]);
      cout<<m+1<<endl;
      return 0;
    }
    cur=a[j]-b[j];


    repA(i,1,n-1){
      if(a[i]-b[i]==0)continue;
      cur=gcd(cur,a[i]-b[i]);
    }
    rep(i,n)if(b[i]>=cur){cout<<-1;return 0;}

    ll m=-1,ss=sqrt(cur),mi=inf;
    rep(i,n)m=max(m,b[i]);
    repA(i,1,ss){
      if(cur%i==0&&i>m)mi=min(mi,i);
      if(cur%i==0&&(cur/i)>m)mi=min(mi,cur/i);
    }
    cout<<mi<<endl;



    return 0;
}
