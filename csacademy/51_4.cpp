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
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'


const ll MAX = 1000009;
const ll MOD = 1e9 + 7;
const ll factRange = MAX;
#define _  %  MOD
#define __ %= MOD


// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

ll abs(ll a, ll b)
{
  if( a > b)
    return a-b;

  return b-a;
}

ll fact[factRange];

ll extGcd(ll a, ll b, ll& x, ll& y) {
	if (!a) {
		x = 0;
		y = 1;
		return b;
	}

	ll x1, y1;
	ll d = extGcd((b+5*a) % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

inline ll addMod(ll a, ll b, ll m = MOD) {
	return ((ll)a + b + 5*m) % m;
}
inline ll mulMod(ll a, ll b, ll m = MOD) {
	return ((ll)a * b + 5*m) % m;
}
inline ll divMod(ll a, ll b, ll m = MOD) {
	ll x, y;
	ll g = extGcd(b, m, x, y);
	if (g != 1) {
		cerr << "Bad gcd!" << endl;
		for (;;);
	}
	x = (x % m + m + 5*m) % m;
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
inline ll P(ll n, ll k) {
	return divMod(F(n),F(k));
}

vll adj[MAX];
ll n, k;
ll vis[MAX] = {0};
ll ans = 1, flag = 0;



void dfs(ll i)
{

    vis[i] = 1;
    if(flag == 1)
    {
      return;
    }

    if(i == 0)
    {
      ans *= k;
      ans = (ans+ 5*MOD) _;
      // cout << i << ", " << ans << end;
    }
    else if(i == 1)
    {
      if(adj[i].size() == 0)
      {
      }
      else
      {
        if(k < (ll)adj[i].size() )
        {
          flag = 1;
          return;
        }
        // ans *= P(k-1, k-adj[i].size());

        for (ll j = k-1; j > k-adj[i].size(); j--) {
          ans*= j;
          ans = (ans+ 5*MOD) _;
          // cout << i << ", " << ans << end;
        }
      }
    }
    else
    {
      if(adj[i].size() == 0)
      {

      }
      else
      {
        if(k-1 < (ll)adj[i].size())
        {
          flag = 1;
          return;
        }
        // ans *= P(k-2, k-1-adj[i].size());

        for (ll j = k-2; j > k-1-adj[i].size(); j--) {
          ans *= j;
          ans = (ans+ 5*MOD) _;
          // cout << i << ", " << ans << end;
        }

        // ans = (ans+ 5*MOD) _;
      }
    }

    for (ll j = 0; j < adj[i].size(); j++) {
      if(vis[adj[i][j]] == 0)
      {
          dfs(adj[i][j]);
      }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    fill(vis);
    // precalcFactorials();

    cin >> n >> k;

    adj[0].pb(1);
    adj[1].pb(0);
    for (ll i = 0; i < n-1; i++) {
      ll a, b;
      cin >> a >> b;

      adj[a].pb(b);
      adj[b].pb(a);
    }

    dfs(0);

    if(flag == 1)
    {
      cout << 0 << end;
    }
    else
    {
      cout << ans << end;
    }

    return 0;
}
