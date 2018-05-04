#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef pair<ll, pp > ppp;
typedef vector<pp > vpp;
typedef vector<ppp > vppp;
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

const int MAX = 100009;
const int MOD = 1e9+7;

// Functions
ll gcd(ll a, ll b){
    if (a == 0) return b;
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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n,m,k;cin>>n>>m>>k;
    ll a[MAX] = {0};


    for (size_t i = 0; i < n; i++) cin>>a[i];

    vppp op;
    for (size_t i = 0; i < m; i++) {
      ll a, b, c; cin>>a>>b>>c;a--, b--;

      op.pb(mp(a, mp(b, c)));
    }

    ll tmp[MAX] = {0}, oop[MAX] = {0};

    for (size_t i = 0; i < k; i++) {
      ll a, b; cin>>a>>b; a--, b--;
      oop[b]++;
      if( a > 0)
        oop[a-1]--;
    }

    for (ll i = m-2; i >= 0; i--) {
      oop[i] += oop[i+1];
    }

    for (size_t i = 0; i < m; i++) {
      ll b = op[i].se.fi, a = op[i].fi, c = op[i].se.se;
      tmp[b] += c*oop[i];

      if(a > 0)
        tmp[a-1] -= c*oop[i];

    }


    for (ll i = n-2; i>= 0; i--) {
      tmp[i] += tmp[i+1];
    }
    // for (size_t i = 0; i < n; i++) {
    //   cout << tmp[i] << " ";
    // }cout << end;
    for (size_t i = 0; i < n; i++) {
      a[i] += tmp[i];
      cout << a[i] << " ";
    }cout<<end;




    return 0;
}
