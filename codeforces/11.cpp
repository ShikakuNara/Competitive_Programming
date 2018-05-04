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
// #define end '\n'

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

const ll MAX = 4000000;
const int MOD = 1e9+7;

ll digsum(ll i)
{
  ll sum = 0;
  while(i >0)
  {
    sum += i%10;
    i /=10;
  }

  return sum;
}

ll memo[100][100] = {0};

ll a[100][100];


ll count(ll i, ll h)
{
  if(memo[h][i] != -1) return memo[h][i];

  if(h == 0)
  {
    if( i == 0)
      return a[h][i];
    else
      return -10000000000;
  }
  ll aa = -1, bb = -1;
  if(memo[h-1][i] != -1)
  {
    aa = memo[h-1][i];
  }
  else
  {
    aa = count(i, h-1);
  }

  if(i >0 && memo[h-1][i-1] != -1)
  {
    bb = memo[h-1][i-1];
  }
  else if(i>0)
  {
    bb = count(i-1, h-1);
  }
  else
  {
    bb = -10000000000000;
  }

  return memo[h][i] = max(aa, bb) + a[h][i];
}

bool prime[MAX];
void SieveOfEratosthenes(ll n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.


    for (ll p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (ll i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


    SieveOfEratosthenes(MAX-1);

    memset(prime, true, sizeof(prime));

    string s = "0123456789";
    sort(s.begin(), s.end());
    ll i = 1;
    do {
        stringstream geek(s);

        // The object has the value 12345 and stream
        // it to the integer x
        ll x = 0;
        geek >> x;

        if(x < MAX && prime[x])
        {
          cout << x << '\n';
        }

    } while(next_permutation(s.begin(), s.end()));


    return 0;
}
