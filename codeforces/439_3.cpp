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
typedef vector<pp > vpp;
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
#define sortD(v)      (sort(v.rbegin(), v.rend())
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


//***********************************************
const ll factRange = 5010;
const ll MOD = 998244353;
#define _  %  MOD
#define __ %= MOD
ll fact[factRange];
ll extGcd(ll a, ll b, ll& x, ll& y) {
  // cout <<" gcd " <<  a << ", " << b << end;
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

    // cout << a << ", " << b << end;
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
  // cout << "C: " << n << ", " << k << end;
	return divMod(F(n), mulMod(F(n-k), F(k)));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    precalcFactorials();

    ll a, b, c; cin >> a >> b >> c;

    ll ta = a, tb = b, tc = c;

    a = min(min(a, b), c);
    c = max(max(ta, tb), tc);
    b = ta+tb+tc - a -c;

    ll ab = 0, ac = 0, bc = 0;
    for (size_t i = 0; i <= a; i++) {
      ll tmp = C(a, i) * C(b, i);
      tmp __;
      tmp *= F(i);
      tmp __;
      ab += tmp;
      ab __;
    }

    for (size_t i = 0; i <= a; i++) {
      ll tmp = C(a, i) * C(c, i);
      tmp __;
      tmp *= F(i);
      tmp __;
      ac += tmp;
      ac __;
    }

    for (size_t i = 0; i <= b; i++) {
      ll tmp = C(b, i) * C(c, i);
      tmp __;
      tmp *= F(i);
      tmp __;
      bc += tmp;
      bc __;
    }

    ll ans = ab * ac;
    ans __;
    ans *= bc;
    ans __;

    cout << ans << end;


    return 0;
}
