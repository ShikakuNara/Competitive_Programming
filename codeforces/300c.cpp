#ifdef LOCAL_TEST
  #include "/usr/local/include/bits/stdc++.h"
  #pragma comment(linker, "/stack:16777216")
#endif
#ifndef LOCAL_TEST
  #include <bits/stdc++.h>
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef pair<ll , pp> ppp;
typedef vector<pp > vpp;
typedef vector<ppp > vppp;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;

#define sz(a) ll((a).size())
#define pb push_back
#define all(c)        (c).begin(),(c).end()
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mp(a, b)       (make_pair(a, b) )
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'
#define PI 3.14159265

// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
ll abs(ll a, ll b){
  if( a > b)
    return a-b;

  return b-a;
}
double abs(double a, double b){
  if( a > b)
    return a-b;

  return b-a;
}


const ll factRange = 1000006;
const ll MOD = 1e9 + 7;
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

ll a, b, n;
ll good(ll x)
{
  while(x > 0)
  {
    if(x % 10 != a && x % 10 != b)
    {
      return 0;
    }
    x /= 10;
  }


  return 1;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt");
      ofstream cout("out.txt");
    #endif

    precalcFactorials();

    cin >> a >> b >> n;

    ll ans = 0;
    for (size_t i = n*a; i <= n*b; i += b-a) {
      if(good(i))
      {
        ll y = ( i - n*a) / (b - a);
        cout << n << ", " << y << end;
        ans += C(n, y);
        ans __;
      }
    }

    cout << ans << end;

    return 0;
}
