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
typedef long long int ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=(a);i<=(n);++i)
#define repD(i,a,n) for(int i=(a);i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define fst first
#define snd second
#define endl '\n'


typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;


ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 1000009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

const ll factRange = MAX;
#define _  %  MOD
#define __ %= MOD
ll fact[factRange];
ll extGcd(ll a, ll b, ll& x, ll& y) {
	if (!a) {
		x = 0;
		y = 1;
		return b;
	}
	ll x1, y1;
	ll d = extGcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
inline ll addMod(ll a, ll b, ll m = MOD) {
	return ((ll)a + b) % m;
}
inline ll mulMod(ll a, ll b, ll m = MOD) {
	return ((ll)a * b) % m;
}
inline ll divMod(ll a, ll b, ll m = MOD) {
	ll x, y;
	ll g = extGcd(b, m, x, y);
	if (g != 1) {
		cerr << "Bad gcd!" << endl;
		for (;;);
	}
	x = (x % m + m) % m;
	return mulMod(a, x, m);
}
inline void precalcFactorials() {
	fact[0] = 1;
	for (ll i = 1; i < factRange; i++) {
		fact[i] = mulMod(fact[i-1], i);
	}
}
inline ll F(ll n) {
	return (n < 0) ? 0 : fact[n];
}
inline ll C(ll n, ll k) {
	return divMod(F(n), mulMod(F(n-k), F(k)));
}

ll f[MAX],a[MAX],finv[MAX];

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
    else
    {
        ll res=(x%m+m)%m;
        return res;
    }
    return -1;
}

void pre(){
  f[0]=1,f[1]=1;finv[0]=1;
  repA(i,2,MAX-1)f[i]=(i*f[i-1])%MOD;
  repA(i,1,MAX-1)finv[i]=modI(f[i]);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    clock_t tm=clock();
    ifstream cin("in.txt");ofstream cout("out.txt");
    tm=clock();
    #endif

    pre();
    precalcFactorials();

    int n;cin>>n;
    rep(i,n)cin>>a[i];
    sort(a,a+n);

    ll ans=0;
    rep(i,n-1)if(a[i]<a[n-1]){
      int j=lower_bound(a,a+n,a[i])-a;
      j++;

      ll inc=(f[n]*a[i])%MOD;
      inc=(inc*modI(n-j+1))%MOD;
      ans=(ans+inc)%MOD;
    }
    cout<<ans<<endl;

    // vpp v;
    // rep(i,n)v.pb(mp(a[i],i));
    //
    // ll ans2=0;
    // do{
    //   int i=0;
    //   repA(j,1,sz(v)-1){
    //     if(v[j].fst>v[i].fst){
    //       ans2+=v[i].fst;
    //       i=j;
    //     }
    //   }
    // }while(next_permutation(all(v)));
    // cout<<ans2;

    #ifdef LOCAL_TEST
    tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";
    #endif

    return 0;
}
