#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")

using namespace std;

typedef long long int ll;
#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a,b) (make_pair((a),(b)) )
#define all(c)  (c).begin(),(c).end()
#define fill(a) (memset((a), 0, sizeof (a)))
#define fillA(a) (memset((a), -1, sizeof (a)))
#define trav(a,x) for(auto& (a):(x))
#define rep(i,n) for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=(a);i<=(n);++i)
#define repD(i,a,n) for(ll i=(a);i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second
#define endl '\n'

typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
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
const int MAX = 100009;
const int MOD = 1e9+7;
const ll inf = 1e18;

ll c[35];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    rep(i,35)c[i]=inf;

    ll n;ll l;cin>>n>>l;
    rep(i,n)cin>>c[i];

    repA(i,1,34)if(c[i]>2*c[i-1])c[i]=2*c[i-1];
    repD(i,33,0)if(c[i+1]<c[i])c[i]=c[i+1];

    ll co=0;
    rep(i,32){
      if((1<<i)&l)co+=c[i];
    }

    bitset<34> al;
    rep(i,32)if((1<<i)&l)al[i]=1;else al[i]=0;

    ll at=0,m=-1;
    while(al[31]==0){
      rep(i,32)if(al[i]==0&&i>m){
        repA(j,0,i-1)al[j]=0;
        al[i]=1,m=i;
        break;
      }

      ll t=0;
      rep(i,32)if(al[i]==1)t+=c[i];
      co=min(co,t);
      at++;
    }
    cout<<co<<endl;


    return 0;
}
