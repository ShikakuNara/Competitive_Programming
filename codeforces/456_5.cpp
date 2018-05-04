#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif
#pragma GCC target ("avx,avx2")
#pragma GCC optimize ("Ofast")

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
const int inf = 1e9+10;


ll superUgly(ll n, ll pr[], ll k)
{
    vll nxt(pr, pr+k);
    ll mul[k];fill(mul);


    set<ll> ugly;
    ugly.insert(1);

    while (ugly.size()!=n)
    {
        ll next = *min_element(nxt.begin(),nxt.end());

        ugly.insert(next);
        rep(j,k)if (next == nxt[j])
          {
              mul[j]++;
              auto it = ugly.begin();
              for (ll i=1; i<=mul[j]; i++)it++;
              nxt[j]=pr[j]*(*it);
              break;
          }
    }

    auto it = ugly.end();
    it--;
    return *it;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll n;cin>>n;
    ll primes[20];
    rep(i,n)cin>>primes[i];

    ll k;cin>>k;
    cout << superUgly(k, primes, n);

    return 0;
}
