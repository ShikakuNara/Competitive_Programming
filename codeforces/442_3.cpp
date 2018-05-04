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
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define rep(i, n)     for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(ll i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

const int MAX = 400009;
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

void prin(ll n, ll i)
{
  if( n == 1)
  {
    cout << 1+i<<" ";
    return;
  }
  if( n == 2)
  {
    cout << 2+i << " " << 1+i << " " << 2+i << " ";
    return;
  }
  if( n == 3)
  {
    cout << 2+i << " " << 1+i << " " << 3+i  << " " << 2+i << " ";
    return;
  }
  if( n == 4)
  {
    cout << 2+i << " " << 1+i << " " << 3+i << " " << 4+i << " "<<3+i << " "<<2+i << " ";
    return;
  }
  cout << 2+i << " " << 1+i << " " << n-1+i << " " << n+i << " ";
  prin(n-4, i+2);
  cout << 2+i<< " " << n-1+i << " ";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // #ifdef LOCAL_TEST
		//   ifstream cin("in.txt"); ofstream cout("out.txt");
    // #endif

    ll n; cin >> n;
    ll ans = 6*(n/4);
    if(n%4 == 1)
    {
      ans+=1;
    }
    if(n%4 == 2)
    {
      ans+=3;
    }
    if(n%4 == 3)
    {
      ans+=4;
    }

    cout << ans << end;

    prin(n, 0);

    return 0;
}
