#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <ll> vi;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;

#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define rep(i,n)     for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
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
const int MAX = 400009;
const int MOD = 1e9+7;

ll add(ll k, ll n)
{
  if(k>n)return n-k/2;
  return k-k/2-1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll n;cin>>n;
    ll m=n+n-1;
    // cout<<m<<endl;
    if(n==0){cout<<0;return 0;}
    if(n==1){cout<<0;return 0;}
    if(n==2){cout<<1;return 0;}
    if(n==3){cout<<3;return 0;}
    if(n==4){cout<<6;return 0;}

    ll t=0,k=0;
    while(t<=m)
    {
      t*=10,t+=9;
      k++;
    }
    k--;

    vll num;
    rep(i,k)num.pb(9);
    ll ans=0;

    repA(i,0,8)
    {
      num.pb(i);
      ll v=0,tt=1;
      // rep(tmp,k+1)
      // {
        rep(j,sz(num))v+=num[j]*tt,tt*=10;
        // cout<<"Num: ";rep(j,sz(num))cout<<num[j];cout<<" ";
        // cout<<v;
        if(v<=m)ans+=add(v,n);//cout<<", add: "<<add(v,n);cout<<endl;
        rep(j,sz(num))if(num[j]==i&&j>0)num[j]=9,num[j-1]=i;
        // v=0,tt=1;
      // }s
      rep(j,sz(num))if(num[j]==i)num.erase(num.begin()+j);
    }
    cout<<ans<<endl;



    return 0;
}
