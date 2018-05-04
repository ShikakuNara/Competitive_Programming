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

const int MAX = 100009;
const int MOD = 1e9+7;

ll ft1[MAX+1] = {0}, ft2[MAX+1] = {0}, n = 5;

void update1(ll x, ll v)
{
  x++;    //indexing change
  for (; x <= n; x += (ll)(x&(-x))) ft1[x] += v;
}
void update2(ll x, ll v)
{
  x++;    //indexing change
  for (; x <= n; x += (ll)(x&(-x))) ft2[x] += v;
}
void update(ll a, ll b, ll v)
{
  update1(b+1, -v);
  update1(a, v);
  update2(b+1, -v*b);
  update2(a, v*(a-1));
}
ll basicsum1(ll x)
{
  x++;    //indexing change
  ll sum = 0;
  for ( ; x; x -= (ll)(x&(-x))) {
    sum += ft1[x];
  }
  return sum;
}
ll basicsum2(ll x)
{
  x++;    //indexing change
  ll sum = 0;
  for ( ; x; x -= (ll)(x&(-x))) {
    sum += ft2[x];
  }
  return sum;
}
ll csum(ll x)
{
  return basicsum1(x) * x - basicsum2(x);
}
ll get(ll a, ll b)
{
  return csum(b) - csum(a-1);
}
ll get(ll a)
{
  return csum(a) - csum(a-1);
}
void build(ll arr[], ll n)
{
  for (size_t i = 1; i <= n; i++) update(i-1 ,i-1, arr[i-1]);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll a[] = {1,2, 3, 4, 5};

    build(a, n);

    for (size_t i = 0; i < n; i++) {
      cout << get(i) << " ";
    }cout<<end;

    update(2, 4, 5);
    for (size_t i = 0; i < n; i++) {
      cout << get(i) << " ";
    }cout<<end;

    cout << get(0, 4) << " ";




    return 0;
}
