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
typedef pair<int, int> pp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const ll MAX = 1000009;
const ll MOD = 1e9+7;
const int inf = 1e9+10;

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

ll modI(ll a, ll m=MOD)
{
    ll x,y;
    ll g=gcdExtended(a,m,&x,&y);
    if (g != 1)cout<<"Inverse doesn't exist";
    else{
        ll res=(x%m+m)%m;
        return res;
    }
    return -1;
}

ll catalan[8000]={0};

ll catalanDP(ll n,ll k,ll a,ll b)
{
    fill(catalan);
    catalan[1]=k%MOD;

    repA(i,2,n)
    {
        catalan[i] = a*catalan[i-1]%MOD;
        repA(j,1,i-1){
          ll tmp=catalan[j] * catalan[i-j]%MOD;
          tmp=(tmp*b)%MOD;
          catalan[i]=(catalan[i]+tmp)%MOD;
        }
    }

    return catalan[n];
}

vi fact,invfact;

void pre(){
  ll tmp=1;
  fact.pb(1),invfact.pb(1);//0!
  repA(i,1,MAX)tmp=(tmp*i)%MOD,fact.pb(tmp),invfact.pb(modI(tmp));
}

ll p=MOD;
ll C(ll n, ll m) {
	ll c = 1;
	while (n || m) {
		ll a = n % p, b = m % p;
		if (a < b) return 0;
		c = c * fact[a] % p * invfact[b] % p * invfact[a - b] % p;
		n /= p; m /= p;
	}
	return c;
}

ll pw(ll x,ll y){
  if(y==0)return 1;
  if(y==1)return x;

  ll tmp=pw(x,y/2);
  if(y%2)return (((tmp*tmp)%MOD)*x)%MOD;

  return (tmp*tmp)%MOD;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    pre();

    // rep(i,100){
      ll n,k,a,b;cin>>n>>k>>a>>b;
      // n=rand()%5000+1;
      // k=rand()%MOD+1;
      // b=rand()%MOD+1;
      // a=0;

      if(n<7000){
        cout<<catalanDP(n,k,a,b)<<endl;
        return 0;
      }

      ll tmp=pw(k,n)*pw(b,n-1)%MOD;
      ll ans=C(2*n-2,n-1)*modI(n)%MOD;
      ans=(ans*tmp)%MOD;

      cout<<ans<<endl;
    // }


    return 0;
}
