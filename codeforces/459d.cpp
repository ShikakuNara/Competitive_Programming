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
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'
#define fi first
#define se second
#define PI 3.14159265

const int MAX = 1000009;

ll tree[MAX];
ll n;
// add v to value at x
void Set(ll x, ll v) {

  while(x <=n) {
    tree[x] += v;
    x += (x & -x);
  }
}
// get cumulative sum up to and including x
ll get(ll x) {

  ll res = 0;

  while(x) {
    res += tree[x];
    x -= (x & -x);
  }

  return res;
}
// get largest value with cumulative sum less than or equal to x;
// for smallest, pass x-1 and add 1 to result
ll getind(ll x) {
  ll idx = 0, mask =n;

  while(mask && idx <n)
  {
    ll t = idx + mask;
    if(x >= tree[t]) {
      idx = t;
      x -= tree[t];
      }
    mask >>= 1;
  }

  return idx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL_TEST
      ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>n;
    ll a[MAX] = {0}, j = 1;

    std::map<ll, ll> mp;

    for (size_t i = 0; i < n; i++)
    {
      ll b; cin>>b;

      if(mp[b] == 0)
      {
        mp[b] = j; j++;
      }

      a[i] = mp[b];
    }

    ll cnt[MAX] = {0}, l[MAX], r[MAX];
    for (ll i = 0; i < n; i++) {
      cnt[a[i]]++;
      l[i] = cnt[a[i]];
    }
    fill(cnt);
    for (ll i = n-1; i >= 0; i--) {
      cnt[a[i]]++;
      r[i] = cnt[a[i]];
    }

    ll ans = 0;
    for (ll i = n-1; i >= 0; i--) {
      ans += get(l[i]-1);

      Set(r[i], 1);
    }
    cout<<ans<<end;

    return 0;
}
