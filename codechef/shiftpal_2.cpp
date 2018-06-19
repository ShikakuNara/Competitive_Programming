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
#define fst first
#define snd second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<ll, ll> pp;
typedef pair<ll, pp> ppp;
typedef vector<pp > vpp;

#ifdef LOCAL_TEST
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 400009;
const int MOD = 1e9+7;
const int MOD2 = 1e9+9;
const int inf = 1e9+10;

int p[]={1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459};
ll h[MAX],rh[MAX];string s;ll n;
ll h2[MAX],rh2[MAX];

ll gcdExtended(ll a,ll b,ll *x,ll *y){
    if(a==0){*x=0,*y=1;return b;}

    ll x1,y1;
    ll gcd=gcdExtended(b%a,a,&x1,&y1);

    *x=y1-(b/a)*x1;
    *y=x1;

    return gcd;
}

ll modI(ll a,ll m=MOD){
    ll x,y;
    ll g=gcdExtended(a,m,&x,&y);
    if(g != 1)cout<<"Inverse doesn't exist";
    else return (x%m+m)%m;;
    return -1;
}

ll f(int i){
  return p[s[(i+n)%n]-'a'];
}

ll powe(int x,int y){
  if(y==0)return 1;
  ll tmp=powe(x,y/2);
  if(y%2)return tmp*tmp%MOD*x%MOD;
  else return tmp*tmp%MOD;
}

ll Hash(int i){
  return powe(f(i),f(i-1));
}
ll Hashr(int i){
  return powe(f(i),f(i+1));
}

ll ghash(int i){
  return h[i+n/2]*modI(h[i])%MOD;
}
ll ghashr(int i){
  i+=n;
  return h[i-1]*modI(h[i-n/2-1])%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t){
      cin>>s; n=sz(s);s+=s;

      rep(i,2*n)h[i]=1;

      h[0]=Hash(0);
      repA(i,1,2*n-1)h[i]=h[i-1]*Hash(i)%MOD;
      rh[0]=Hash(0);
      repA(i,0,2*n-2)rh[i]=rh[i+1]*Hashr(i)%MOD;

      ll ans=0;
      rep(i,n)if(f(i)==f(i+1))
        if(ghash(i+1)==ghashr(i))ans++;
      cout<<ans<<endl;
    }

    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
