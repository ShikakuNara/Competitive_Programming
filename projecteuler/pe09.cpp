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

// Functions
ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
ll Abs(ll a){
  if( a > 0)
    return a;

  return -a;
}
double Abs(double a){
  if( a > 0)
    return a;

  return -a;
}

const ll MAX = 5000002;
const int MOD = 1e9+7;

ll ispal(ll i)
{
  ll dig[10] = {0};

  ll k = 0;
  while(i > 0)
  {
    dig[k] = i%10; k++;
    i /=10;
  }

  rep(i, k)
  {
    if(dig[i] != dig[k-1-i])
    {
      return 0;
    }
  }

  return 1;

}

ll memo[MAX] ={0};
ll len(ll i)
{
  if(i == 1)
  {
    return 1;
  }
  if(i < MAX && memo[i] != -1)
  {
    return memo[i];
  }

  if(i < MAX &&  i % 2 == 0)
  {
    memo[i] = 1 + len(i/2);
    return memo[i];
  }

  else if(i % 2 == 0)
    return 1 + len(i/2);


  if(i < MAX &&  i % 2 == 1)
  {
     memo[i] = 2 + len((3*i+1)/2);
     return memo[i];
  }

  return 2 + len((3*i+1)/2);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll M = 10, ind = -1;
    rep(i, MAX)
    {
      memo[i] = -1;
    }
    repA(i, 1, 1000000)
    {
      ll tmp = len(i);
      if(tmp > M) M = tmp, ind = i;
    }

    cout << ind<< ", "<<M;

    return 0;
}
