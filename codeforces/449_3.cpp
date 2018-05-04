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

ll m,k,len[MAX];
string a="What are you doing while sending \"",
       b="\"? Are you busy? Will you send \"",
       c="\"?",
       s0="What are you doing at the end of the world? Are you busy? Will you save us?";
char geta(ll n,ll k);
char getb(ll n,ll k);

char geta(ll n,ll k)
{
  if(n<54&&k>=len[n])return '.';
  if(n==0)return s0[k];
  if(k<34)return a[k];k-=34;
  char t=geta(n-1,k);
  if(t!='.')return t;
  return getb(n,k-len[n-1]);
}
char getb(ll n,ll k)
{
  if(k<32)return b[k];k-=32;
  char t=geta(n-1,k);
  if(t!='.')return t;
  k-=len[n-1];
  if(k>2)return '.';
  return c[k];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    len[0]=75;
    repA(i,1,MAX-1)len[i]=68+2*len[i-1];

    // rep(i,100)cout<<i<<' '<<len[i]<<end;
    ll q;cin>>q;
    rep(aaja,q)
    {
      cin>>m>>k;
      cout<<geta(m,k-1);
    }


    return 0;
}