#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef pair<ll, pp > ppp;
typedef pair<ll, ppp > pd;
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

int comp(pd a, pd b)
{
  if(a.fi < b.fi)
    return 1;
  if(a.fi > b.fi)
    return 0;

  if(a.se.fi > b.se.fi)
    return 1;

  return 0;
}

ll n, d[110][2010] = {0}, taken[110] = {0}, nxt[110][2010] = {0}; pd item[110];

ll f(ll i, ll t)
{
  if(i == n || t > 2000)
    return 0;

  if(d[i][t] != -1)
    return d[i][t];

  if(item[i].first - item[i].se.se.fi <= t)
  {

    d[i][t] = f(i+1, t);
    return d[i][t];
  }

  ll a = item[i].se.fi + f(i+1, t+item[i].se.se.fi), b =f(i+1, t);
  d[i][t] = max(a, b);

  if( a == max(a, b))
    nxt[i][t] = 1;

  return d[i][t];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    c



    return 0;
}
