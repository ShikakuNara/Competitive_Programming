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

ll npwtw (ll n)
{
  ll m = n;
  n--;
  n|= n >> 1;
  n|= n >> 2;
  n|= n >> 4;
  n|= n >> 8;
  n|= n >> 16;
  n|= n >> 32;
  n++;
  if( m == n)
    return n*2;
  return n;
}
int ispwtw (ll n)
{
  return !(n&(n-1));
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll c, d;cin>>c>>d;
    ll n, m; cin>>n>>m;
    ll k;cin>>k;

    if(k >= m*n)
    {
      cout << 0<<end;
    }
    else
    if(c >= n*d)
    {
      cout << (m*n-k)*d;
    }
    else
    {
      ll min = 10000000000;

      for (size_t i = 0; i <= m; i++) {
        ll sum = c*i;//(m*n-i*n)/n;


        if( k <= m*n-i*n)
        {
          sum += d*(m*n-i*n-k);
        }

        if(sum < min)
        {
          // cout << i << " " << sum << end;
          min = sum;
        }
      }

      cout << min <<end;
    }




    return 0;
}
